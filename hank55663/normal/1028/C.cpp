#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	pair<pii,pii> p[140000];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		p[i]=mp(mp(x1,y1),mp(x2,y2));
	}
	vector<int> x;
	vector<int> y;
	for(int i=0;i<n;i++){
		x.pb(p[i].x.x);
		x.pb(p[i].y.x);
		y.pb(p[i].x.y);
		y.pb(p[i].y.y);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for(int i=max((int)x.size()/2-5,0);i<min((int)x.size()/2+6,(int)x.size());i++)
		for(int j=max((int)y.size()/2-5,0);j<min((int)y.size()/2+6,(int)y.size());j++){
		//	printf("%d %d\n",i,j);
			int xx=x[i],yy=y[j];
		//	printf("%d %d\n",xx,yy);
			int cnt=0;
			for(int k=0;k<n;k++){
				if(xx<=p[k].y.x&&xx>=p[k].x.x&&yy<=p[k].y.y&&yy>=p[k].x.y){
					cnt++;
			//		printf("%d %d\n",xx,yy);
			//		return 0;
				}
			}
			if(cnt>=n-1){
				printf("%d %d\n",xx,yy);
				return 0;
			}
		}
	assert(0);
}