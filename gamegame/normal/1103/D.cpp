#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=1e6+1,PC=11,Q=2048;
int n;
ll k,g;
ll a[N],e[N];
ll deg[N][PC];
bool die[N];
ll gcd(ll x,ll y){
	while(y!=0){ x%=y;x^=y^=x^=y;}
	return x;
}
int pc=0;
ll p[PC];
void factor(){
	ll h=g;
	for(ll i=2; i*i<=h ;i++){
		if(h%i==0){
			while(h%i==0) h/=i;
			p[pc++]=i;
		}
	}
	if(h!=1) p[pc++]=h;
}
pair<pair<ll,ll>,int>ord[N];
ll save[Q];
int lg[Q];
int got[Q];
vector<int>bois[N];
ll dp[2][PC+1][Q];
void in(int& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
void in(ll& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
int main(){
	ios::sync_with_stdio(false);
	in(n);in(k);
	for(int i=1; i<=n ;i++){
		in(a[i]);g=gcd(a[i],g);
	}
	for(int i=1; i<=n ;i++) in(e[i]);
	factor();
	if(g==1){
		cout << "0\n";
		return 0;
	}
	for(int i=1; i<=n ;i++){
		ll cur=a[i];
		for(int j=0; j<pc ;j++){
			deg[i][j]=1;
			while(cur%p[j]==0) cur/=p[j],deg[i][j]*=p[j];
		}
		ord[i]={{a[i]/cur,e[i]},i};
	}
	sort(ord+1,ord+n+1);
	int cnt=0;
	for(int i=1; i<=n ;i++){
		if(ord[i].fi.fi!=ord[i-1].fi.fi) cnt=0;
		++cnt;if(cnt>pc) die[ord[i].se]=true;
	}
	for(int i=1; i<=n ;i++) ord[i]={{e[i],0},i};
	sort(ord+1,ord+n+1);
	for(int i=0; i<pc ;i++) lg[(1<<i)]=i;
	for(int i=1; i<=n ;i++){
		int cur=ord[i].se;
		if(die[cur]) continue;
		save[0]=1;
		for(int j=1; j<(1<<pc) ;j++){
			save[j]=save[j^(j&-j)]*deg[cur][lg[j&-j]];
			if(save[j]<=k && got[j]<=pc-__builtin_popcount(j)){
				++got[j];bois[cur].push_back(j);
			}
		}
	}
	for(int i=0; i<=pc ;i++)
		for(int j=0; j<(1<<pc) ;j++)
			dp[1][i][j]=1e17;
	dp[1][0][0]=0;
	for(int i=1; i<=n ;i++){
	    if(bois[i].empty()) continue;
		for(int r=0; r<=pc ;r++)
			for(int j=0; j<(1<<pc) ;j++)
				dp[0][r][j]=dp[1][r][j];
		for(auto mk:bois[i]){
			int flip=mk^((1<<pc)-1);
			for(int j=pc-1; j>=0 ;j--){
				for(int r=flip; true ;r=(r-1)&flip){
					dp[1][j+1][r|mk]=min(dp[1][j+1][r|mk],dp[0][j][r]+e[i]);
					if(r==0) break;
				}
			}
		}
	}
	ll ans=1e18;
	for(int i=1; i<=pc ;i++){
		ans=min(ans,i*dp[1][i][(1<<pc)-1]);
	}
	if(ans>=1e17) cout << "-1\n";
	else cout << ans << endl;
}