#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
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
int f[100005];
int Find(int a){
	if(f[a]==a)
	return a;
	return f[a]=Find(f[a]);
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[100005];
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	f[i]=i;
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy){
			if(a[fx]>a[fy])
			f[fx]=fy;
			else
			f[fy]=fx;	
		}
	} 
	LL ans=0;
	for(int i=1;i<=n;i++){
		if(Find(i)==i)
		ans+=a[i];
	}
	printf("%I64d\n",ans);
}