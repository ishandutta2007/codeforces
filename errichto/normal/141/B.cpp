#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
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
const double PI = acos(0) * 2.0;

int main()
{
	ios_base::sync_with_stdio(0);
	int licz = 1;
	int a, x, y;
	cin >> a >> x >> y;
	if(y < a) {
		if(y == 0 || 2 * abs(x) >= a) cout << -1;
		else cout << licz;
		return 0;
	}
	licz++;
	y -= a;
	
	licz += 3 * (y / (2 * a));
	y %= (2 * a);
	
	if(y < a) {
		if(y == 0 || 2 * abs(x) >= a) cout << -1;
		else cout << licz;
		return 0;
	}
	y -= a;
	licz++;
	
	if(y < a) {
		if(y == 0 || abs(x) >= a || x == 0) cout << -1;
		else if(x < 0) cout << licz;
		else cout << licz + 1;
		return 0;
	}
	cout << -1;
	return 0;
}