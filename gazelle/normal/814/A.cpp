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
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

int main(void) {
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	vector<int> b(k);
	REP(i, n) cin>>a[i];
	REP(i, k) cin>>b[i];
	if(k > 1) cout<<"Yes"<<endl;
	else {
		REP(i, a.size()) {
			if(a[i] == 0) {
				a[i] = b[0];
			}
		}
		bool d = true;
		FOR(i, 1, a.size()) {
			if(a[i] < a[i - 1]) d = false;
		}
		if(d) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}