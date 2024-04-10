#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <algorithm>

template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}
template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}

const int MN = 85;
const int INF = 0x3f3f3f3f;

int N, M, a[MN], dp[MN][MN*MN];

template<typename T>
T divf(T n, T d)
{
	if(d<0) n*=-1,d*=-1;
	return n<0?-((-n+d-1)/d):n/d;
}

//min mono cht
struct Line
{
	public:
		int m, b;
		mutable int r;
		Line(int _m=1, int _b=1, int _r=-1) :m(_m), b(_b), r(_r) {}
		int operator * (const Line& o) const
		{
			if(m==o.m) return o.b < b ? -INF : INF;
			return divf(b-o.b,o.m-m);
		}
		int operator [] (const int& x) const {return m*x+b;}
};

//m nonincreasing, x nondecreasing
struct CHT : public std::deque<Line>
{
	public:
		bool upd(Line& a, const Line& b) {return (a.r=a*b)>=b.r;}
		void ins(Line l)
		{
			l.r=INF;
			if(!empty() && upd(back(), l)) return;//this should never trigger; no equality for m
			if(!empty())
			{
				Line b=back(); pop_back();
				for(upd(b, l);!empty() && upd(back(), b);)
					b=back(), pop_back(), upd(b, l);
				push_back(b);
			}
			push_back(l);
		}
		int operator [] (const int& x)
		{
			if(empty()) return INF;
			for(;front().r < x;pop_front());
			return front()[x];
		}
};

CHT cht[MN*MN];

//[i*i+3*i] + [-2*i]*j + j*j-3*j+2
int main()
{
	scanf("%d", &N);
	for(int i=0, x;i<N;++i)
	{
		scanf("%d", &x);
		if(x)
			a[M++]=i+1;
	}
	a[M++]=N+1;
	memset(dp, 0x3f, sizeof dp);
	dp[0][0]=0;
	for(int i=0;i<M;++i)
	{
		for(int k=0;k<=N*(N-1)/2;++k)
			cht[k].clear();
		for(int j=0;j<=N+1;++j)
		{
			for(int k=0;k<=N*(N-1)/2;++k)
			{
				int val = dp[j][k], d=std::abs(j-a[i]);
				if(k>=d) dp[j][k]=cht[k-d][j];
				else dp[j][k]=INF;
				if(dp[j][k]<INF) dp[j][k]+=j*j-3*j+2;
				if(val < INF)
					cht[k].ins({-2*j, val+j*j+3*j});
			}
		}
	}
	int sum=(N-M+1)*(N-M);
	for(int i=0;i<=N*(N-1)/2;++i)
	{
		printf("%d%c", (sum-dp[N+1][i])/2, " \n"[i==N*(N-1)>>1]);
		ckmin(dp[N+1][i+1], dp[N+1][i]);
	}
	return 0;
}