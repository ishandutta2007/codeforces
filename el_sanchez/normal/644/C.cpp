#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
const ll MOD[3] = {999989981, 999989957, 999979957};
const ll PW[3] = {1000010029, 1002010033, 1000510037};

struct piii {
	int x, y, z;

	piii(int _X = 0, int _Y = 0, int _Z = 0) {
		x = _X;
		y = _Y;
		z = _Z;
	}
};

bool operator==(piii a, piii b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

bool operator!=(piii a, piii b) {
	return !(a == b);	
}
    
bool operator<(piii a, piii b) {
	if (a.x != b.x)
		return a.x < b.x;
	if (a.y != b.y)
		return a.y < b.y;
	return a.z < b.z;	
}

int n, m, sz;
string s, res[2];
//ll P[2][MAXN];
ll tmp[3];
pair<piii, piii> hashes[MAXN];
pair<piii, piii> blocks[MAXN];
map<piii, string> strings, paths;
vector<piii> ans[MAXN];

piii getHash(string &s) {
	ll res[3];

	forn(i, 3) {
		res[i] = 0;
		forn(j, s.size())
			res[i] = (res[i] * PW[i] + s[j]) % MOD[i];
	}
	
	return piii(res[0], res[1], res[2]);
}

int main() {   
/*	
	forn(i, 2) {
		P[i][0] = 1;
		forab(j, 1, MAXN)
			P[i][j] = (P[i][j - 1] * PW[i]) % MOD[i]; 	
	}
*/	
	cin >> n;
	forn(i, n) {
		cin >> s;

		res[0] = "";
		res[1] = "/";
		int id = 0;
		for (int j = 0; j < (int)s.size(); j++) {
			if (id == 0 && j >= 7 && s[j] == '/') {
				id++;	
			}
			res[id] += s[j];	
		}
		//cout << res[0] << ' ' << res[1] << '\n';
		
		piii p1 = getHash(res[0]);
		piii p2 = getHash(res[1]);
		
		strings[p1] = res[0];
		paths[p2] = res[1];
		
		hashes[i] = {p1, p2};
	}
			
	sort(hashes, hashes + n);
	n = unique(hashes, hashes + n) - hashes;
	/*
	forn(i, n)
		cout << strings[hashes[i].X] << ' ' << hashes[i].Y.x << ' ' << hashes[i].Y.y << ' ' << hashes[i].Y.z << '\n';
	*/
	int L = 0;
	m = 0;
	for (int i = 1; i <= n; i++)
		if (hashes[L].X != hashes[i].X || i == n) {
		    
			tmp[0] = tmp[1] = tmp[2] = 0;
			
			s = "";
			for (int j = L; j < i; j++)
				s += paths[hashes[j].Y] + '!';
				
			blocks[m] = {getHash(s), hashes[L].X};
			m++;						
			
			L = i;
		}
		
	sort(blocks, blocks + m);
	
	L = 0;
	sz = 0;
	for (int i = 1; i <= m; i++)
		if (blocks[L].X != blocks[i].X || i == m) {
	    	if (L + 1 < i) {
	    		for (int j = L; j < i; j++) {
	    		 	ans[sz].pb(blocks[j].Y);
	    		}
	    		sz++;
	    	}
			
			L = i;	
		}
		
	cout << sz << '\n';
	forn(i, sz) {
		forn(j, ans[i].size())
			cout << strings[ans[i][j]] << " \n"[j == (int)ans[i].size() - 1];	
	}
	
	return 0;
}