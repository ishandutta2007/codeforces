#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
char s[N];
int p[N];
void solve(){
	cin >> n;
	int mn=2*n+1,mx=-1;
	for(int i=1; i<=2*n ;i++){
		cin >> s[i];
		p[i]=p[i-1];
		if(s[i]=='(') p[i]++;
		else p[i]--;
		if(p[i]<0){
			mn=min(mn,i);
			mx=max(mx,i);
		}
	}
	if(mx==-1){
		cout << "0\n";return;
	}
	int lh=0,rh=0,ch=0;
	for(int i=0; i<=mn ;i++) lh=max(lh,p[i]);
	for(int i=mx; i<=2*n ;i++) rh=max(rh,p[i]);
	for(int i=mn; i<=mx ;i++) ch=max(ch,p[i]);
	int lk,rk;
	for(int i=0; i<=mn ;i++) if(p[i]==lh) lk=i;
	for(int i=mx; i<=2*n ;i++) if(p[i]==rh) rk=i;
	if(ch<=lh+rh){
		cout << "1\n";
		cout << lk+1 << ' ' << rk << '\n';
		return;
	}
	for(int i=1; ;i++){
		if(p[i]==ch){
			cout << "2\n";
			cout << 1 << ' ' << i << '\n';
			cout << (i+1) << ' ' << 2*n << '\n';
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}