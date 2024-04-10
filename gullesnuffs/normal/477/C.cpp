#include <bits/stdc++.h>

using namespace std;

int stop[2005];

char s[2005], p[505];
int dp[2005][2005];

int main(){
	scanf("%s%s", s, p);
	int slen=strlen(s);
	for(int i=0; s[i]; ++i){
		int j=0;
		for(stop[i] = i; p[j] && stop[i] < slen; ++stop[i]){
			if(s[stop[i]] == p[j])
				++j;
		}
		if(p[j])
			stop[i] = -1;
	}
	int plen=strlen(p);
	for(int i=0; s[i]; ++i)
		for(int j=0; s[j]; ++j)
			dp[i][j]=-1000000;
	dp[0][0]=0;
	for(int i=0; s[i]; ++i){
		for(int j=0; s[j]; ++j){
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
			dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]);
			if(stop[i] != -1){
				int newj=stop[i]-i-plen+j;
				dp[stop[i]][newj]=max(dp[stop[i]][newj], dp[i][j]+1);
			}
		}
	}
	for(int i=0; i <= slen; ++i){
		printf("%d", dp[slen][i]);
		if(i < slen)
			printf(" ");
		else
			printf("\n");
	}
}