#include<bits/stdc++.h>
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
#define N 800005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
using namespace std;
typedef long long LL;
int main()
{
	char hi[30];
	scanf("%s",hi);
	set<char> s;
	for(int i=0;hi[i]!=0;i++)
	s.insert(hi[i]);
	char c[100005];
	scanf("%s",c);
	int q;
	scanf("%d",&q);
	char ask[100005];
	while(q--){
		scanf("%s",ask);
		int ok=1,end=-1;
		for(int i=0;c[i]!=0||ask[i]!=0;i++)
		{
			if(c[i]=='*')
			{
				end=i;
				break;
			}
			if(ask[i]!=c[i]&&(c[i]!='?'||s.find(ask[i])==s.end())){
				ok=0;
				break;
			}
		} 
		if(end!=-1&&ok){
			int i,j;
			for(i=strlen(ask)-1,j=strlen(c)-1;j!=end;i--,j--){
				if(c[j]!=ask[i]&&(c[j]!='?'||s.find(ask[i])==s.end()))
				{
					ok=0;
					break;
				}
			}
			if(i<end-1)
			ok=0;
			if(ok){
				for(int k=end;k<=i;k++){
					if(s.find(ask[k])!=s.end()){
						ok=0;
						break;
					}
				}
			} 
		}
		printf("%s\n",ok?"YES":"NO");
	}
}