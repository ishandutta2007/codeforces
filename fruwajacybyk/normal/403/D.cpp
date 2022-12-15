#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;

lint mod = 1000*1000*1000+7;
lint b[2005][2005];
lint p[1005][1005];
lint fact[1020];


int main(){
	
	FOR(i,0,2005) b[i][0] = b[i][i] = 1;
	FOR(i,2,2005){
		FOR(j,1,i) b[i][j] = (b[i-1][j-1]+b[i-1][j])%mod;
	}
	fact[0] = 1;
	FOR(i,1,1005) fact[i]=(i*1LL*fact[i-1])%mod;


	p[0][0]=1;
	FOR(i,1,1005) p[i][0] = 0;
	p[0][1] = 0;
	FOR(i,1,1005) p[i][1] = 1;


	FOR(i,2,1005){
		FOR(j,1,1005){
			lint u1 = (j-i>=0) ? p[j-i][i-1] : 0;
			lint u2 = (j-i>=0) ? p[j-i][i] : 0;
			p[j][i] = (u1+u2)%mod;
		}
	}


	
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);

		lint res = 0;
		FOR(l,k*(k+1)/2,n+1){
			lint u = (n-l+k>=0 ? b[n-l+k][k] : 0);
			res += (((p[l][k]*b[n-l+k][k])%mod)*fact[k])%mod;
			res = res%mod;
		}
		cout<<res<<endl;
	}
	
	






	
	return 0;
}