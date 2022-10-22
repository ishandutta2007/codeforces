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

int main(){
	int n;
	cin >> n;
	rep(i, 0, n){
		long long l, r;
		cin >> l >> r;
		long long M=l;
		while(l <= r){
			M=max(l, M);
			l|=l+1;
		}
		cout << M << endl;
	}
}