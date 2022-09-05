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

ll t[nax], s[nax];

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	cin >> n;
	RE(i, n) {
		cin >> t[i];
		if(i > 0) s[i] = s[i-1] + t[i];
		else s[i] = t[i];
	}
	ll suma = s[n-1];
	if(suma % 3LL != 0LL) {
		cout << 0;
		return 0;
	}
	suma /= 3LL;
	ll licz = 0;
	RE(i, n - 1) if(s[i] == 2LL * suma) licz++;
	ll res = 0;
	RE(i, n - 1) {
		if(s[i] == suma * 2LL) licz--;
		if(s[i] == suma) res += licz;
	}
	cout << res;
	
	return 0;
}