//#define _GLIBCXX_DEBUG
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
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-9;
const int INF = 1E9; 
const int MAXN = 511;
         
int n, sz, k;
map<int, int> numbers;
int res[MAXN];

int main() {

	cin >> n;
	sz = n * n;
	forn(i, sz) {
		scanf("%d", &k);	
		numbers[-k]++;
	}
		
	forn(i, n) {
		while (numbers.begin()->Y == 0)
			numbers.erase(numbers.begin());
			
		int x = numbers.begin()->X;
		x = -x;	
		res[i] = x;
		
		for (int j = 0; j < i; j++)
			numbers[-__gcd(res[j], res[i])] -= 2;
		numbers[-res[i]]--;		
	}
	
	forn(i, n)
		cout << res[i] << " \n"[i == n - 1];
		
	return 0;
}