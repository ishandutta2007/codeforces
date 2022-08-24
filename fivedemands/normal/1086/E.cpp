#include<iostream>
using namespace std;
typedef long long ll;
int n;
const ll mod=998244353;
ll god=0;
int a[2001][2001];
ll f[2001],inf[2001];
ll bit[2001],bit2[2001];
int u[2001],v[2001];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2==1) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void upd(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
int qry(int id){
	int res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}
void upd2(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit2[i]+=v;
}
int qry2(int id){
	int res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit2[i];
	return res;
}
ll ans=0;
ll big[2001];
ll dp[2001][2001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			cin >> a[i][j];
		}
	}
	f[0]=1;
	for(int i=1; i<=n ;i++){
		f[i]=f[i-1]*i%mod;
	}
	dp[0][0]=1;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<=i ;j++){
			if(j==0) dp[i][j]=f[i];
			else if(j==1) dp[i][j]=dp[i-1][j-1]*(i-j)%mod;
			else dp[i][j]=(dp[i-1][j-1]*(i-j)+dp[i-1][j-2]*(j-1))%mod;
		}
	}
	for(int i=1; i<=n ;i++){
		upd(a[1][i],1);
		int num=a[1][i]-qry(a[1][i]);
		big[1]=(big[1]+num*f[n-i])%mod;
	}
	for(int i=2; i<=n ;i++){
		int rep=n;
		for(int j=1; j<=n ;j++) bit[j]=bit2[j]=0,u[j]=1,v[j]=1;
		for(int j=1; j<=n ;j++) upd2(j,1);
		for(int j=1; j<=n ;j++){
			if(u[a[i-1][j]]){//rep>=1
				upd2(a[i-1][j],-1);
				int num1=qry(a[i][j]-1);
				int num2=qry2(a[i][j]-1);
				big[i]=(big[i]+num1*dp[n-j][rep-1])%mod;
				if(rep>1) big[i]=(big[i]+num2*dp[n-j][rep-2])%mod;
				if(v[a[i][j]]) rep-=2;
				else rep--;
				upd(a[i-1][j],1);
			}
			else{
				int num1=qry(a[i][j]-1);
				int num2=qry2(a[i][j]-1);
				big[i]=(big[i]+num1*dp[n-j][rep])%mod;
				if(rep>0) big[i]=(big[i]+num2*dp[n-j][rep-1])%mod;
				if(v[a[i][j]]) rep--;
			}
			if(v[a[i][j]]) upd2(a[i][j],-1);
			else upd(a[i][j],-1);
			u[a[i][j]]=0;
			v[a[i-1][j]]=0;
		}
	}
	for(int i=1; i<=n ;i++) {
		ans=(ans*dp[n][n]+big[i])%mod;
	}
	cout << ans << endl;
}