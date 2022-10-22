/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,m;
int b[101][101];
int ans[101][101];
void solve(){
	unordered_map<int,int> app;
	vector<pair<int,mp> > v;
	scanf("%d%d",&n,&m);
	rb(i,1,n) rb(j,1,m) scanf("%d",&b[i][j]),v.PB(II(b[i][j],II(i,j)));
	int have=0;
	sort(ALL(v));
	rb(i,1,m) app[v[i-1].SEC.FIR*1000+v[i-1].SEC.SEC]=1;
	rb(i,1,n){
		vector<int> mini;
		vector<int> oth;
		rb(j,1,m) {
			if(app[i*1000+j]) mini.PB(b[i][j]);	
			else oth.PB(b[i][j]);
		}
		int l,r;
		l=have,r=have;
		for(auto it:mini){
			ans[i][++have]=it;
		}
		r=have;
		rb(j,1,l) ans[i][j]=oth.back(),oth.POB();
		rb(j,r+1,m) ans[i][j]=oth.back(),oth.POB();
	}
	rb(i,1,n){
		rb(j,1,m) printf("%d ",ans[i][j]);puts("");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}