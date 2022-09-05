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

pii p[3];
bool koniec = false;

bool Ok() {
	vi w;
	RE(i, 3) RE(j, i) {
		int a = p[j].x - p[i].x;
		int b = p[j].y - p[i].y;
		w.pb(a*a + b*b);
	}
	sort(w.begin(), w.end());
	if(!koniec) koniec = w[0] + w[1] == w[2] && w[0] > 0;
	return w[0] + w[1] == w[2] && w[0] > 0;
}



int main()
{
	ios_base :: sync_with_stdio(0);
	
	RE(i, 3) cin >> p[i].x >> p[i].y;
	if(Ok()) {
		cout << "RIGHT";
		return 0;
	}
	RE(i, 3) {
		for(int a = -1; a <= 1; ++a) {
			p[i].x += a;
			Ok();
			p[i].x -= a;
			p[i].y += a;
			Ok();
			p[i].y -= a;
		}
	}
	if(koniec) cout << "ALMOST";
	else cout << "NEITHER";

	return 0;
}