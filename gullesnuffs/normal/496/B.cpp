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

char s[1005];
string best;

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	rep(i, 0, n){
		string cur;
		rep(j, 0, n){
			cur.push_back('0'+((s[(i+j)%n]-s[i]+10)%10));
		}
		if(i == 0 || cur < best)
			best=cur;
	}
	cout << best << endl;
}