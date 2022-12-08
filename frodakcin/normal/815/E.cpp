#include <cstdio>
#include <cassert>
#include <functional>

using ll = long long;

ll N, K, min, max, num[100][2], cmax[100][2], cmin[100][2], ctot[100][2];//0=min,1=max
int layer;

void carrym(int l, bool a, bool b)
{
	cmin[l][a] += cmin[l+1][b];
	cmax[l][a] += cmax[l+1][b];
}
void edge()
{
	num[layer][0] = ctot[layer][0] = min;
	num[layer][1] = ctot[layer][1] = max;
	for(int i=layer-1;i>=0;--i)
	{
		if(num[i][0]-1>>1==num[i+1][0]) ctot[i][0] += ctot[i+1][0]; else ctot[i][0] += ctot[i+1][1];
		if(num[i][0]>>1==num[i+1][0]) ctot[i][0] += ctot[i+1][0]; else ctot[i][0] += ctot[i+1][1];
		if(num[i][1]-1>>1==num[i+1][0]) ctot[i][1] += ctot[i+1][0]; else ctot[i][1] += ctot[i+1][1];
		if(num[i][1]>>1==num[i+1][0]) ctot[i][1] += ctot[i+1][0]; else ctot[i][1] += ctot[i+1][1];
	}
	K -= (1LL<<layer)-1;
	std::function<void(int,ll,ll)> dfs=[&](int n, ll l, ll r)
	{
		ll m=l+(r-l-1)/2;
		//printf("%d: %lld %lld %lld (%lld)\n", n, l, m, r, K);
		if(n==layer)
		{
			assert(K==1||K==2);
			if(K==1) printf("%lld\n", m);
			else printf("%lld\n", m+1);
			return;
		}
		bool lb=m-l!=num[n+1][0];
		if(K>ctot[n+1][lb]) K-=ctot[n+1][lb], dfs(n+1, m+1, r);
		else dfs(n+1, l, m);
	};
	dfs(0, 2, N);
}
void edge2()//2-3
{
	num[layer][0]=min, num[layer][1]=max;
	cmax[layer][1]=1;
	for(int i=layer-1;i>=0;--i)
	{
		if(num[i][0]-1>>1==num[i+1][0]) cmax[i][0]+=cmax[i+1][0]; else cmax[i][0]+=cmax[i+1][1];
		if(num[i][0]>>1==num[i+1][0]) cmax[i][0]+=cmax[i+1][0]; else cmax[i][0]+=cmax[i+1][1];
		if(num[i][1]-1>>1==num[i+1][0]) cmax[i][1]+=cmax[i+1][0]; else cmax[i][1]+=cmax[i+1][1];
		if(num[i][1]>>1==num[i+1][0]) cmax[i][1]+=cmax[i+1][0]; else cmax[i][1]+=cmax[i+1][1];
	}
	K -= (1LL<<layer)-1;
	if(K > cmax[0][0])
	{
		K-=cmax[0][0];//2-(3->1,1) case
		std::function<void(int,ll,ll)> dfs=[&](int n, ll l, ll r)
		{
			ll m=l+(r-l-1)/2;
			if(n==layer) return (void) printf("%lld\n", K==1?l:r-1);
			if(K>1LL<<layer-n) K-=1LL<<layer-n, dfs(n+1, m+1, r);
			else dfs(n+1, l, m);
		};
		dfs(0, 2, N);
	}
	else
	{
		//pick 3
		std::function<void(int,ll,ll)> dfs=[&](int n, ll l, ll r)
		{
			ll m=l+(r-l-1)/2;
			if(n==layer) return (void) printf("%lld\n", m);
			bool lb=m-l!=num[n+1][0];
			if(K>cmax[n+1][lb]) K-=cmax[n+1][lb], dfs(n+1, m+1, r);
			else dfs(n+1, l, m);
		};
		dfs(0, 2, N);
	}
}
int main()
{
	scanf("%lld%lld", &N, &K);
	if(K==1) return printf("1\n"), 0;
	if(K==2) return printf("%lld\n", N), 0;
	K-=2;
	layer = 63-__builtin_clzll(K);
	assert(K>>layer&1 && K<1LL<<layer+1);
	min = max = N-2;
	for(int i=0;i<layer;++i)
	{
		num[i][0] = min, num[i][1] = max;
		min = min-1>>1, max>>=1;
		if(max == 2)//1-2 edge case
		{
			layer = i+1;
			edge();
			return 0;
		}
		if(min == 2)//2-3 edge case
		{
			layer = i+1;
			edge2();
			return 0;
		}
	}
	K -= (1LL<<layer)-1;

	num[layer][0] = min, num[layer][1] = max;
	assert(min == max || min+1 == max);

	ctot[layer][0] = ctot[layer][1] = cmax[layer][1] = cmin[layer][0] = 1;
	for(int i=layer-1;i>=0;--i)
	{
		carrym(i, 0, num[i][0]-1>>1!=num[i+1][0]);
		carrym(i, 0, num[i][0]>>1!=num[i+1][0]);
		carrym(i, 1, num[i][1]-1>>1!=num[i+1][0]);
		carrym(i, 1, num[i][1]>>1!=num[i+1][0]);

		ctot[i][0] = cmin[i][0] + cmax[i][0];
		ctot[i][1] = cmin[i][1] + cmax[i][1];
	}

	if(min==max||min&1)//equality or odd/even: left -> right
	{
		std::function<void(int, ll, ll)> dfs=[&](int n, ll l, ll r) //layer, l, r (inc, exc)
		{
			ll m=l+(r-l-1)/2;
			if(n==layer)
				return (void) printf("%lld\n", m);
			//(l, m)
			//(m+1, r)
			bool bl = m-l!=num[n+1][0];//big left;
			if(K > ctot[n+1][bl]) K -= ctot[n+1][bl], dfs(n+1, m+1, r);
			else dfs(n+1, l, m);
		};//this can be done iterative with for loop too. I might rewrite it like that in a bit
		dfs(0, 2, N);
	}
	else//even/odd: odd before even, odd is the larger one
	{
		if(K > cmax[0][0])//even = smaller
		{
			K -= cmax[0][0];
			std::function<void(int, ll, ll)> dfs=[&](int n, ll l, ll r)
			{
				ll m=l+(r-l-1)/2;
				if(n==layer)
					return (void) printf("%lld\n", m);
				bool bl = m-l!=num[n+1][0];
				if(K > cmin[n+1][bl]) K-=cmin[n+1][bl], dfs(n+1, m+1, r);
				else dfs(n+1, l, m);
			};
			dfs(0, 2, N);
		}
		else//odd = larger
		{
			std::function<void(int, ll, ll)> dfs=[&](int n, ll l, ll r)
			{
				ll m=l+(r-l-1)/2;
				if(n==layer)
					return (void) printf("%lld\n", m);
				bool bl = m-l!=num[n+1][0];
				if(K > cmax[n+1][bl]) K-=cmax[n+1][bl], dfs(n+1, m+1, r);
				else dfs(n+1, l, m);
			};
			dfs(0, 2, N);
		}
	}
}