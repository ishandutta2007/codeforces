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

double dp[105][105][105][3];

int main(){
	int r, s, p;
	scanf("%d%d%d", &r, &s, &p);
	rep(i,0,r+1)
	rep(j,0,s+1)
	rep(k,0,p+1){
		if(i == 0)
			dp[i][j][k][0]=0;
		if(j == 0)
			dp[i][j][k][1]=0;
		if(k == 0)
			dp[i][j][k][2]=0;
		if(!i && !j){
			dp[i][j][k][2]=1;
			continue;
		}
		if(!j && !k){
			dp[i][j][k][0]=1;
			continue;
		}
		if(!k && !i){
			dp[i][j][k][1]=1;
			continue;
		}
		if(!i){
			dp[i][j][k][1]=1;
			dp[i][j][k][2]=0;
			continue;
		}
		if(!j){
			dp[i][j][k][2]=1;
			dp[i][j][k][0]=0;
			continue;
		}
		if(!k){
			dp[i][j][k][0]=1;
			dp[i][j][k][1]=0;
			continue;
		}
		double sum=i*j+j*k+k*i;
		rep(l,0,3)
			dp[i][j][k][l] += (i*j)*dp[i][j-1][k][l]/sum;
		rep(l,0,3)
			dp[i][j][k][l] += (j*k)*dp[i][j][k-1][l]/sum;
		rep(l,0,3)
			dp[i][j][k][l] += (k*i)*dp[i-1][j][k][l]/sum;
	}
	rep(i,0,3)
		printf("%.10lf ", dp[r][s][p][i]);
	printf("\n");
}