#include <bits/stdc++.h>
#define mod 1000000007
#define N 5050

using namespace std;
typedef long long LL;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

bool vis[N][N],ok[N][N];
int sum[N],n;
short dp[N][N];
int hash[N][N];
char s[N];

short F(int l,int r) {
	if (vis[l][r]) return dp[l][r];
	vis[l][r] = 1;
	short ret = ok[l][r] ? 1 : -n;
	if (l == r) {
		hash[l][r] = s[l]-'a'+1;
		dp[l][r] = 1;
		return 1;
	}
	
	int h = (r-l+1) >> 1;
	
	short p1 = F(l,l+h-1);
	short p2 = F(r-h+1,r);

	if (hash[l][l+h-1] == hash[r-h+1][r] && p1 == p2) ret = max(ret, (short)(p1+1));
	return dp[l][r] = ret;
}

int main() {
	scanf("%s",s+1); n = strlen(s+1);
	
	for (int j=1;j<=n;j++)
		for (int i=1;i+j-1<=n;i++) {
			int x = i+j-1;
			if (i==x) ok[i][x] = 1; else {
				if (i+1 == x) ok[i][x] = s[i]==s[x]; else {
					if (s[i] == s[x]) ok[i][x] = ok[i+1][x-1];
				}
			}
		}
		
	for (int j=1;j<=n;j++)
		for (int i=1;i+j-1<=n;i++) {
			int x = i+j-1;
			hash[i][x] = 1LL * hash[i][x-1] * 26 % mod + (s[x]-'a'+1);
			hash[i][x] %= mod;
		}
	
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++) if (F(i, j)>0)
			sum[ F(i,j) ]++;
	for (int i=n;i>=1;i--) sum[i] += sum[i+1];
	for (int i=1;i<=n;i++) printf("%d%c",sum[i],i==n?'\n':' ');
	return 0;
}