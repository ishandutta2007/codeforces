#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 18 + 5;
const int ALL = (1<<18) + 5;

mt19937 rnd((unsigned long long)new char ^ time(0));

const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
const int base1 = (rnd() >> 1) % (mod1 / 10) + mod1 / 10;
const int base2 = (rnd() >> 1) % (mod2 / 10) + mod2 / 10;
const pii base = {base1, base2};

pii operator + (const pii &p,const pii &q)
{
	return {(p.first + q.first) %mod1, (p.second + q.second) %mod2};
}
pii operator * (const pii &p,const pii &q)
{
	return {(ll)p.first * q.first %mod1, (ll)p.second * q.second %mod2};
}

pii pwb[ALL];

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int n,all;
char s[ALL];

pii h[MAXN][ALL];

int main(void)
{
	pwb[0] = {1,1};
	for(int i=1; i<ALL; ++i) pwb[i] = pwb[i-1] * base;
	
	scanf("%d%s",&n,s);
	all = 1<<n;
	
	for(int i=0; i<all; ++i) h[0][i] = {s[i], s[i]};
	for(int i=1; i<=n; ++i)
		for(int j=0; j<all; ++j)
			h[i][j] = h[i-1][j] * pwb[bbit(i-1)] + h[i-1][j^bbit(i-1)];
	
	function<int(int,int,int)> cmp = [&] (int dep,int mask1,int mask2)
	{
		if(dep == 0)
			return s[mask1] < s[mask2]? -1: s[mask1] == s[mask2]? 0: 1;
		if(h[dep][mask1] == h[dep][mask2])
			return 0;
		
		int res = cmp(dep-1, mask1, mask2);
		if(res != 0) return res;
		else return cmp(dep-1, mask1 ^ bbit(dep-1), mask2 ^ bbit(dep-1));
	};
	
	int ans = 0;
	for(int i=1; i<all; ++i)
		if(cmp(n, i, ans) < 0) ans = i;
	for(int i=0; i<all; ++i)
		putchar(s[i ^ ans]);
	return 0;
}