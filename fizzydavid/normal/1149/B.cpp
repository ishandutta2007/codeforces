//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
//My i/o stream
struct fastio
{
	char s[100000];
	int it, len;
	fastio() {it=len=0;}
	inline char get()
	{
		if (it<len) return s[it++]; it=0;
		len=fread(s, 1, 100000, stdin);
		if (len==0) return EOF; else return s[it++];
	}
	bool notend()
	{
		char c=get();
		while (c==' '||c=='\n') c=get();
		if (it>0) it--;
		return c!=EOF;
	}
}_buff;
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putchar(' ')
#define putii(x,y) puti(x),puti(y)
#define putiii(x,y,z) putii(x,y),puti(z)
#define putsi(x) putnum(x),putchar('\n')
#define putsii(x,y) puti(x),putsi(y)
#define putsiii(x,y,z) putii(x,y),putsi(z)
inline ll getnum()
{
	ll r=0; bool ng=0; char c; c=_buff.get();
	while (c!='-'&&(c<'0'||c>'9')) c=_buff.get();
	if (c=='-') ng=1, c=_buff.get();
	while (c>='0'&&c<='9') r=r*10+c-'0', c=_buff.get();
	return ng?-r:r;
}
template <class T> inline void putnum(T x)
{
	if (x<0) putchar('-'), x=-x;
	register short a[20]={}, sz=0;
	while (x) a[sz++]=x%10, x/=10;
	if(sz==0) putchar('0');
	for (int i=sz-1; i>=0; i--) putchar('0'+a[i]);
}
inline char getreal() {char c=_buff.get(); while (c<=32) c=_buff.get(); return c;}
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
char s[100111];
int go[100111][26];
int n;
int dp[255][255][255];
int nA, nB, nC;
char sA[255], sB[255], sC[255];
void addA(char c)
{
	sA[++nA] = c;
	for (int i=nA; i<=nA; i++)
	{
		for (int j=0; j<=nB; j++)
		{
			for (int k=0; k<=nC; k++)
			{
				int &cur = dp[i][j][k];
				cur = n+2;
				if (i>0) cur = min(cur, go[dp[i-1][j][k]][sA[i]-'a']);
				if (j>0) cur = min(cur, go[dp[i][j-1][k]][sB[j]-'a']);
				if (k>0) cur = min(cur, go[dp[i][j][k-1]][sC[k]-'a']);
			}
		}
	}
}
void addB(char c)
{
	sB[++nB] = c;
	for (int i=0; i<=nA; i++)
	{
		for (int j=nB; j<=nB; j++)
		{
			for (int k=0; k<=nC; k++)
			{
				int &cur = dp[i][j][k];
				cur = n+2;
				if (i>0) cur = min(cur, go[dp[i-1][j][k]][sA[i]-'a']);
				if (j>0) cur = min(cur, go[dp[i][j-1][k]][sB[j]-'a']);
				if (k>0) cur = min(cur, go[dp[i][j][k-1]][sC[k]-'a']);
			}
		}
	}
}

void addC(char c)
{
	sC[++nC] = c;
	for (int i=0; i<=nA; i++)
	{
		for (int j=0; j<=nB; j++)
		{
			for (int k=nC; k<=nC; k++)
			{
				int &cur = dp[i][j][k];
				cur = n+2;
				if (i>0) cur = min(cur, go[dp[i-1][j][k]][sA[i]-'a']);
				if (j>0) cur = min(cur, go[dp[i][j-1][k]][sB[j]-'a']);
				if (k>0) cur = min(cur, go[dp[i][j][k-1]][sC[k]-'a']);
			}
		}
	}
}
int main()
{
	int q;
	scanf("%d%d", &n, &q);
	scanf("%s", s+1);
	
	for (int i=0; i<26; i++) go[n+2][i] = go[n+1][i] = n+2;
	for (int i=n; i>=1; i--)
	{
		for (int j=0; j<26; j++) go[i][j] = go[i+1][j];
		go[i][s[i]-'a'] = i+1;
	}
	dp[0][0][0] = 1;
	for (int i=1; i<=q; i++)
	{
		char cmd[10], s[10];
		int id;
		scanf("%s %d", cmd, &id);
		if (cmd[0]=='+')
		{
			scanf("%s", s);
			if (id==1) addA(s[0]);
			if (id==2) addB(s[0]);
			if (id==3) addC(s[0]);
		}
		else
		{
			if (id==1) nA--;
			if (id==2) nB--;
			if (id==3) nC--;
		}
		if (dp[nA][nB][nC]<=n+1) puts("YES"); else puts("NO");
	}
	return 0;
}