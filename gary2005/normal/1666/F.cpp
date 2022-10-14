#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=5e3+233;
const int MOD=998244353;
int n,a[MAXN],b[MAXN],dp[MAXN][MAXN],sum[MAXN],ifact[MAXN];
void add(int &A,int B){
	A+=B;
	if(A>=MOD) A-=MOD;
}
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int iv(int A){
	return quick(A,MOD-2);
}
void solve(){
	cin>>n;
	rb(i,1,n) cin>>a[i];
	if(n==2){
		cout<<(a[1]<a[2])<<endl;
		return ;
	}
	int pt=0;
	rb(i,1,n){
	while(a[pt+1]<a[i]) pt++;
	b[i]=pt;
	}
	rb(i,0,n) rb(j,0,n) dp[i][j]=0;
	rb(i,1,n) dp[i][1]=b[i]*(b[i]-1);
	memset(sum,0,sizeof(sum));
	rb(i,1,n){
		rb(j,b[i-1]+1,b[i]){
			rb(k,0,n) add(sum[k],dp[j][k]);
		}
		rb(k,1,n/2-1){
			if(k!=n/2-1)
			add(dp[i][k+1],1ll*sum[k]*max(0,b[i]-k-k-1)%MOD);
			else
			add(dp[i][k+1],sum[k]);
		}
//		rb(j,1,n/2) if(dp[i][j]) cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	}
	int ans=dp[n][n/2];
//	cout<<ans<<endl;
	map<int,int> cnt;
	rb(i,1,n) cnt[a[i]]++;
	for(auto it:cnt) ans=1ll*ans*ifact[it.SEC]%MOD;
	cout<<ans<<endl;
}
int main(){
	ifact[0]=1;
	rb(i,1,5000) ifact[i]=1ll*ifact[i-1]*i%MOD;
//	cout<<ifact[3]<<endl;
	rb(i,0,5000) ifact[i]=iv(ifact[i]);
//	cout<<6ll*iv(6)%MOD<<endl;
	int T;
	cin>>T;
	while(T--) solve();
    return 0;
}

/*
1
6
1 1 1 2 3 4

*/