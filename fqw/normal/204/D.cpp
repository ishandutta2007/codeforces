#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN=1000000+10;
const int MODNUM=1000000000+7;

int lall[MAXN], lt[MAXN], lc[MAXN];
int rall[MAXN], rt[MAXN], rc[MAXN];
char s[MAXN];
int n, k;

int main() {
	scanf("%d%d%s", &n, &k, s);
	for(int i=n; i>=1; --i) s[i]=s[i-1];

	lall[0]=1;
	for(int i=1; i<=n; ++i) lall[i]=(lall[i-1]*(s[i]=='X'?2:1))%MODNUM;
	for(int i=0; i<k; ++i) lc[i]=lt[i]=0;
	int cnt=0; for(int i=1; i<=k; ++i) cnt+=(s[i]=='W');
	lc[k]=lt[k]=(cnt==0);
	for(int i=k+1; i<=n; ++i) {
		cnt-=(s[i-k]=='W');
		cnt+=(s[i]=='W');
		if(cnt==0 && s[i-k]!='B') lc[i]=(lall[i-k-1]-lt[i-k-1]+MODNUM)%MODNUM;
			else lc[i]=0;
		lt[i]=(lt[i-1]*(s[i]=='X'?2:1)%MODNUM+lc[i])%MODNUM;
	}

	rall[n+1]=1;
	for(int i=n; i>=1; --i) rall[i]=(rall[i+1]*(s[i]=='X'?2:1))%MODNUM;
	for(int i=n+1; i>n-k+1; --i) rc[i]=rt[i]=0;
	cnt=0; for(int i=n; i>=n-k+1; --i) cnt+=(s[i]=='B');
	rc[n-k+1]=rt[n-k+1]=(cnt==0);
	for(int i=n-k; i>=1; --i) {
		cnt-=(s[i+k]=='B');
		cnt+=(s[i]=='B');
		if(cnt==0 && s[i+k]!='W') rc[i]=(rall[i+k+1]-rt[i+k+1]+MODNUM)%MODNUM;
			else rc[i]=0;
		rt[i]=(rt[i+1]*(s[i]=='X'?2:1)%MODNUM+rc[i])%MODNUM;
	}
	
	//for(int i=1; i<=n; ++i) printf("lc[%d]=%d lt[%d]=%d\n", i,lc[i],i,lt[i]);

	int ans=0;
	for(int i=1; i<n; ++i) ans=((long long)ans+(long long)lt[i]*(long long)rc[i+1])%MODNUM;
	printf("%d\n", ans);
	return 0;
}