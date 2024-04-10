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
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 100500;
        
string L = "aeiouy";

int n;
int p[MAXN];
string s;

int main() {

	cin >> n;
	forn(i, n)
		scanf("%d", &p[i]);
	scanf("\n");

	forn(i, n) {
		getline(cin, s);
		//cout << s << '\n';
		
		int vw = 0;
		forn(j, s.size())
			forn(k, L.size())
				if (s[j] == L[k])
					vw++;

		if (vw != p[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	
	return 0;
}