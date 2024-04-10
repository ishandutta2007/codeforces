#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		ll x, y;
		int X, Y;
		scanf("%d%d", &X, &Y);
		x=X;
		y=Y;
		ll hi = 2e6;
		ll lo = 1;
		while(hi-lo > 1){
			ll mid = (lo+hi)/2;
			if(mid*y > 3e18/(mid*mid)){
				hi = mid;
				continue;
			}
			if(mid*mid*mid*y > x*x){
				hi = mid;
			}
			else{
				lo = mid;
			}
		}
		ll a = lo;
		ll b = x / (a*a);
		if(x == a*a*b && y == a*b*b)
			puts("Yes");
		else
			puts("No");
	}
}