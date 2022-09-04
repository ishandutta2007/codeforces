#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
vector<pdd> v;
vector<double> tot;
double cal(double x){
	auto it = lower_bound(v.begin(),v.end(),mp(x,0.0));
	double ret=0;
	if(it!=v.begin()){
		//printf("%d\n",it-v.begin());
		it--;
		ret+=tot[it-v.begin()];
		ret+=min(it->y,x)-it->x;
	//	printf("%lf %lf %lf %lf\n",it->y,x,it->x,ret);
	}
	return ret;
}
int main(){
	int s,a,b;
	scanf("%d %d %d",&s,&a,&b);
	int n;
	scanf("%d",&n);
	double last=0;
	tot.pb(0);
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d %d",&l,&r);
		v.pb(mp(l,r));
		last+=r-l;
		tot.pb(last);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d %d",&x,&y);
		double l=a+(double)(x-a)/(y-s)*(-s),r=b+(double)(x-b)/(y-s)*(-s);
	//	printf("%lf %lf\n",l,r);
		double tot=cal(r)-cal(l);
	//	printf("%lf %lf\n",cal(r),cal(l));
		printf("%.12lf\n",tot/(r-l)*(b-a));
	}
}