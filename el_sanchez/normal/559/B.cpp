#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second                    
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-7;
const int INF = 1E9;
const int MAXN = 200500;
    
string s[2], curS;
int K, L;
int ind[2][MAXN];
vector<string> lib, lib2;

int main() {

   	forn(i, 2)
   		cin >> s[i];
    
   	L = s[0].size();
	while (L != 1 && (L % 2 == 0))
		L >>= 1;
	K = s[0].size() / L;
   	
	lib.resize(K);
	forn(i, K) {
		lib[i] = "";
		for (int j = L * i; j < L * (i + 1); j++)
			lib[i] += s[0][j];	
	}
	sort(all(lib));
	
	lib2.pb(lib[0]);
	forab(i, 1, lib.size())
		if (lib[i - 1] != lib[i])
			lib2.pb(lib[i]);
	lib = lib2;
	
	forn(id, 2) {
		forn(i, K) {
			curS = "";
			for (int j = L * i; j < L * (i + 1); j++)
				curS += s[id][j];	
			auto it = lower_bound(all(lib), curS);	
			if (it == lib.end()) {
				cout << "NO";
				return 0;
			}
			int pos = it - lib.begin();
			if (lib[pos] != curS) {
				cout << "NO";
				return 0;
			}
			ind[id][i] = pos;
		}
		
	//	forn(i, K)
	//		cout << ind[id][i] << " \n"[i == K - 1];
	}
	
	//sorting
	forn(id, 2) {
		int step = 1;
		while (step < K) {
			for (int i = 0; i < K; i += step * 2) {
				//cmp (i) & (i + 1)
				bool cmp = 0;
				for (int j = i; j < (i + step); j++) {
					if (ind[id][j] < ind[id][j + step])
						break;
					if (ind[id][j] > ind[id][j + step]) {
						cmp = 1;
						break;
					}
				}				
				if (cmp) { //swap
					for (int j = i; j < (i + step); j++)
						swap(ind[id][j], ind[id][j + step]);		
				}
			}
			
			step *= 2;
		}	
		
	//	forn(i, K)
	//		cout << ind[id][i] << " \n"[i == K - 1];
	
	}
	
	//cmp
	forn(i, K)
		if (ind[0][i] != ind[1][i]) {
			cout << "NO";
			return 0;
		}
	cout << "YES";
	
	return 0;
}