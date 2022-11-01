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
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	int a, b;
	cin>>a>>b;
	int cnt = 1;
	int d = 0;
	while(true) {
		if(d == 0) {
			a -= cnt;
			if(a < 0) {
				cout<<"Vladik"<<endl;
				break;
			}
			++cnt;
			d = 1;
		} else {
			b -= cnt;
			if(b < 0) {
				cout<<"Valera"<<endl;
				break;
			}
			++cnt;
			d = 0;
		}
	}
}