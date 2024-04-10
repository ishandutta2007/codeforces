#include <cstdio>
#include <cstring>
#include <cassert>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 55;
const int MK = 55;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, K, key[MN];
ll c[MK], l[MN], r[MN], mem[MK][MN][MN][4][4];

void get(int i, int x, bool& b, int& v)
{
	if(i>key[x])
		return b=l[x]>>i&1, v=0, void();
	if(i==key[x])
	{
		assert(!(v&1));
		return b=v>>1, v=0, void();
	}

	if(v>>1&1)
		b=r[x]>>i&1;
	else
		b=l[x]>>i&1;

	if(v&1)
		v^=1, b^=1;
}

ll dp(int i, int ql, int qr, int vl, int vr)
{
	if((vl&1 && (i>=key[ql] || (vl>>1&1 ? (r[ql]>>i&1)==0 : (l[ql]>>i&1)==1))) // if need boost and (key bit) or (bad value) then you can't boost
			|| (vr&1 && (i>=key[qr] || (vr>>1&1 ? (r[qr]>>i&1)==0 : (l[qr]>>i&1)==1)))) // unable to boost
		return INF;
	if(i==K) return 0;

	ll &f=mem[i][ql][qr][vl][vr];
	if(f!=-1) return f;
	f=INF;

	bool ok=1;
	//split
	for(int m=ql+1;m<qr;++m)
	{
		ckmin(f, dp(i, ql, m, vl, 1)+dp(i, m, qr, 1, vr)); // left, boost
		if(i==0) ckmin(f, dp(i, ql, m, vl, 0)+dp(i, m, qr, 0, vr)); // left, no boost (clone)
		ckmin(f, dp(i, ql, m, vl, 3)+dp(i, m, qr, 3, vr)); // right, boost
		ok &= i+1<key[m];
	}

	//shift
	if(ok)
	{
		bool lb,rb;
		get(i, ql, lb, vl);
		get(i, qr, rb, vr);
		ckmin(f, (ql>0 && qr<=N && lb != rb)*c[i] + dp(i+1, ql, qr, vl, vr));
	}

	return f;
}

int main()
{
	memset(mem, -1, sizeof mem);
	scanf("%d%d", &N, &K);
	l[0]=l[N+1]=0;
	r[0]=r[N+1]=1ll<<K;
	key[0]=key[N+1]=K;
	for(int i=1;i<=N;++i)
	{
		scanf("%lld%lld", l+i, r+i), ++r[i];
		key[i]=-1;
		for(int j=K;j>=0;--j)
			if((l[i]>>j&1) != (r[i]>>j&1))
			{
				key[i]=j;
				break;
			}
		//printf("%d: %d\n", i, key[i]);
		assert(key[i] >= 0);
	}
	for(int i=0;i<K;++i) scanf("%lld", c+i);

	printf("%lld\n", dp(0, 0, N+1, 0, 0));
	return 0;
}