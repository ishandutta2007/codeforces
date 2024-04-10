#include <bits/stdc++.h>
#define MOD 1000000007LL

using namespace std;

char s[100005];
char t[100005];
int a[100005];
bool good[100005];
long long dp[100005][2];
int nxGood[100005];
int prGood[100005];
long long sum[100005];
int usedPrev;

int main(){
	scanf("%s%s", s, t);
	a[0]=-1;
	a[1]=0;
	int tlen=strlen(t);
	for(int i=1; t[i-1]; ++i){
		a[i+1]=a[i];
		while(a[i+1] != -1 && t[i] != t[a[i+1]])
			a[i+1]=a[a[i+1]];
		++a[i+1];
	}
	int pos=0;
	for(int i=0; s[i]; ++i){
		while(pos != -1 && s[i] != t[pos])
			pos=a[pos];
		++pos;
		if(pos == tlen){
			good[i-tlen+1]=1;
		}
	}
	nxGood[strlen(s)]=-1;
	for(int i=strlen(s)-1; i >= 0; --i){
		if(good[i])
			nxGood[i]=i;
		else
			nxGood[i]=nxGood[i+1];
	}
	int slen=strlen(s);
	prGood[0]=-1;
	if(good[0])
		prGood[0]=0;
	for(int i=1; i < slen; ++i){
		if(good[i])
			prGood[i]=i;
		else
			prGood[i]=prGood[i-1];
	}
	if(nxGood[0] == -1){
		puts("0");
		return 0;
	}
	sum[0]=1;
	dp[0][0]=1;
	usedPrev=0;
	for(long long i=0; i < slen; ++i){
		if(good[i]){
			usedPrev=(sum[i]-usedPrev+MOD)%MOD;
			dp[i+tlen][1]=(dp[i+tlen][1]+sum[i]+MOD)%MOD;
			if(i && prGood[i-1] != -1)
				dp[i+tlen][1]=(dp[i+tlen][1]+MOD-sum[prGood[i-1]])%MOD;
		}
		dp[i+1][1]=(dp[i+1][1]+dp[i][1])%MOD;
		dp[i+1][0]=(dp[i+1][0]+dp[i][0]+dp[i][1])%MOD;
		sum[i+1]=(sum[i]+dp[i+1][0]+dp[i+1][1])%MOD;
	}
	int ans=(dp[slen][0]+dp[slen][1]-1+MOD)%MOD;
	printf("%d\n", ans);
}