#include <cstdio>
#include <cassert>

using ll = long long;

const int MOD = 998244353;

struct mint
{
	public:
		int v;
		mint(int _v=0): v(_v)
		{
			if(v<-MOD || MOD <= v) v%=MOD;
			if(v<0) v+=MOD;
		}

		mint& operator += (const mint& o) {if((v+=o.v)>=MOD) v-=MOD; return *this;}
		mint& operator -= (const mint& o) {if((v-=o.v)<0) v+=MOD; return *this;}
		mint& operator *= (const mint& o) {v=(ll)v*o.v%MOD; return *this;}

		friend mint operator + (mint a, const mint& b) {return a+=b;}
		friend mint operator - (mint a, const mint& b) {return a-=b;}
		friend mint operator * (mint a, const mint& b) {return a*=b;}
};

const int MN = 2e5+10;
const int MM = 2e5+10;

mint inv[MN], F[2][MN], _p2[MN*2], *p2=_p2+MN;

void pcp()
{
	inv[1]=mint(1);
	for(int i=2;i<MN;++i)
		inv[i]=mint(MOD-MOD/i)*inv[MOD%i];
	F[0][0]=F[1][0]=mint(1);
	for(int i=1;i<MN;++i)
		F[0][i]=F[0][i-1]*mint(i), F[1][i]=F[1][i-1]*inv[i];
	p2[0]=mint(1);
	for(int i=1;i<MN;++i)
		p2[i]=p2[i-1]*mint(2), p2[-i]=p2[-i+1]*inv[2];
}

mint choose(int n, int k) {assert(0 <= k && k <= n); return F[0][n]*F[1][k]*F[1][n-k];}

struct chpfx
{
	public: 
		int n, k;
		mint val; // n choose i, i<=k
		chpfx(): n(0), k(0), val(1) {}

		void inc_nk()
		{
			val = val*mint(2)+choose(n+1, k+1)-choose(n, k); // or ch(n,k+1), allowing k>n
			++n, ++k;
		}
		void dec_nk()
		{
			assert(n>0 && k>0);
			val = (val-choose(n, k)+choose(n-1, k-1))*inv[2];
			--n, --k;
		}
		void inc_k()
		{
			assert(k<n);
			val += choose(n, k+1);
			++k;
		}
		void dec_k()
		{
			assert(k>0);
			val -= choose(n, k);
			--k;
		}
		void setk(int _k)
		{
			for(;k<_k;) inc_k();
			for(;k>_k;) dec_k();
		}
		void go(int _n, int _k)
		{
			if(_n<n)
			{
				setk(_k+n-_n);
				for(;n>_n;)
					dec_nk();
			}
			else
			{
				for(;n<_n;)
					inc_nk();
				setk(_k);
			}
		}
} cur_val;

int N, M, shift, qm;
char s[MN];

mint eval(int n, int k) // return [sum(choose(n, i))] for i = k, k-2, k-4, ..., (1 or 0)
{
	assert(0 <= k && k <= n);
	if(n==0) return mint(1); // special qm==1 case
	if(k==n) --k; //?

	cur_val.go(n-1, k);
	return cur_val.val;
}

mint answer() // by symmetry, we *can* just make shift positive, but I want it to work with negatives too
{
	//printf("%d %d\n", shift, qm);
	// sum over abs(i*2+shift-qm) * choose(qm, i) over all even i if shift-qm == 0 mod 4, otherwise over all odd i
	
	//signed: sum(i*2+shift-qm)*choose(qm, i) 
	//= 2*sum(i * choose(qm, i)) + (shift-qm) * sum(choose(qm, i))
	//= 2*qm*sum(choose(qm-1, i-1)) + ^^
	//= 2*qm*2^(qm-2) + (shift-qm)*2^(qm-1) [extra factor of 1/2 because choosing every other i coincidentally means dividing by 2]
	//= shift*2^(qm-1)
	mint ans=mint(shift)*p2[qm-1];
	if(qm==1)
		ans=(shift-qm)%4 == 0 ? mint(shift-1) : mint(shift+1); // edge case, because (0 choose even) = 1; doesnt satisfy the 1/2 factor rule

	//add back 2*negative
	//(i*2+shift-qm<0): i*2<qm-shift
	int i=(qm-shift)/2; // "i" will always be located at 0, so good
	if(i<=1) return ans; // 1 case: i==1 yields 0, i==0 would not be 2 mod 4

	if(i>qm) i -= i-qm+1>>1<<1;
	mint cnt = eval(qm, i);
	mint tot = i>0?mint(qm)*eval(qm-1, i-1):mint(0);

	//add 2*sum((qm-shift-2*i) * choose(qm, i))
	// = 2*(qm-shift)*sum(choose(qm, i)) - 4*(sum(i*choose(qm, i)))
	// = ...                             - 4*qm*sum(choose(qm-1, i-1))
	return ans + (mint(2*(qm-shift))*cnt - mint(4)*tot);
}

int main()
{
	pcp();
	scanf("%d%d %s", &N, &M, s);

	for(int i=0;i<N;++i)
		if(s[i]=='?')
			++qm;
		else
			shift += (s[i]=='b' ^ i&1)*2-1;

	printf("%d\n", answer()*p2[-1-qm]); // divide by 4 (len/4 = # crossings), divide by 2^(qm-1) (# of ok ways)
	for(int i=0;i<M;++i)
	{
		int x; scanf("%d", &x), --x;

		if(s[x]=='?') --qm;
		else shift -= (s[x]=='b' ^ x&1)*2-1;

		scanf(" %c", s+x);

		if(s[x]=='?') ++qm;
		else shift += (s[x]=='b' ^ x&1)*2-1;

		printf("%d\n", answer()*p2[-1-qm]);
	}

	return 0;
}