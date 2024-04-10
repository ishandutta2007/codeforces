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
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	pair<LL,char> p[300005];
	p[0]=mp(-1e9,'G');
	p[n+1]=mp(2e9,'G');
	int ok=0;
	for(int i=1;i<=n;i++){
		scanf("%I64d %c",&p[i].x,&p[i].y);
		if(p[i].y=='G')
		ok=1;
	}
	sort(p,p+n+2);
	if(!ok){
		int lastr=1e9;
		int lastb=1e9;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(p[i].y=='R'){
				ans+=max(0ll,p[i].x-lastr);
				lastr=p[i].x;
			}
			if(p[i].y=='B'){
				ans+=max(0ll,p[i].x-lastb);
				lastb=p[i].x;
			}
		}
		printf("%d\n",ans);
		return 0;	
	}
	LL ans=0;
	int last=0;
	for(int i=1;i<=n+1;i++){
		if(p[i].y=='G'){
			LL res=0;
			LL maxr=0,maxb=0;
			int lastr=p[last].x,lastb=p[last].x;
			for(int k=last+1;k<i;k++){
				if(p[k].y=='R'){
					maxr=max(maxr,p[k].x-lastr);
					lastr=p[k].x;
				}
				if(p[k].y=='B'){
					maxb=max(maxb,p[k].x-lastb);
					lastb=p[k].x;
				}
			}
			maxr=max(maxr,p[i].x-lastr);
			maxb=max(maxb,p[i].x-lastb);
			ans+=min((p[i].x-p[last].x)*2,(p[i].x-p[last].x)*3-maxr-maxb);
		//	printf("%I64d %I64d %I64d %I64d\n",ans,min((p[i].x-p[last].x)*2,(p[i].x-p[last].x)*3-maxr-maxb),maxr,maxb);
			last=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i].y=='G'){
			ans-=p[i].x-p[0].x;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(p[i].y=='G'){
			ans-=p[n+1].x-p[i].x;
			break;
		}
	}
	printf("%I64d\n",ans);
}