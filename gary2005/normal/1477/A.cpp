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
int t;
LL a[200000+20];
LL gcd(LL A,LL B){
	if(B==0) return A;
	return gcd(B,A%B);
}
int main(){
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		LL k;
		cin>>k;
		bool ok=false;
		rb(i,1,n) scanf("%lld",&a[i]);
		sort(a+1,a+1+n);
		LL tmp=a[2]-a[1];
		rb(i,2,n){
			tmp=gcd(tmp,a[i]-a[i-1]);
		}
		rb(i,1,n){
			if(abs(k-a[i])%tmp==0) ok=1;
		}
		cout<<(ok? "YES":"NO")<<endl;
	}	
	return 0;
}