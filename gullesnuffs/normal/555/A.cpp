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

int a[1000005];
int m[1000005];

int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	int ans=1;
	rep(i,0,k){
		scanf("%d", m+i);
		rep(j,0,m[i]){
			scanf("%d", a+j);		
		}
		ans += 2*m[i]-1;
		rep(j,0,m[i]){
			if(a[j] != j+1)
				break;
			ans -= 2;
		}
	}
	printf("%d\n", ans);
}