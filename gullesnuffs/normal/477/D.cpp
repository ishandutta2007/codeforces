#include <bits/stdc++.h>
#define MOD 1000000007
#define HASHMOD 382918273847283129LL
using namespace std;

char x[5005];
int val[5005][5005];
int dp[5005][5005];
int order[5005];
int diff[5005][5005];
int common[5005];
int Min[5005][5005];
bitset<5005> b[5005];
int n;

struct Pos{
	int pos;

	bool operator< (const Pos &other) const{
		if(pos == other.pos)
			return 0;
		int p2=other.pos;
		for(int i=0; i < n; ++i){
			if(b[pos][i]^b[p2][i]) return b[p2][i];
		}
		return 0;
		/*int i=0;
		while(x[pos+i] == x[other.pos+i])++i;
		return x[pos+1] < x[other.pos+1];*/
	}
};

Pos p[5005];

int main(){
	scanf("%s", x);
	n=strlen(x);
	for(int i=0; i < n; ++i){
		p[i].pos=i;
		for(int j=i; j < n; ++j)
			if(x[j] == '1')
				b[i].set(j-i);
	}
	sort(p, p+n);
	for(int i=0; i < n; ++i){
		order[p[i].pos]=i;
		if(i < n-1){
			common[i]=0;
			while(x[p[i].pos+common[i]] == x[p[i+1].pos+common[i]])
				++common[i];
		}
	}
	for(int i=0; i < n; ++i){
		int P=0;
		for(int j=0; j < n; ++j){
			if(j)P=min(P, common[j-1]);
			if(p[j].pos == i){
				P = n-i;
			}
			else{
				while(x[i+P] == x[p[j].pos+P])
					++P;
			}
			diff[i][p[j].pos] = P;
		}
	}
	for(int i=0; i <= n; ++i)
		for(int j=0; j <= i; ++j)
			Min[i][j]=1000000;
	Min[0][0]=0;
	dp[0][0]=1;
	for(int i=0; x[i]; ++i){
		//if(x[i] == '0')
		//	continue;
		for(int j=0; j <= i; ++j){
			//j=len
			dp[i+1][j+1] += dp[i][j];
			dp[i+1][j+1] %= MOD;
			Min[i+1][j+1] = min(Min[i+1][j+1], Min[i][j]);
			if(j && i+j < n+3){
				if(x[i] == '0')
					continue;
				if(diff[i-j][i] >= j || x[i-j+diff[i-j][i]] == '0'){
					dp[i+j][j] += dp[i][j];
					dp[i+j][j] %= MOD;
					Min[i+j][j] = min(Min[i+j][j], Min[i][j]+1);
				}
				else{
					dp[i+j+1][j+1] += dp[i][j];
					dp[i+j+1][j+1] %= MOD;
					Min[i+j+1][j+1] = min(Min[i+j+1][j+1], Min[i][j]+1);
				}
			}
		}
	}
	int ways=0;
	for(int i=1; i <= n; ++i){
		ways += dp[n][i];
		ways%=MOD;
	}
	int ans=MOD+1;
	for(int i=1; i <= n; ++i){
		if(Min[n][i] >= 1000000)
			continue;
		int sum = Min[n][i]+1;
		int sum2=0;
		if(i > 20 && ans < MOD)
			break;
		for(int j=n-i; j < n; ++j){
			sum2 *= 2;
			if(x[j] == '1')
				++sum2;
			sum2 %= MOD;
		}
		sum += sum2;
		sum%=MOD;
		ans=min(ans, sum);
	}
	printf("%d\n%d\n", ways, ans);
}