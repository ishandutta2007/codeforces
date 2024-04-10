#include<bits/stdc++.h>
#include<assert.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define rank Rank
using namespace std;
typedef long long LL;
int s[100005][15][15][4];
void add(int index,int op,int x){
	for(int i=1;i<=10;i++)
	{
		for(int j=index;j<=100000;j+= j&-j)
			s[j][i][index%i][op]+=x;
	}
}
int query(int index,int op,int div,int mod){
	int res=0;
	for(int i=index;i>0;i-=i&-i){
		res+=s[i][div][mod][op];
	}
	return res;
}
int transform(char c){
	if(c=='A')
	return 0;
	if(c=='T')
	return 1;
	if(c=='C')
	return 2;
	if(c=='G')
	return 3;
}
int main()
{
	string s;
	cin>> s;
	for(int i=0;i<s.size();i++){
		int op;
		op=transform(s[i]);
		add(i+1,op,1);
	} 
	int q;
	scanf("%d",&q);
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x;
			char c[2];
			scanf("%d %s",&x,c);
			int org=transform(s[x-1]);
			int now=transform(c[0]);
			s[x-1]=c[0];
			add(x,org,-1);
			add(x,now,1);
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			char c[15];
			scanf("%s",c);
			int len=strlen(c);
			int res=0;
			for(int i=0;c[i]!=0;i++){
				res+=query(r,transform(c[i]),len,(i+l%len)%len)-query(l-1,transform(c[i]),len,(i+l%len)%len);
			//	printf("%d\n",res);
			}
			printf("%d\n",res);
		}
	}
}