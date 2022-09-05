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
const int mod=1e9+7;
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
int ANS, n, m;
vector<vector<int> > ANSG;
bool ANS_rev;
void solve(int n, int m, vector<vector<int>> &G, bool rev)
{
	int p[4] = {0, 1, 2, 3};
	do
	{
		int cur = 0;
		for (int i=0; i<n; i++)
		{
			int cur1 = 0, cur2 = 0;
			for (int j=0; j<m; j++)
			{
				int c = (i&1?(j&1?p[0]:p[1]):(j&1?p[2]:p[3]));
				cur1 += c!=G[i][j];
			}
			for (int j=0; j<m; j++)
			{
				int c = (i&1?(j&1?p[1]:p[0]):(j&1?p[3]:p[2]));
				cur2 += c!=G[i][j];
			}
			cur += min(cur1, cur2);
		}
		if (cur<ANS)
		{
			ANS = cur;
			vector<vector<int> > curG;
			for (int i=0; i<n; i++)
			{
				int cur1 = 0, cur2 = 0;
				for (int j=0; j<m; j++)
				{
					int c = (i&1?(j&1?p[0]:p[1]):(j&1?p[2]:p[3]));
					cur1 += c!=G[i][j];
				}
				for (int j=0; j<m; j++)
				{
					int c = (i&1?(j&1?p[1]:p[0]):(j&1?p[3]:p[2]));
					cur2 += c!=G[i][j];
				}
				vector<int> V;
				if (cur1<cur2)
				{
					for (int j=0; j<m; j++)
					{
						int c = (i&1?(j&1?p[0]:p[1]):(j&1?p[2]:p[3]));
						V.PB(c);
					}
				}
				else
				{
					for (int j=0; j<m; j++)
					{
						int c = (i&1?(j&1?p[1]:p[0]):(j&1?p[3]:p[2]));
						V.PB(c);
					}
				}
				curG.PB(V);
			}
			ANSG = curG;
			ANS_rev = rev;
		}
	} while(next_permutation(p, p+4));
}
vector<vector<int>> G1, G2;
int mp[256];
string S = "AGCT";
int main()
{
	ANS = 1e9;
	mp['A'] = 0;
	mp['G'] = 1;
	mp['C'] = 2;
	mp['T'] = 3;
	getii(n, m);
	vector<int> tmp;
	tmp.resize(m);
	for (int i=0; i<n; i++) G1.PB(tmp);
	tmp.resize(n);
	for (int i=0; i<m; i++) G2.PB(tmp);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			char c = getreal();
			int x = mp[c];
			G1[i][j] = x;
			G2[j][i] = x;
		}
	}
	solve(n, m, G1, 0);
	solve(m, n, G2, 1);
	if (!ANS_rev)
	{
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				putchar(S[ANSG[i][j]]);
			}
			puts("");
		}
	}
	else
	{
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				putchar(S[ANSG[j][i]]);
			}
			puts("");
		}
	}
	return 0;
}