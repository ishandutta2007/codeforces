#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;
#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define pii pair<ld,ld>
#define mp make_pair
#define x first
#define y second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
const int inf=1e9+5, nax=1e6+5;

pair<ld, ld> p[nax];

void Dostosuj(pii p0, pii & p1) {
	p1.x -= p0.x;
	p1.y -= p0.y;
}

ld odl(pii a, pii b) {
	Dostosuj(a, b);
	return sqrt(b.x * b.x + b.y * b.y - 1e-9);
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	int n;
	ld k;
	cin >> n >> k;
	RE(i, n) cin >> p[i].x >> p[i].y;
	ld res = 0;
	RI(i, n - 1) res += odl(p[i-1], p[i]);
	cout << setprecision(10) << res * k / 50.0;
	return 0;
}