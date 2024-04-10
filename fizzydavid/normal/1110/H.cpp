//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
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
const int maxn = 2011;
const int maxtot = 811*2;
char sl[maxtot], sr[maxtot];
int n, nl, nr, stl[maxtot], str[maxtot];
int go[maxtot][11], tot = 1, len[maxtot], fail[maxtot], fa[maxtot], fa_c[maxtot];
int fgo[maxtot][11];
int sgnl[maxtot], sgnr[maxtot];
int tab[maxtot][11][maxn];
int dp[maxn][maxtot];
void add_string(char s[], int st[])
{
	int p = 1;
	for (int i=1; s[i]; i++)
	{
		int &nxt = go[p][s[i]-'0'];
		if (!nxt)
		{
			nxt = ++tot;
			fa[nxt] = p;
			len[nxt] = len[p]+1;
			fa_c[nxt] = s[i]-'0';
		}
		p = nxt;
		st[i] = p;
	}
}
int q[maxn], qn;
int getsgn(int cur_sgn, int pattern_c, int cur_c)
{
	if (cur_sgn==0&&pattern_c!=cur_c) return cur_c>pattern_c?1:-1;
	else return cur_sgn;
}
pair<int,int> get_state(char s[], int l, int c)
{
	int p = 0;
	for (int i=0; i<l; i++)
	{
		if (!go[p][s[i]-'0']) return MP(p, s[i]-'0');
		else p = go[p][s[i]-'0'];
	}
	assert(!go[p][c]);
	return MP(p, c);
}
pair<int,int> get_next_state(pair<int,int> cur, int c)
{
	if (cur.SS!=-1) return cur;
	else
	{
		if (go[cur.FF][c]) return MP(go[cur.FF][c], -1);
		else return MP(cur.FF, c);
	}
}
void prework()
{
	qn = 0;
	q[qn++] = 1;
	for (int i=1; i<=nr; i++)
	{
		if (i<=nl) q[qn++] = stl[i];
		if (str[i]!=stl[i]) q[qn++] = str[i];
	}
	static int sgl[maxtot][11], sgr[maxtot][11];
	fail[1] = 1;
	for (int i=0; i<qn; i++)
	{
		int x = q[i];
		if (x==1||fa[x]==1) fail[x] = 1;
		else
		{
			int &f = fail[x];
			f = fail[fa[x]];
			while (f!=1&&!go[f][fa_c[x]]) f = fail[f];
			if (go[f][fa_c[x]]) f = go[f][fa_c[x]];
		}
		if (x>1)
		{
			if (len[x]<=nl) sgnl[x] = getsgn(sgnl[fa[x]], sl[len[x]]-'0', fa_c[x]); else sgnl[x] = sgnl[fa[x]];
			sgnr[x] = getsgn(sgnr[fa[x]], sr[len[x]]-'0', fa_c[x]);
		}
		for (int j=0; j<11; j++)
		{
			if (len[x]+1<=nl) sgl[x][j] = getsgn(sgnl[x], sl[len[x]+1]-'0', j); else sgl[x][j] = sgnl[x];
			if (len[x]+1<=nr) sgr[x][j] = getsgn(sgnr[x], sr[len[x]+1]-'0', j); else sgr[x][j] = sgnr[x];
		}
	}
//	for (int i=1; i<=tot; i++) cerr<<fa[i]<<","<<fa_c[i]<<" "; cerr<<endl;
//	for (int i=1; i<=tot; i++) cerr<<len[i]<<"   "; cerr<<endl;
//	for (int i=1; i<=tot; i++) cerr<<fail[i]<<"   "; cerr<<endl;
	
	
	static bool ptl[maxtot][11], ptr[maxtot][11];
	for (int i=0; i<qn; i++)
	{
		int x = q[i];
		for (int j=0; j<11; j++)
		{
			if (go[x][j]) continue;
			if (nl==nr)
			{
				ptl[x][j] = sgl[x][j]>=0&&sgr[x][j]<=0;
			}
			else
			{
				ptl[x][j] = sgl[x][j]>=0;
				ptr[x][j] = sgr[x][j]<=0;
			}
		}
	}
	static pair<int,int> st[maxtot][maxn];
	for (int i=0; i<qn; i++)
	{
		int x = q[i];
		for (int l=0; l<=n; l++) st[x][l] = MP(1, -1);
		if (x>1)
		{
			for (int l=1; l<=len[x]; l++) st[x][l] = get_next_state(st[fa[x]][l-1], fa_c[x]);
			if (fa_c[x]==0) st[x][1] = MP(-1, 1);
		}
//		cerr<<"x="<<x<<endl;
//		for (int l=1; l<=len[x]; l++) cerr<<st[x][l].FF<<","<<st[x][l].SS<<" ";
		for (int j=0; j<11; j++)
		{
			if (go[x][j]) continue;
			int p = x;
			while (p!=1&&!go[p][j]) p = fail[p];
			if (go[p][j]) p = go[p][j];
			fgo[x][j] = p;
//			cerr<<"fgo["<<x<<"]["<<j<<"]="<<fgo[x][j]<<endl;
			int *B = tab[x][j];
			if (nl+1<nr)
			{
				int C = 0;
				for (int l = len[p]; l<=len[x]; l++)
				{
					if (st[x][l].FF==-1||l==0&&j==0) continue;
					int cl = nl+1-l, cr = nr-l;
					if (cr<=0) C += cr-cl;
					else if (cl<=0) C += 0-cl, B[0]++, B[cr]--;
					else B[cl]++, B[cr]--;
				}
				for (int t=1; t<=n; t++) B[t] += B[t-1];
				B[0] += C;
			}
			
			for (int l = len[p]; l<=len[x]; l++)
			{
				if (st[x][l].FF==-1||l==0&&j==0) continue;
				pair<int,int> cur = get_next_state(st[x][l], j);
//				cerr<<"x="<<x<<" j="<<j<<" l="<<l<<" cur=("<<cur.FF<<","<<cur.SS<<") "<<ptl[cur.FF][cur.SS]<<ptr[cur.FF][cur.SS]<<endl;
				assert(cur.SS!=-1);
				if (ptl[cur.FF][cur.SS]) B[max(0, nl-l)]++;
				if (ptr[cur.FF][cur.SS]) B[max(0, nr-l)]++;
			}
//			for (int t=0; t<=n; t++) cerr<<B[t]<<" "; cerr<<endl;
			for (int t=1; t<=n; t++) B[t] += B[t-1];
//			for (int t=0; t<=n; t++) cerr<<B[t]<<" "; cerr<<endl;
		}
	}
	memset(dp, 200, sizeof(dp));
	for (int i=1; i<=tot; i++) dp[0][i] = tab[i][10][0];
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=tot; j++)
		{
			for (int c=0; c<10; c++)
			{
				if (go[j][c]) dp[i][j] = max(dp[i][j], dp[i-1][go[j][c]]);
				else dp[i][j] = max(dp[i][j], dp[i-1][fgo[j][c]]+tab[j][c][i]);
			}
		}
	}
	/*
	for (int i=0; i<=n; i++)
	{
		for (int j=1; j<=tot; j++) cerr<<dp[i][j]<<" "; cerr<<endl;
	}
	*/
}
int main()
{
	scanf("%s", sl+1);
	scanf("%s", sr+1);
	scanf("%d", &n);
	nl = strlen(sl+1);
	nr = strlen(sr+1);
	add_string(sl, stl);
	add_string(sr, str);
	prework();
	int p = 1;
	string ans;
	cout<<dp[n][1]<<endl;
	for (int i=n; i>=1; i--)
	{
		for (int c=0; c<10; c++)
		{
			if (go[p][c]&&dp[i-1][go[p][c]]==dp[i][p]||!go[p][c]&&dp[i-1][fgo[p][c]]+tab[p][c][i]==dp[i][p])
			{
				ans += (char)('0'+c);
				if (go[p][c]) p = go[p][c]; else p = fgo[p][c];
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}