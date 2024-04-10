#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define sc second
#define pb push_back
#define mp make_pair
const ll mod = 1000000007;
typedef pair<int,int> P;

int main(){
	ll n; cin >> n;
	if(n == 1){ puts("1"); return 0; }
	vector<ll>vi;
	for(ll i=2;i*i<=n;i++){
		if(n%i != 0) continue;
		while(n%i == 0) n/=i;
		vi.pb(i);
	}
	if(n != 1) vi.pb(n);
	
	if(vi.size() == 1){
		cout << vi[0] << endl;
	}
	else{
		cout << 1 << endl;
	}
}