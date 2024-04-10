#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
using namespace std;
typedef long long LL;
bool cmp(const pii &a,const pii &b){
	return a.y<b.y;
}
int main(){
	
	int n;
	scanf("%d",&n);
	int a[200005];
	a[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pii base[33];
	base[31].x=1e9;
	base[31].y=1e9;
	for(int i=0;i<31;i++){
		base[i].x=0;
		base[i].y=i;
	} 
	LL res=0;
	map<int,int> m;
	for(int i=1;i<=n;i++){
		m[a[i]]=i;
		int k=a[i];
		for(int j=0;j<31;j++){
			if(k&1)base[j].x=i;
			k>>=1;
		} 
		sort(base,base+31);
		int now=2147483647;
		int last=0;
		for(int j=0;j<31;j++){
			if(j==0||base[j-1].x!=base[j].x){

					res+=base[j].x-max(m[now],last);
			//	printf("now :%d %d %d %d %d\n",now,base[j].x,base[j].y,m[now],last);
			}
			now^=(1<<base[j].y);
			last=base[j].x;
		}
		sort(base,base+31,cmp);
//	printf("%d ",res);
	}
	printf("%I64d\n",res);

	return 0;
}