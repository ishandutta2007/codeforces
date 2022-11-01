#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<deque>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};



int main(void) {
	string n;
	cin>>n;
	if(stoi(n) < 8) cout<<1<<endl;
	else {
		if(n[0] != 9) {
			string s = "";
			s += to_string(stoi(n.substr(0, 1)) + 1);
			REP(i, n.size() - 1) {
				s += "0";
			}
			cout<<stoi(s) - stoi(n)<<endl;
		} else {
			string s = "";
			s += "1";
			REP(i, n.size()) {
				s += "0";
			}
			cout<<stoi(s) - stoi(n)<<endl;
		}
	}
}