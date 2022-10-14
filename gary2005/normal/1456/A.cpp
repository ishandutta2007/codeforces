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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
string s;
int val[100000+20];
void solve(){
	int n,p,k;
	cin>>n>>p>>k>>s;
	rep(i,k) val[i]=0;
	string ns;
	rb(i,p-1,n-1)
		ns.PB(s[i]);
	int x,y;
	cin>>x>>y;
	n-=p-1;
	int rest=INF;
	rl(i,n-1,0){
		val[i%k]+=(ns[i]=='0');
		check_min(rest,i*y+val[i%k]*x);
	}
	cout<<rest<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}