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
const int MAXN = 222;

int n;
string s;
char c[3];
int cnt[3];
bool dp[MAXN][MAXN][MAXN];
bool ok[3];

int main() {

	c[0] = 'B';
	c[1] = 'R';
	c[2] = 'G';
	
	sort(c, c + 3);
		
	cin >> n;
	cin >> s;
	forn(j, 3)
		cnt[j] = 0;
	forn(i, n)
		forn(j, 3)
			if (s[i] == c[j])
				cnt[j]++;
				
	dp[cnt[0]][cnt[1]][cnt[2]] = 1;
	
	int i[3];
	for (int sum = n; sum >= 0; sum--) 
		for (i[0] = n; i[0] >= 0; i[0]--)
			for (i[1] = n; i[1] >= 0; i[1]--) {
				i[2] = sum - i[0] - i[1];
				if (i[2] < 0)
					continue;
					
				if (dp[i[0]][i[1]][i[2]]) {
					for (int d = 0; d < 3; d++)
						if (i[d] >= 2) {
							i[d]--;
							dp[i[0]][i[1]][i[2]] = 1;
							i[d]++;	
						}
						
					for (int d = 0; d < 3; d++)
						if (i[d] >= 1 && i[(d + 1) % 3] >= 1) {
							i[d]--;
							i[(d + 1) % 3]--;
							i[(d + 2) % 3]++;
							dp[i[0]][i[1]][i[2]] = 1;
							i[d]++;
							i[(d + 1) % 3]++;
							i[(d + 2) % 3]--;							
						}  		
							
				}
			}
	
	ok[0] = dp[1][0][0];
	ok[1] = dp[0][1][0];
	ok[2] = dp[0][0][1];
	
	forn(j, 3)
		if (ok[j])
			cout << c[j];
	cout << '\n';
	return 0;
}