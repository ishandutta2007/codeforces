#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

vector<int> d[1000005];
int phi[1000005];
int phisum[1000005];
long long K[1000005], M[1000005];

long long getSquare(long long n){
	//printf("getSquare(%I64d)=%I64d\n", n, (n*n*n*2+n)/3-2*n*n+2*phisum[n]);
	return ((n*n*n*2+n)/3-2*n*n+2*phisum[n])%MOD;
}

long long fix(long long n){
	n %= MOD;
	while(n < 0)
		n += MOD;
	return n;
}

long long solve(long long n, long long m){
	if(n > m)
		return solve(m, n);
	if(!n)
		return 0;
	if(n == 1)
		return m;
	if(n == m)
		return fix(getSquare(n)+solve(n, n-1)*2-solve(n, n-2));
	//printf("solve(%I64d, %I64d)=%I64d\n", n, m, m*K[n]+M[n]);
	return fix(m*K[n]+M[n]);
}

int main(){
	for(int i=1; i <= 1000000; ++i)
		phi[i]=i;
	for(int i=1; i <= 1000000; ++i){
		for(int j=i; j <= 1000000; j += i){
			d[j].push_back(i);
		}
		for(int j=0; j < d[i].size(); ++j){
			if(d[d[i][j]].size() == 2)
				phi[i]=(phi[i]/d[i][j])*(d[i][j]-1);
		}
		for(int j=0; j < d[i].size(); ++j)
			phisum[i] += phi[d[i][j]]*(i/d[i][j]);
	}
	K[1]=1;
	M[1]=0;
	for(int i=2; i <= 1000000; ++i){
		K[i]=fix(solve(i, i)-solve(i-1, i));
		M[i]=fix(solve(i, i)-K[i]*i);
	}
	int t;
	scanf("%d", &t);
	for(int i=0; i < t; ++i){
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%I64d\n",solve(n, m));
	}
	return 0;
}