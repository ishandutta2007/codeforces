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
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 100500;
  
int n, k;
int a[MAXN], res;

int f0(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	if (x == 2)
		return 2;
	return !(x & 1);		
}

int f1(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	if (x == 2)
		return 0;
	if (x == 3)
		return 1;
	if (x == 4)
		return 2;
	if (x == 5)
		return 0;
	if (x == 6)
		return 2;
		
	if (x & 1)
		return 0;
	if ((x >> 1) & 1)
		return 1;	
		
	return 3 - f1(x >> 1);
}

int main() {

	cin >> n >> k;
	forn(i, n)
		scanf("%d", &a[i]);
	/*
	forn(i, 35)
		cout << i << ": " << f1(i) << '\n';
	*/	
	res = 0;
	forn(i, n)
		if (k & 1)
			res = res ^ f1(a[i]);
		else
			res = res ^ f0(a[i]);
		
	cout << (res == 0 ? "Nicky" : "Kevin");
		
	return 0;
}