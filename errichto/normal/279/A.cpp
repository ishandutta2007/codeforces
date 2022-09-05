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

int main()
{
	ios_base::sync_with_stdio(0);
	pii cel;
	cin >> cel.x >> cel.y;
	pii teraz, M, m;
	M = m = teraz = mp(0, 0);
	dir[0] = mp(1, 0);
	dir[1] = mp(0, 1);
	dir[2] = mp(-1, 0);
	dir[3] = mp(0, -1);
	int d = 0;
	while(teraz != cel) {
		if(teraz.x > M.x) {
			M.x = teraz.x;
			d++;
		}
		if(teraz.x < m.x) {
			m.x = teraz.x;
			d++;
		}
		if(teraz.y > M.y) {
			M.y = teraz.y;
			d++;
		}
		if(teraz.y < m.y) {
			m.y = teraz.y;
			d++;
		}
		teraz.x += dir[d % 4].x;
		teraz.y += dir[d % 4].y;
	}
	cout << d << "\n";
	return 0;
}