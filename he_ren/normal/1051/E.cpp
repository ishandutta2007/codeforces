#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline int mod_add(int a,int b){ return a+b>=mod? a+b-mod: a+b;}

vector<int> getz(const string &s)
{
	int n = (int)s.size();
	vector<int> z(n);
	z[0] = n;
	for(int i=1,l=0,r=0; i<n; ++i)
	{
		if(i<r) z[i] = min(r-i, z[i-l]);
		while(i+z[i]<n && s[z[i]] == s[i+z[i]]) ++z[i];
		if(i+z[i] > r) l = i, r = i+z[i];
	}
	return z;
}

vector<int> getconn(char a[],char s[],int n,int sl)
{
	vector<int> z = getz(string(s+1,s+sl+1) + '$' + string(a+1,a+n+1));
	z.erase(z.begin(), z.begin()+sl+1);
	z.insert(z.begin(), 0);
	return z;
}

char a[MAXN], s[MAXN], t[MAXN];
int f[MAXN], suf[MAXN];

int main(void)
{
	scanf("%s%s%s",a+1,s+1,t+1);
	int n = strlen(a+1), sl = strlen(s+1), tl = strlen(t+1);
	
	vector<int> zs = getconn(a, s, n, sl);
	vector<int> zt = getconn(a, t, n, tl);
	
	f[n+1] = suf[n+1] = 1;
	for(int i=n; i>=1; --i)
	{
		if(a[i] == '0')
		{
			if(sl == 1 && s[1] == '0') f[i] = f[i+1];
			suf[i] = mod_add(f[i], suf[i+1]);
			continue;
		}
		
		int lef = sl+1, rig = min(n-i+1, tl-1);
		if(lef <= rig) f[i] = mod_add(suf[i+lef], mod - suf[i+rig+1]);
		
		bool flags = 0, flagt = 0;
		if(i+sl-1 <= n)
		{
			int len = zs[i];
			if(len == sl || a[i+len] >= s[1+len]) flags = 1;
		}
		if(i+tl-1 <= n)
		{
			int len = zt[i];
			if(len == tl || a[i+len] <= t[1+len]) flagt = 1;
		}
		
		if(sl == tl)
		{
			if(flags && flagt) add_mod(f[i], f[i+sl]);
		}
		else
		{
			if(flags) add_mod(f[i], f[i+sl]);
			if(flagt) add_mod(f[i], f[i+tl]);
		}
		
		suf[i] = mod_add(f[i], suf[i+1]);
	}
	printf("%d",f[1]);
	return 0;
}