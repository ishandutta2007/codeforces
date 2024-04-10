#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pld pair<ld, ld>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;
const ld eps = 1e-8;

ld Odl(pld a, pld b) {
	b.x -= a.x;
	b.y -= a.y;
	return sqrt(b.x * b.x + b.y * b.y);
}

pld p[105];

int main()
{
	ios_base :: sync_with_stdio(0);
	
	int n;
	ld vb, vs;
	pld cel;
	cin >> n >> vb >> vs;
	RI(i, n) cin >> p[i].x;
	cin >> cel.x >> cel.y;
	int best = 1;
	ld wart = (ld) inf;
	ld wart2 = (ld) inf;
	RI(i, n) if(i > 1) {
		ld czas = p[i].x / vb + Odl(p[i], cel) / vs;
		if(czas < wart - eps || (abs(czas - wart) < eps && Odl(p[i], cel) < wart2)) {
			best = i;
			wart = czas;
			wart2 = Odl(p[i], cel);
		}
	}
	cout << best;

	return 0;
}