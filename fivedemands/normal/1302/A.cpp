#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int n,k;
ll dp[2121][2121];
ll dp2[2121];
bool used[2021];
vector<int>v;
int sum=0,cnt=0;
int sum2=0;
int ans=0;
int sz=0;
vector<int>g[500001];
void magic(int x,int y){
	if(sum2>n) return;
	if(y==0){
		if(v.empty()) return;
		g[++sz]=v;
		return;
	}
	if(x<y){
		magic(x,x);return;
	}
	magic(x,y-1);
	v.push_back(y);
	sum2+=y*sum+(cnt+1)*y*(y+1)/2;
	sum+=y*cnt+y;
	cnt++;
	magic(x-y,y);
	v.pop_back();
	cnt--;
	sum-=y*cnt+y;
	sum2-=y*sum+(cnt+1)*y*(y+1)/2;
}
ll k1(){
	dp2[0]=1;
	for(int i=1; i<=n ;i++){
		for(int j=i; j<=n ;j++){
			dp2[j]=(dp2[j]+dp2[j-i])%mod;
		}
	}
	ll ans=0;
	for(int i=1; i<=n ;i++) ans=(ans+dp2[i])%mod;
	return ans;
}
ll k2(){
	dp[0][0]=1;
	for(int i=n; i>=1 ;i--){
		for(int j=0; j<n ;j++){
			for(int k=0; k<n/i ;k++){
				if(j+i*(k+1)>n) continue;
				dp[j+i*(k+1)][k+1]+=dp[j][k];
				dp[j+i*(k+1)][k+1]%=mod;
			}
		}
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++){
			ans+=dp[i][j];
			ans%=mod;
		}
	}
	return ans;
}
int f[71];
map<ll,int>mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	if(k>=15){
		cout << "1\n";
		return 0;
	}
	if(k==1) return cout << k1() << endl,0;
	if(k==2) return cout << k2() << endl,0;
	magic(66,66);
	for(int i=1; i<=sz ;i++){
		for(int z=1; z<=k-3 ;z++){
			int mx=0;
			for(auto c:g[i]){
				f[c]++;
				mx=max(mx,c);
			}
			g[i].clear();
			for(int j=1; j<=mx ;j++){
				if(f[j]) g[i].push_back(f[j]);
				f[j]=0;
			}	
		}
		sort(g[i].begin(),g[i].end());
		ll h=0;
		for(auto c:g[i]){
			h=h*2039+c;
			h%=mod;
		}
		ans+=!mp[h];
		mp[h]=true;
	}
	cout << ans << endl;
}