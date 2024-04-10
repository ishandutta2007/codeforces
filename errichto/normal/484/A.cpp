#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i = 0, _n = (n); i < _n; ++i)
#define RI(i,n) for(int i = 1, _n = (n); i <= _n; ++i)
const int inf = 1e9 + 5, nax = 1e6 + 5;

ll pot[105];

int main()
{
	ios_base :: sync_with_stdio(false);
	
	pot[0] = 1;
	RI(i, 100) pot[i] = pot[i - 1] * 2LL;
	
	int z;
	cin >> z;
	while(z--) {
		ll low, high;
		cin >> low >> high;
		if(low == high) cout << low << "\n";
		else {
			for(int k = 60; k >= 0; --k)
				if((high & pot[k]) && !(low & pot[k])) {
					low = (low >> k);
					low++;
					low = (low << k);
					low--;
					ll res = low;
					res += (1LL << k);
					if(res == high) cout << res << "\n";
					else cout << low << "\n";
					k = -1;
				}
		}
	}
	return 0;
}