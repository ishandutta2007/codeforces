#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

string f[1005];
int n, m;

bool inside(int x, int y){
	if(x < 0 || y < 0 || x >= n || y >= m)
		return false;
	if(f[x][y] == '*')
		return false;
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin >> n >> m;
	rep(i,0,n)
		cin >> f[i];
	int sx, sy;
	int ex, ey;
	rep(i,0,n)
		rep(j,0,m){
			if(f[i][j] == 'S'){
				sx = i;
				sy = j;
			}
			if(f[i][j] == 'T'){
				ex = i;
				ey = j;
			}
		}
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	rep(d1,0,4){
	rep(d2,0,4){
	rep(d3,0,4){
		if(d1%2 == d2%2)
			continue;
		if(d2%2 == d3%2)
			continue;
		int x=sx;
		int y=sy;
		while(inside(x, y)){
			int x2=x;
			int y2=y;
			while(inside(x2, y2)){
				if(x2 == ex || y2 == ey){
					int x3=x2;
					int y3=y2;
					while(inside(x3, y3)){
						if(x3 == ex && y3 == ey){
							cout << "YES" << endl;
							return 0;
						}
						x3 += dx[d3];
						y3 += dy[d3];
					}
					break;
				}
				x2 += dx[d2];
				y2 += dy[d2];
			}
			x += dx[d1];
			y += dy[d1];
		}
	}
	}
	}
	cout << "NO" << endl;
}