#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

template<typename T> bool ckmin(T& a, T b){return b<a?a=b,1:0;}

using ll = long long;
const int MN = 1e5+10;//BOUNDS
const ll INF = 0x3f3f3f3f3f3f3f3f;
int N, M, K, G, x[MN], y[MN], X, Y, D;
ll f[MN], T;
std::vector<int> d1[MN*2], d2[MN*2];

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	memset(f, 0x3f, sizeof f);
	for(int i=0;i<K;++i)
	{
		scanf("%d%d", x+i, y+i);
		d2[x[i]+y[i]].push_back(i);
		d1[x[i]-y[i]+MN].push_back(i);
	}
	for(;;)
	{
		if(D==0)//+X, +Y
		{
			for(auto x:d1[X-Y+MN])
				ckmin(f[x], ::x[x]-X+T);
			if(N-X > M-Y)
			{
				T += M-Y;
				X += M-Y;
				Y = M;
				D = 3;
			}
			else if(N-X < M-Y)
			{
				T += N-X;
				Y += N-X;
				X = N;
				D = 1;
			}
			else break;
		}
		else if(D==1)//-X, +Y
		{
			for(auto x:d2[X+Y])
				ckmin(f[x], X-::x[x]+T);
			if(X > M-Y)
			{
				T += M-Y;
				X -= M-Y;
				Y = M;
				D = 2;
			}
			else if(X < M-Y)
			{
				T += X;
				Y += X;
				X = 0;
				D = 0;
			}
			else break;
		}
		else if(D==2)//-X, -Y
		{
			for(auto x:d1[X-Y+MN])
				ckmin(f[x], X-::x[x]+T);
			if(X > Y)
			{
				T += Y;
				X -= Y;
				Y = 0;
				D = 1;
			}
			else if(X < Y)
			{
				T += X;
				Y -= X;
				X = 0;
				D = 3;
			}
			else break;
		}
		else if(D==3)//+X, -Y
		{
			for(auto x:d2[X+Y])
				ckmin(f[x], ::x[x]-X+T);
			if(N-X > Y)
			{
				T += Y;
				X += Y;
				Y = 0;
				D = 0;
			}
			else if(N-X < Y)
			{
				T += N-X;
				Y -= N-X;
				X = N;
				D = 2;
			}
			else break;
		}
	}
	for(int i=0;i<K;++i)
		if(f[i]<INF) printf("%lld\n", f[i]);
		else printf("-1\n");
	return 0;
}