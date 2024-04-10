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
const int MAXN = 200500;

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<string, int> id;

int main() {

	id["monday"] = 0;
	id["tuesday"] = 1;
	id["wednesday"] = 2;
	id["thursday"] = 3;
	id["friday"] = 4;
	id["saturday"] = 5;
	id["sunday"] = 6;

	string s1, s2;
	cin >> s1;
	cin >> s2;
	
	int a1 = id[s1];
	int a2 = id[s2];
	for (int i = 0; i < 11; i++) {
		if (a2 == (a1 + days[i]) % 7) {
			cout << "YES\n";
			return 0;
		}
	}
	
	cout << "NO\n";
		
	return 0;
}