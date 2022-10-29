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
const int MAXN = 30300;

int n, p;
string s, ans, cur;
string A = "abcd";
int id[4];
      
int main() {

	cin >> n >> p;
	cin >> s;
		
	if (p == 1) {
		cout << "NO\n";
	} else if (p == 2) {
		if (n == 1) {
			if (s[0] == 'a')
				cout << "b\n";
			else
				cout << "NO\n";
		} else if (n == 2) {
			if (s[0] == 'a')
				cout << "ba\n";
			else
				cout << "NO\n";
		} else {
			cout << "NO\n";	
		}
	} else {
		ans = "";
		for (int i = 0; i < n; i++) {
			cur = "";
			forn(j, i + 1)
				cur += s[j];
			
			while (int(cur[i] - 'a') < p - 1) {
				cur[i]++;
			
				forn(j, n - i - 1)
					cur += ' ';

				forn(j, 3)
					id[j] = j;
				forn(ii, 6) {
					for (int j = i + 1; j < n; j++) {
						cur[j] = A[id[(j - i) % 3]];
					}

					bool ok = 1;
					forn(i, n - 2)
						if (cur[i] == cur[i + 2])
							ok = 0;
					forn(i, n - 1)
						if (cur[i] == cur[i + 1])
							ok = 0;
					
					if (ok && s < cur && (ans.size() == 0 || cur < ans)) {
						ans = cur;		
					}
					
					next_permutation(id, id + 3);	
				}
			}
		}
		
		if (ans.size() == 0)
			cout << "NO\n";
		else
			cout << ans << '\n';
	}
	
	return 0;	
}