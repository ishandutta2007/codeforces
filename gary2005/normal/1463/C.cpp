/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
#define int LL
const int INF=1e18;
typedef pair<int,int> mp;
/*}
*/
int n;
int t[100000+20],x[100000+20];
vector<mp> point;
void solve(){
	scanf("%lld",&n);
	rb(i,1,n) scanf("%lld%lld",&t[i],&x[i]);
	t[n+1]=INF;
	int las=0;
	point.clear();
	point.PB(II(0,0));
	for(int i=1;i<=n;){
		point.PB(II(t[i],las));
		point.PB(II(t[i]+abs(x[i]-las),x[i]));
		int j=i+1;
		for(;j<=n&&t[j]-t[i]<abs(x[i]-las);++j){
			point.PB(II(t[j],las+(t[j]-t[i])*(x[i]-las)/abs(x[i]-las)));
		}
		las=x[i];
		i=j;
	}
	point.PB(II(INF,las));
	sort(ALL(point));
	int t_=2;
	int rest=0;
	rb(i,1,n){
		bool ok=false;
		while(t_<point.size()&&point[t_].FIR<=t[i+1]){
			ok|=(x[i]<=max(point[t_].SEC,point[t_-1].SEC)&&x[i]>=min(point[t_].SEC,point[t_-1].SEC)); 
			t_++;
		}
		rest+=ok;
	}
	printf("%lld\n",rest);
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}