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
LL x,a[200000+20];
int main(){
	int n;
	LL k;
	scanf("%d%lld%lld",&n,&k,&x);
	rb(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	vector<LL> Tmp;
	int ans=n;
	rb(i,1,n-1) Tmp.PB(a[i+1]-a[i]);
	sort(ALL(Tmp));
	for(auto it:Tmp){
		if((it-1)/x<=k){
			k-=max(0ll,(it-1)/x);
			ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}