/*
x1=a*n ; x2=b*m
y1=b*n ; y2=a*m

a<b

l <= a*n*b*m <= r
(l+a*n-1)/(a*n) <= b*m <= r/(a*n)
b*m <= M

b*n <= M
a < b <= M/n

loop through all divisors of x1 to be 'a'
 * This is difficult to do

Instead:
 * loop through n = N ... 1
 * This way, the upper bound strictly is increasing
 * Maintain all 

*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

template<typename T> bool ckmax(T& a, const T& b) {return b>a?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

using ll = long long;

const int MN = 2e5+10;

struct ST
{
	public:
		int m[1<<19];
		void upd(int n, int l, int r, int q, int v)
		{
			if(r-l>1)
			{
				int m=l+(r-l)/2;
				if(q<m) upd(n<<1, l, m, q, v);
				else upd(n<<1|1, m, r, q, v);
				ST::m[n]=std::max(ST::m[n<<1], ST::m[n<<1|1]);
			}
			else
				ckmax(ST::m[n], v);
		}
		int qry(int n, int l, int r, int ql, int qr)
		{
			if(ql <= l&&r <= qr) return m[n];
			else
			{
				int m=l+(r-l)/2, f=0;
				if(ql<m) ckmax(f, qry(n<<1, l, m, ql, qr));
				if(m<qr) ckmax(f, qry(n<<1|1, m, r, ql, qr));
				return f;
			}
		}
};

int N, M, mb=1, A[MN], B[MN], C[MN];
ll L, R;
ST st;

int main()
{
	memset(A, -1, sizeof A);
	scanf("%d%d%lld%lld", &N, &M, &L, &R);
	for(int n=N;n>=1;--n)
	{
		for(;mb<=N/n;++mb)
			for(int i=1,mi=M/mb;i<=mi;++i)
				st.upd(1, 0, M, mb*i-1, mb);
		for(int i=1,mi=N/n;i<=mi;++i)
		{
			int a=i;
			int x1=a*n;
			//if(~A[x1]) continue;//some optimization if necessary
			ll lb=(L+x1-1)/x1, rb=std::min<ll>(R/x1, M);
			if(lb <= rb)
			{
				int b = st.qry(1, 0, M, (int)lb-1, (int)rb);
				//printf("[%lld, %lld]: %d\n", lb, rb, b);
				if(a < b)
					A[x1]=a, B[x1]=b, C[x1]=(int)rb/b;
			}
		}
	}
	for(int i=1;i<=N;++i)
	{
		if(~A[i])
		{
			int a=A[i], n=i/a, b=B[i], m=C[i];
			printf("%d %d %d %d\n", a*n, b*m, b*n, a*m);
		}
		else
			printf("-1\n");
	}
	return 0;
}