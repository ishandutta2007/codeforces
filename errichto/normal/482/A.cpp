#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

bool vis[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	RE(i, n + 5) vis[i] = true;
	vi w;
	RI(i, n) vis[i] = false;
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			vis[i] = true;
			w.pb(i);
		}
		if(!vis[n + 1 - i]) {
			vis[n + 1 - i] = true;
			w.pb(n + 1 - i);
		}
	}
	RI(i, n) vis[i] = false;
	int memo = 1;
	RE(i, k) {
		cout << w[i] << " ";
		vis[w[i]] = true;
		memo = w[i];
	}
	if(!vis[memo + 1]) for(int i = memo + 1; !vis[i]; ++i) cout << i << " ";
	else if(!vis[memo - 1]) for(int i = memo - 1; !vis[i]; --i) cout << i << " ";
	
	return 0;
}