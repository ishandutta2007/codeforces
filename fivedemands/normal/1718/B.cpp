#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll f[N];
int sz=0;
pair<ll,int>a[N];
int use[N];
void solve(){
	cin >> n;
	ll s=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		s+=a[i].fi;
		a[i].se=i;
	}
	int ptr=0;
	ll t=0;
	while(t<s){
		t+=f[++ptr];
	}
	if(t!=s){
		cout << "NO\n";
		return;
	}
	//cout << t << ' ' << s << ' ' << ptr << endl;
	sort(a+1,a+n+1);
	for(int i=ptr; i>=1 ;i--){
		if(a[n].fi<f[i]){
			cout << "NO\n";
			return;
		}
		a[n].fi-=f[i];
		use[i]=a[n].se;
		if(i!=ptr && use[i]==use[i+1]){
			cout << "NO\n";
			return;
		}
		int cur=n;
		while(cur>1 && a[cur-1].fi>=a[cur].fi){
			swap(a[cur-1],a[cur]);
			cur--;
		}
		
	}
	cout << "YES\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int sz=2;
	f[1]=f[2]=1;
	while(f[sz]<1e11){
		f[sz+1]=f[sz]+f[sz-1];
		sz++;
	}
	int t;cin >> t;while(t--) solve();
}