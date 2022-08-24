#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
typedef pair<ll,ll> pll;
const int N=2e6+1;
int n;
int f[N];
pair<int,int>g[N];
int h[N];
bool check(int x){
	if(x==1) return true;
	int tmp=n/(x-1)+1;
	int duh=n%(x-1);
	int cnt=0;
	for(int i=1; i<=n ;i++){
		if(f[i]>tmp) return false;
		cnt+=(f[i]==tmp);
	}
	if(cnt>duh) return false;
	else return true;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) f[i]=0;
	int ans=n;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		f[x]++;
	}
	for(int i=1; i<=n ;i++) g[i]={f[i],i};
	sort(g+1,g+n+1);
	reverse(g+1,g+n+1);
	int l=1,r=n;
	while(l!=r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout << l-2 << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--)  solve();
}