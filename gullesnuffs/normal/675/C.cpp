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
	
map<ll, int> M;

int main(){
	int n;
	scanf("%d", &n);
	ll sum=0;
	int Max=0;
	rep(i,0,n){
		int a;
		scanf("%d", &a);
		sum += a;
		M[sum]++;
		Max=max(Max, M[sum]);
	}
	printf("%d\n", n-Max);
}