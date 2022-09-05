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



int main()
{
	ios_base::sync_with_stdio(0);
	
	ll n, a, b;
	cin >> n >> a >> b;
	n *= 6LL;
	if(a * b >= n) {
		cout << a * b << "\n";
		cout << a << " " << b;
		return 0;
	}
	while(true) {
		for(ll i = min(a, b); i * i <= n; ++i) if(n % i == 0LL) {
			ll j = n / i;
			if(i >= min(a, b) && j >= max(a, b)) {
				cout << n << "\n";
				if(a < b)
					cout << i << " " << j;
				else cout << j << " " << i;
				return 0;
			}
		}
		n++;
	}
	return 0;
}