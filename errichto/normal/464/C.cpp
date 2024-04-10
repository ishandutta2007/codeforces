#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
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
const int inf=1e9+5, nax=2e5+5;

ll mod = 1000 * 1000 * 1000 + 7;

char sl[nax];
ll wart[10];
string in[nax];
ll ile[10];

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> sl;
	int z;
	cin >> z;
	RE(i, z)
		cin >> in[i];
	
	RE(i, 10) {
		wart[i] = i;
		ile[i] = 10LL;
	}
	
	for(int i = z - 1; i >= 0; --i) {
		int d = in[i].length();
		ll x = 0;
		ll licz = 1LL;;
		for(int j = 3; j < d; ++j) {
			int c = (int)(in[i][j] - '0');
			x = (ile[c] * x + wart[c]) % mod;
			licz = (licz * ile[c]) % mod;
		}
		int a = in[i][0] - '0';
		wart[a] = x;
		ile[a] = licz;
	}
	int d = strlen(sl);
	ll x = 0;
	RE(i, d) {
		int c = (int) ( sl[i] - '0' );
		x = (ile[c] * x + wart[c]) % mod;
	}
	cout << x;
	return 0;
}