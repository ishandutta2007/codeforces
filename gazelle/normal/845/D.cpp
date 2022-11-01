#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<complex>
#include<unordered_map>

#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	int res=0;
	int n;
	cin>>n;
	stack<int> sl;
	int c=0;
	int cs=0;
	REP(i,n) {
		int t;
		cin>>t;
		switch(t) {
			case 1: {
				cin>>cs;
				while(!sl.empty()&&sl.top()<cs) {
					++res;
					sl.pop();
				}
				break;
			}
			case 2: {
				res+=c;
				c=0;
				break;
			}
			case 3: {
				int s;
				cin>>s;
				if(s<cs) ++res;
				else sl.push(s);
				break;
			}
			case 4: {
				c=0;
				break;
			}
			case 5: {
				while(!sl.empty()) sl.pop();
				break;
			}
			case 6: {
				++c;
				break;
			}
		}
	}
	cout<<res<<endl;
}