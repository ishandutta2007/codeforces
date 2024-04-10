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
	vector<vector<int> > p(4, vector<int>(4));
	REP(i, 4) {
		REP(j, 4) {
			cin>>p[i][j];
		}
	}
	bool det = false;
	if(p[0][3] == 1 && p[0][0] | p[0][1] | p[0][2] | p[1][0] | p[2][1] | p[3][2] == 1) {
		det = true;
	}
	if(p[1][3] == 1 && p[1][0] | p[1][1] | p[1][2] | p[2][0] | p[3][1] | p[0][2] == 1) {
		det = true;
	}
	if(p[2][3] == 1 && p[2][0] | p[2][1] | p[2][2] | p[3][0] | p[0][1] | p[1][2] == 1) {
		det = true;
	}
	if(p[3][3] == 1 && p[3][0] | p[3][1] | p[3][2] | p[0][0] | p[1][1] | p[2][2] == 1) {
		det = true;
	}
	if(det) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}