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

double p[25];
double dp[(1<<20)];
double ans[25];

int main(){
	int k, n;
	scanf("%d%d", &n, &k);
	int nonzero=0;
	rep(i,0,n){
		scanf("%lf", p+i);
		if(p[i] > 0)
			++nonzero;
	}
	if(k > nonzero)
		k=nonzero;
	dp[0]=1;
	rep(i,0,(1<<n)){
		if(__builtin_popcount(i) == k){
			rep(j,0,n){
				if(!(i&(1<<j))){
					continue;
				}
				ans[j] += dp[i];
			}
		}
		double sum=0;
		rep(j,0,n){
			if(i&(1<<j))
				continue;
			sum += p[j];
		}
		if(sum == 0)
			continue;
		rep(j,0,n){
			if(i&(1<<j))
				continue;
			dp[i|(1<<j)] += dp[i]*p[j]/sum;
		}
	}
	rep(i,0,n){
		printf("%.7lf ", ans[i]);
	}
	printf("\n");
}