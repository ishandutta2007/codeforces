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
const int MAXN = 10;

int n, k;
string s, ans;
int num[MAXN];

int main() {

	cin >> n;
	cin >> s;
	memset(num, 0, sizeof(num));
	ans = "";
	forn(i, n) {
		int X = s[i] - '0';	
		for (int x = 2; x <= X; x++) {
			k = x;
			for (int j = 2; j <= 9; j++) {
				while (k % j == 0) {
					k /= j;
					num[j]++;
				}
			}
		}
	}

	for (int i = 9; i >= 2; i--) {
		while (num[i] > 0) {
			ans += char('0' + i);
			for (int j = 2; j <= i; j++) {
				if (j == 4)
					num[2] -= 2;
				else if (j == 6)
					num[2]--, num[3]--;
				else if (j == 8)
					num[2] -= 3;
				else if (j == 9)
					num[3] -= 2;
				else
					num[j]--;		
			}						}
	}	
	
	cout << ans;	

	return 0;
}