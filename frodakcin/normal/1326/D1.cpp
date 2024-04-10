#include <cstdio>
#include <algorithm>

const int MN = 1e6 + 100;
bool ckmax(int& a, int b) {return a<b?a=b,1:0;}

char s[MN];
int S;
int L;
int o[MN], e[MN];//even = left middle
void manacher()
{
	for(int i = 0, l, r = -1;i < S;++i)
	{
		o[i] = i < r ? std::min(o[l+(r-i)], r-i+1) : 1;
		//printf("BASE %d %d\n", i, o[i]);
		for(;i-o[i] >= 0 && i+o[i] < S && s[i-o[i]] == s[i+o[i]];++o[i]);
		if(i+o[i]-1 > r)
			l = i-o[i]+1, r = i+o[i]-1;
	}

	for(int i = 0, l, r = -1;i < S;++i)
	{
		e[i] = i < r ? std::min(e[l+(r-i-1)], r-i) : 0;
		for(;i-e[i] >= 0 && i+e[i]+1 < S && s[i-e[i]] == s[i+e[i]+1];++e[i]);
		if(i+e[i] > r)
			l = i-e[i]+1, r = i+e[i];
	}

	//for(int i = 0;i < S;++i) printf("MANA %d %d\n", o[i], e[i]);
}
int bo[MN], be[MN];
int ans, lv, rv;
void solve()
{
	scanf(" %s", s);
	for(S = 0;s[S];++S);
	for(L=0;L < S;++L)
		if(s[L] != s[S-L-1])
			break;
	if(L == S)
		return (void) printf("%s\n", s);
	manacher();

	ans = 0;
	for(int i = 0;i <= S;++i) bo[i] = be[i] = -1;
	//LEFT
	for(int i = 0;i < S/2;++i) bo[i-o[i]+1] = i;
	for(int i = 0;i < (S-1)/2;++i) if(e[i]) be[i-e[i]+1] = i;
	for(int i = 0;i <= L;++i)
	{
		if(i) bo[i] = std::max(bo[i-1], bo[i]);
		if(i) be[i] = std::max(be[i-1], be[i]);

		if(ckmax(ans, i*2 + (bo[i]-i)*2+1))
			lv = i + (bo[i]-i)*2+1, rv = S-i;
		if(~be[i] && ckmax(ans, i*2 + (be[i]-i+1)*2))
			lv = i + (be[i]-i+1)*2, rv = S-i;
	}

	for(int i = 0;i <= S;++i) bo[i] = be[i] = MN;
	//RIGHT
	for(int i = S-1;i >= (S+1)/2;--i) bo[i+o[i]-1] = i;
	for(int i = S-1;i >= S/2;--i) if(e[i]) be[i+e[i]] = i;
	for(int i = 0;i <= L;++i)
	{
		int k = S-i-1;
		bo[k] = std::min(bo[k+1], bo[k]);
		be[k] = std::min(be[k+1], be[k]);

		//printf("DBG %d %d\n", k, be[k]);
		if(ckmax(ans, i*2 + (k-bo[k])*2 + 1))
			lv = i, rv = k - (k-bo[k])*2;
		if(be[k] < MN && ckmax(ans, i*2 + (k-be[k])*2))
			lv = i, rv = k - (k-be[k])*2 + 1;
	}

	//printf("%d(%d)   %d %d\n", L, ans, lv, rv);
	//printf("%d\n", ans);
	s[lv] = 0;
	printf("%s%s\n", s, s+rv);
}

int T;
int main(void)
{
	scanf("%d", &T);
	for(;T--;)
		solve();
	return 0;
}

//aababbb