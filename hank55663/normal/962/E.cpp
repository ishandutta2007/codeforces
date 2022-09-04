#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int main(){
	int n;
	scanf("%d",&n);
	pair<int,char> p[200005];
	for(int i=0;i<n;i++){
		scanf("%d %c",&p[i].x,&p[i].y);
	}
	sort(p,p+n);
	int minred=1e9+1,maxred=1e9+1;
	int mingreen=1e9+1,maxgreen=1e9+1;
	for(int i=0;i<n;i++){
		if(p[i].y=='R')
		{
			maxred=p[i].x;
			minred=min(minred,p[i].x);
		}
		else if(p[i].y=='B'){
			maxgreen=p[i].x;
			mingreen=min(mingreen,p[i].x);
		}
		else{
			maxred=p[i].x;
			minred=min(minred,p[i].x);
			maxgreen=p[i].x;
			mingreen=min(mingreen,p[i].x);
		}
	}
	//printf("%d %d %d %d\n",minred,maxred,mingreen,maxgreen);
	LL ans=(LL)maxred-minred+maxgreen-mingreen;
	int lastp=-1;
	for(int i=0;i<n;i++){
		if(p[i].y=='P'){
			if(lastp!=-1){
				int lastr=p[lastp].x;
				int lastg=p[lastp].x;
				int maxr=0,maxg=0;
				for(int j=lastp+1;j<i;j++){
					if(p[j].y=='R'){
						maxr=max(p[j].x-lastr,maxr);
						lastr=p[j].x;
					}
					else{
						maxg=max(p[j].x-lastg,maxg);
						lastg=p[j].x;
					}
				}
				maxr=max(p[i].x-lastr,maxr);
				maxg=max(p[i].x-lastg,maxg);
				ans-=max(0,maxr+maxg-(p[i].x-p[lastp].x));
			}
			lastp=i;
		}
	}
	printf("%lld\n",ans);
}