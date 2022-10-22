#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

char s[1005], t[1005];

int main(){
	int n;
	scanf("%d", &n);
	scanf("%s%s", s, t);
	int ans=0;
	rep(i,0,n){
		ans += min(min(abs(s[i]-t[i]), abs(s[i]+10-t[i])), abs(s[i]-10-t[i]));
	}
	printf("%d\n", ans);
}