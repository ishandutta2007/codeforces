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

long long dp[505][2];
char field[505][505];

int main(){
	int n, m, mod;
	scanf("%d%d%d", &n, &m, &mod);
	for(int i=0; i < m; ++i)
		scanf("%s", field[i]);
	int ones=0;
	for(int i=0; i < n; ++i){
		int num=0;
		for(int j=0; j < m; ++j)
			if(field[j][i] == '1')
				++num;
		if(num == 1)
			++ones;
	}
	bool read=0,write=1;
	dp[ones][write]=1;
	for(int i=m; i < n; ++i){
		write^=1;
		read^=1;
		for(int j=0; j <= 500; ++j)
			dp[j][write]=0;
		for(int n1=0; n1 <= 500; ++n1){
			int n0=n-i-n1/2;
			int n2=n-n1-n0;
			dp[n1][write] += n0*n1*dp[n1][read];
			dp[n1][write]%=mod;
			dp[n1+2][write] += ((n0*(n0-1))/2)*dp[n1][read];
			dp[n1+2][write]%=mod;
			if(n1 > 1){
				dp[n1-2][write] += ((n1*(n1-1))/2)*dp[n1][read];
				dp[n1-2][write]%=mod;
			}
		}
	}
	printf("%I64d\n", dp[0][write]);
}