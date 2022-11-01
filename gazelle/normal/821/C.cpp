#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<tuple>
#include<complex>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

using namespace std;

int main() {
	int n;
	cin>>n;
	int res = 0;
	int roc = 1;
	vector<bool> used(n, false);
	vector<int> st(n, 0);
	int rocr = 0;
	REP(i, 2 * n) {
		string s;
		cin>>s;
		if(s == "add") {
			int a;
			cin>>a;
			st[rocr] = a;
			++rocr;
		} else if(s == "remove") {
			if(rocr > 0) {
				if(st[rocr - 1] != roc) {
					while(rocr > 0) {
						used[st[rocr - 1]] = true;
						--rocr;
					}
					++res;
				} else {
					st[rocr - 1] = 0;
					--rocr;
				}
			}
			++roc;
		}
	}
	cout<<res<<endl;
}