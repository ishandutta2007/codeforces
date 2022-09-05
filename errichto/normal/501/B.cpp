#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
#include<map>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

map<string, string> m;

int main(int argc, char * argv[]) {
	debug = argc > 1;
	ios_base :: sync_with_stdio(0);
	
	int n;
	cin >> n;
	int counter = 0;
	while(n--) {
		string a, b;
		cin >> a >> b;
		if(m[a] == "") {
			m[b] = a;
			++counter;
		}
		else {
			m[b] = m[a];
			m[a] = "";
		}
	}
	cout << counter << "\n";
	for(auto a : m) {
		if(a.nd != "") 
			cout << a.nd << " " << a.st << "\n";
	}
	
	return 0;
}