#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<assert.h>
#include<map>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

map<string, string> m;

int main(int argc, char *argv[])
{
	debug = argc > 1;
	ios_base :: sync_with_stdio(0);
	
	int n, z;
	cin >> n >> z;
	while(z--) {
		string a, b;
		cin >> a >> b;
		if(b.length() < a.length()) m[a] = b;
		else m[a] = a;
	}
	while(n--) {
		string a;
		cin >> a;
		cout << m[a] << " ";
	}
	cout << "\n";
	return 0;
}