#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
char c[N];
void solve(){
	string s;cin >> s;
	n=s.size();
	int b=0;
	int a=0;
	for(auto c:s){
		if(c=='A') a++;
		else if(a!=0) a--;
		else b++;
	}
	cout << a+b%2 << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}