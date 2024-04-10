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
#define x first
#define y second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;
const double PI = acos(0) * 2.0;

pii dir[4];

const string no = "NO\n";
const string yes = "YES\n";

int main()
{
	ios_base::sync_with_stdio(0);
	int n, R, r;
	cin >> n >> R >> r;
	if(n == 1) {
		if(R < r) cout << no;
		else cout << yes;
		return 0;
	}
	if(2 * r > R) {
		cout << no;
		return 0;
	}
	if(2 * r == R) {
		if(n == 2) cout << yes;
		else cout << no;
		return 0;
	}
	double kat = asin(  ((double)(r))/(R - r)  );
	if(kat * n * 2 > 1e-9 + asin(1) * 4) cout << no;
	else cout << yes;
	return 0;
}