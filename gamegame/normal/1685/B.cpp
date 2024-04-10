#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
char s[N];
void solve(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	n=a+b+2*c+2*d;
	for(int i=1; i<=n ;i++){
		cin >> s[i];
	}
	int prv=0;
	vector<int>chp,dhp;
	for(int i=1; i<=n ;i++){
		if(i==n || s[i]==s[i+1]){
			int l=prv+1,r=i;
			if((r-l+1)%2==0){
				if(s[i]=='B'){
					chp.push_back((r-l+1)/2);
					c-=(r-l+1)/2;
				}
				else{
					dhp.push_back((r-l+1)/2);
					d-=(r-l+1)/2;
				}
			}
			else{
				if(s[i]=='A') a--;
				else b--;
			}
			prv=i;
			
		}
	}
	//cout << c << ' ' << d << endl;
	if(a!=b || a<0){
		cout << "NO\n";return;
	}
	sort(chp.begin(),chp.end());//reverse(chp.begin(),chp.end());
	sort(dhp.begin(),dhp.end());//reverse(dhp.begin(),dhp.end());
	while(c<0){
		if(a==0){
			cout << "NO\n";return;
		}
		a--;c+=chp.back();chp.pop_back();
	}
	while(d<0){
		if(a==0){
			cout << "NO\n";return;
		}
		a--;d+=dhp.back();dhp.pop_back();
	}
	cout << "YES\n";
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}