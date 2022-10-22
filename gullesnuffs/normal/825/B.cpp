#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

string f[10];
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={1,0,-1,-1,-1,0,1,1};


bool inside(int x, int y){
	return x>= 0 && y >= 0 && x < 10 && y < 10;
}

bool hasWon(){
	rep(i,0,10)
		rep(j,0,10){
			rep(k,0,8){
				bool ok = 1;
				rep(l,0,5){
					int x = i+l*dx[k];
					int y = j+l*dy[k];
					if(!inside(x, y) || f[x][y] != 'X'){
						ok = 0;
					}
				}
				if(ok)
					return 1;
			}
		}
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
	rep(i,0,10)
		cin >> f[i];
	rep(i,0,10)
		rep(j,0,10){
			if(f[i][j] != '.')
				continue;
			f[i][j] = 'X';
			//rep(k,0,10)
			//	cerr << f[k] << endl;
			if(hasWon()){
				cout << "YES" << endl;
				return 0;
			}
			f[i][j] = '.';
		}
	cout << "NO" << endl;
}