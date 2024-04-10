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

int p[10];
int n, K;
double ans=0;
double dp[205][35][35];

int getPos(int pos, int i, int j){
	if(pos < i || pos > j)
		return pos;
	return j-(pos-i);
}

int main(){
	scanf("%d%d", &n, &K);
	rep(i,0,n)
		scanf("%d", p+i);
	rep(j,0,n)
		rep(k,0,n){
			if(k < j)
				dp[0][j][k]=1;
			else
				dp[0][j][k]=0;
		}
	rep(i,1,K+1){
		rep(j,0,n)
			rep(k,0,n){
				int cnt=0;
				rep(l,0,n)
					rep(m,l,n)
						++cnt;
				rep(l,0,n)
					rep(m,l,n)
						dp[i][j][k] += dp[i-1][getPos(j,l,m)][getPos(k,l,m)]/cnt;
			}
	}
	rep(j,0,n)
		rep(k,j+1,n){
			if(p[k] > p[j])
				ans += dp[K][j][k];
			else
				ans += 1-dp[K][j][k];
		}
	printf("%.10lf\n", ans);
}