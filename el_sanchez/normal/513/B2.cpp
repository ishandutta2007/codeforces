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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 1111;

int n, i;
ll m, num[MAXN];
vi a;
int ptr[2];

int main() {

	cin >> n >> m;
	m--;
	a.resize(n);
	ptr[0] = 0;
	ptr[1] = n - 1;
	   
	num[1] = 1;
	for (int i = 2; i <= n; i++)
		num[i] = num[i - 1] * 2;
	
	i = 1;
	while (ptr[0] <= ptr[1]) {
		int k = ptr[1] - ptr[0];
		//cerr << num[k] << endl;
		
		if (m < num[k]) {
			a[ptr[0]++] = i++;
		} else {
			a[ptr[1]--] = i++;
			m -= num[k];
		}
		
		//cerr << ptr[0] << ' ' << ptr[1] << '\n';
	}
	
	forn(i, n)
		cout << a[i] << ' ';
	
	return 0;
}