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
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define RE(i,n) for(int i=0,_n=(n);i<_n;++i)
#define RI(i,n) for(int i=1,_n=(n);i<=_n;++i)
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
#define all(w) w.begin(),w.end()
const int inf=1e9+5,nax=1e6+5;

ld t[105];

int main()
{
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	RE(i, n) cin >> t[i];
	sort(t, t + n);
	reverse(t, t + n);
	ld res = 0;
	RI(ile, n) {
		ld x = 1, y = 0;
		RE(i, ile) {
			ld x2 = x * (1.0L - t[i]);
			y += (x - y) * t[i];
			x = x2;
		}
		maxi(res, y);
	}
	double rzut = res;
	cout << setprecision(15) << rzut;

	return 0;
}