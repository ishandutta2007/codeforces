#include <cstdio>
#include <cstring>
#include <algorithm>

template<typename T> bool ckmax(T& a, T b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, T b) {return b<a?a=b,1:0;}

using ll = long long;
const int INF=2e9;
const ll INFL = 0x5555555555555556;
const ll SMV = INFL-1e17;

const int MN=5e5+10;
int N, M, a[MN], b[MN], c[MN];
ll p;
ll bit[MN], x;
void upd(int n, ll v)
{
	for(++n;n<=M+1;n+=-n&n)
		bit[n-1]+=v;
}
void upd(int l, int r, ll v)//[l,r)
{
	upd(l, v);
	upd(r, -v);
}
ll qry(int n)
{
	ll x=0;
	for(++n;n;n-=-n&n)
		x+=bit[n-1];
	return x;
}

int main(void)
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	for(int i=0;i<N;++i)
		scanf("%d", c+i), p+=c[i];
	scanf("%d", &M);
	for(int i=0;i<M;++i)
		scanf("%d", b+i);
	b[M]=INF;
	for(int i=0;i<N;++i)
	{
		int *k = std::lower_bound(b, b+M, a[i]);
		if(*k==a[i])
			a[i]=(k-b)+1;
		else
			a[i]=(b-k)-1;
	}

	upd(1, -INFL);
	for(int i=0,k;i<N;++i)
	{
		k=(a[i]<0?-a[i]:a[i])-1;
		if(c[i]>0 && k!=M)
			upd(k+1, c[i]);
		if(a[i] > 0 && (x=qry(k)) > -SMV)
			if((x+=c[i]-qry(k+1))>0)
				upd(k+1, k+2, x);
	}
	if((x=qry(M)) <= -SMV)
		printf("NO\n");
	else
		printf("YES\n%lld\n", p-x);
	return 0;
}