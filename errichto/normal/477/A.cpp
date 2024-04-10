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
	
	ll a, b;
	cin >> a >> b;
	const ll mod = 1000 * 1000 * 1000 + 7;
	ll p = a * (a + 1LL) / 2LL;
	p %= mod;
	p *= b;
	p %= mod;
	p += a;
	p %= mod;
	ll cyk = b * (b - 1LL) / 2LL;
	cyk %= mod;
	p *= cyk;
	p %= mod;
	cout << p;
	
	return 0;
}