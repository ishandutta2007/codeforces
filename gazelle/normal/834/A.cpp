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

#define INF 1000000000
#define MOD 1000000007
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
	char s, e;
	int n;
	cin>>s>>e>>n;
	n = n % 4;
	int s_i, e_i;
	if(s == '^') s_i = 0;
	if(s == '>') s_i = 1;
	if(s == 'v') s_i = 2;
	if(s == '<') s_i = 3;
	if(e == '^') e_i = 0;
	if(e == '>') e_i = 1;
	if(e == 'v') e_i = 2;
	if(e == '<') e_i = 3;
	if((s_i + n) % 4 == e_i && (e_i + n) % 4 == s_i) cout<<"undefined"<<endl;
	else if((s_i + n) % 4 == e_i) cout<<"cw"<<endl;
	else if((e_i + n) % 4 == s_i) cout<<"ccw"<<endl;
	else cout<<"undefined"<<endl;
}