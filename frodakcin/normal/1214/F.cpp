#include <cstdio>
#include <algorithm>

using namespace std;

using ll = long long;
const int MN = 2e5 + 100;

int N, M;
ll F = 1e18, f;
ll p[MN*3];//equality = b-a
int g;
struct W
{
public:
	ll v; int i;
	void in(int i) {scanf("%lld", &v); W::i=i;}
	bool operator < (W o) const {return v < o.v;}
	bool operator < (ll x) const {return v < x;}
} A[MN], B[MN];
bool operator < (ll x, W y) {return x < y.v;}
int z[MN];

int main(void)
{
	scanf("%d%d", &M, &N);
	for(int i = 0;i < N;++i) A[i].in(i);
	for(int i = 0;i < N;++i) B[i].in(i);
	sort(A, A+N), sort(B, B+N);
	for(int i = 0;i < N;++i)
	{
		p[0] += M-A[i].v;
		p[i+1] -= M;
		p[i+N-(std::lower_bound(B, B+N, A[i].v)-B)+1] += A[i].v*2;
		p[i+N+1] += M;
	}
	for(int i = 0;i < N;++i)
		p[0] += B[i].v, p[N-i+(std::upper_bound(A, A+N, B[i].v)-A)]-=B[i].v*2;
	for(int i = 0;i <= N*2;++i) 
		if((f+=p[i])<F)
			F=f, g=i;
	printf("%lld\n", F);
	for(int i = 0;i < N;++i)
		z[A[i].i] = B[(i+N*4-g)%N].i;
	for(int i = 0;i < N;i++)
		printf("%d%c", z[i]+1, " \n"[i==N-1]);
	return 0;
}