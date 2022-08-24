#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
int p[N],q[N],s[N];
bool vis[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p[i];s[i]=p[i];
	}
	while(true){
		for(int i=1; i<=n ;i++) vis[i]=false;
		int x=1;
		while(!vis[x]){
			vis[x]=true;x=s[x];
		}
		bool done=true;
		for(int i=1; i<=n ;i++){
			if(!vis[i]){
				for(int j=1; j<=n ;j++){
					if(s[j]==i-1) s[j]=i;
					else if(s[j]==i) s[j]=i-1;
				}
				done=false;
				break;
			}
		}
		if(done) break;
	}
	q[n]=1;
	for(int i=n-1; i>=1 ;i--){
		q[i]=s[q[i+1]];
	}
	for(int i=1; i<=n ;i++) cout << q[i] << ' ';
	cout << '\n';
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}