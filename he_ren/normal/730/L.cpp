#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline int mod_add(int a,int b){ return a+b >= mod? a+b-mod: a+b;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

ll pw10[MAXN];

inline int get_cid(char c){ return c >= '0' && c <= '9'? 0: c == '+' || c == '*'? 1: 2;}

char s[MAXN];
int lef[MAXN], rig[MAXN], lvl[MAXN];

int val[MAXN], pren[MAXN];
int pid[MAXN], psum[MAXN], pl[MAXN], pr[MAXN], pcnt = 0;
int nid[MAXN], nval[MAXN], nprod[MAXN], inprod[MAXN], nzero[MAXN], ncnt = 0;

inline int get_num(int l,int r)
{
	return s[r] == ')'? val[r]: mod_add(pren[r], mod - (ll)pren[l-1] * pw10[r-l+1] %mod);
}

inline int get_p(int l,int r)
{
	if(nid[l] == nid[r]) return get_num(l, r);
	int res = (ll)get_num(l, rig[l]) * get_num(lef[r], r) %mod;
	
	l = rig[l] + 2; r = lef[r] - 2;
	if(l > r || !res) return res;
	l = nid[l]; r = nid[r];
	
	if(nzero[r] - nzero[l-1] > 0) return 0;
	return (ll)res * nprod[r] %mod * inprod[l-1] %mod;
}

int build(int l,int r,int cur_lvl)
{
	vector<int> num, vs, ps;
	for(int i=l; i<=r; i=rig[i]+2)
	{
		num.push_back(i);
		if(s[i] == '(')
		{
			lvl[i] = lvl[rig[i]] = cur_lvl;
			val[i] = val[rig[i]] = build(i+1, rig[i]-1, i);
		}
		else
		{
			for(int j=i; j<=rig[i]; ++j)
				lvl[j] = cur_lvl;
		}
		vs.push_back(get_num(i, rig[i]));
	}
	ps.push_back(0);
	for(int i=1; i<(int)num.size(); ++i)
		if(s[num[i]-1] == '+') ps.push_back(i);
	ps.push_back((int)num.size());
	
	for(int i=0; i<(int)num.size(); ++i)
	{
		int nl = num[i], nr = rig[nl];
		nval[++ncnt] = vs[i];
		if(s[nl] == '(') nid[nl] = nid[nr] = ncnt;
		else for(int j=nl; j<=nr; ++j) nid[j] = ncnt;
	}
	
	int res = 0;
	for(int k=0; k+1<(int)ps.size(); ++k)
	{
		int il = ps[k], ir = ps[k+1] - 1, cur = 1;
		++pcnt;
		pl[pcnt] = num[il]; pr[pcnt] = rig[num[ir]];
		for(int i=il; i<=ir; ++i)
		{
			cur = (ll)cur * vs[i] %mod;
			int nl = num[i], nr = rig[nl];
			if(s[nl] == '(') pid[nl] = pid[nr] = pcnt;
			else for(int j=nl; j<=nr; ++j) pid[j] = pcnt;
		}
		psum[pcnt] = cur;
		add_mod(res, cur);
	}
	return res;
}

int main(void)
{
	pw10[0] = 1;
	for(int i=1; i<MAXN; ++i) pw10[i] = pw10[i-1] * 10 %mod;
	
	int n,Q;
	scanf("%s%d",s+2,&Q);
	n = strlen(s+2) + 2;
	s[1] = '('; s[n] = ')';
	
	stack<int> sta;
	for(int i=n; i>=1; --i)
	{
		if(get_cid(s[i]) == 0)
			rig[i] = get_cid(s[i+1])? i: rig[i+1];
		else if(s[i] == ')') rig[i] = i, sta.push(i);
		else if(s[i] == '(') rig[i] = sta.top(), sta.pop();
	}
	for(int i=1; i<=n; ++i)
	{
		if(get_cid(s[i]) == 0)
			lef[i] = get_cid(s[i-1])? i: lef[i-1];
		else if(s[i] == '(') lef[i] = i, sta.push(i);
		else if(s[i] == ')') lef[i] = sta.top(), sta.pop();
	}
	
	for(int i=1; i<=n; ++i)
		if(get_cid(s[i]) == 0)
			pren[i] = ((ll)pren[i-1] * 10 + (s[i] - '0')) %mod;
	
	val[1] = val[n] = build(2, n-1, 1);
	
	for(int i=1; i<=pcnt; ++i) add_mod(psum[i], psum[i-1]);
	nprod[0] = 1;
	for(int i=1; i<=ncnt; ++i)
	{
		nzero[i] = nzero[i-1] + !nval[i];
		nprod[i] = (ll)nprod[i-1] * max(nval[i], 1) %mod;
	}
	inprod[ncnt] = pw(nprod[ncnt], mod - 2);
	for(int i=ncnt-1; i>=0; --i) inprod[i] = (ll)inprod[i+1] * max(nval[i+1], 1) %mod;
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		++l; ++r;
		
		if(get_cid(s[l]) == 1 || get_cid(s[r]) == 1){ printf("-1\n"); continue;}
		if(s[l] == ')' || s[r] == '('){ printf("-1\n"); continue;}
		if(lvl[l] != lvl[r]){ printf("-1\n"); continue;}
		
//		for(int i=l; i<=r; ++i)
//			putchar(s[i]);
//		putchar('\n');
		
		if(nid[l] == nid[r])
		{
			printf("%d\n",get_num(l, r));
		}
		else if(pid[l] == pid[r])
		{
			printf("%d\n",get_p(l, r));
		}
		else
		{
			int res = mod_add(get_p(l, pr[pid[l]]), get_p(pl[pid[r]], r));
			l = pid[l] + 1; r = pid[r] - 1;
			if(l <= r) res = ((ll)res + psum[r] + mod - psum[l-1]) %mod;
			printf("%d\n",res);
		}
	}
	return 0;
}

/*
-  [l, r]?
	- s[l], s[r] != '*', '+'
	- s[l] != ')'
	- s[r] != '('
- ? lvl[i]  i 
	- lvl[l] == lvl[r]

- 
	- rig[i]  i 
	- 
	- 
	- ?
	- ?

- ?
	- rig[i]  i ?
	- pid[i]  i ?
	- nid[i]  i 
	- ?dfs 0  1  0 ?
	- ?dfs ?
*/