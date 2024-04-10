#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n;
int a[105];
int main(){
	cin >> n;
	rep(i, 0, n)
		cin >> a[i];
	int base=0;
	rep(i, 0, n-1)
		base=max(base, a[i+1]-a[i]);
	int best=1000000000;
	rep(i, 1, n-1){
		best=min(best, a[i+1]-a[i-1]);
	}
	cout << max(base, best) << endl;
}