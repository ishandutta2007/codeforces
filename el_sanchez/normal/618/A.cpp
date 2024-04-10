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
#define db(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;

int n;
vi a;

int main() {

    cin >> n;
    a.clear();
    forn(i, n) {
    	a.pb(1);
    	while (a.size() > 1 && a[(int)a.size() - 1] == a[(int)a.size() - 2]) {
    		a.pop_back();
    		a.back()++;
    	}
    }
		
    forn(i, a.size())
    	cout << a[i] << ' ';
    cout << '\n';
    
	return 0;
}