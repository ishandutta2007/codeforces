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

int Suma(int x) {
	int s = 0;
	while(x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	ll liczba = 1000 * 1000 * 1000;
	ll a, b, c;
	cin >> a >> b >> c;
	vi res;
	RI(suma, 100) {
		ll s = suma;
		ll mno = b;
		RE(_, a) mno *= s;
		mno += c;
		if(mno > 0LL && mno < liczba) if(Suma((int)mno) == suma) res.pb((int) mno);
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for(auto x : res) cout << x << " ";
	
	return 0;
}