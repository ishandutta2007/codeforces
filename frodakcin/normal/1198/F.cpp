#include <cstdio>
#include <vector>

const int MN = 1e5 + 100;
const int MK = 9;
int N, a[MN], K;

int gcd(int x, int y) {return x?gcd(y%x,x):y;}

std::vector<int> factorize(int n)
{
	std::vector<int> r;
	for(int i = 2;i*i <= n;i++)
	{
		if(n%i==0)
			r.push_back(i), n/=i;
		while(n%i==0)
			n/=i;
	}
	if(n>1) r.push_back(n);
	return r;
}
std::vector<int> v[2];
bool c[MN];
int dp[MK*MK*2][1<<MK][1<<MK], id[MK*MK*2];
int u[2][MK], k[2], z[2];
int t[2], C, q;

int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;i++) scanf("%d", a+i);
	v[0]=factorize(a[0]);
	a[0] = 1;
	for(int x : v[0]) a[0] *= x;
	k[0] = v[0].size();
	c[0] = 1;
	q = a[0];
	for(;q>1;)
	{
		int s = -1;
		for(int i = 1;i < N;i++)
			if(!c[i] && gcd(q, a[i]) < q)
			{
				s = i;
				break;
			}
		if(!~s) return printf("NO\n"), 0;
		v[0] = factorize(q); k[0] = v[0].size();
		v[1] = factorize(a[s]); k[1] = v[1].size();
		K = k[0]+k[1];
		for(int i = 0;i < 2;i++) for(int j = 0;j < k[i];j++) u[i][j] = 0;
		for(int i = 0;i < 1<<k[0];i++) for(int j = 0;j < 1<<k[1];j++) dp[0][i][j] = -1;
		dp[0][0][0] = 0;
		C = 0;
		for(int i = 1;i < N;i++)
		{
			if(c[i] || i == s) continue;
			bool e = 0;
			t[0] = t[1] = 0;
			for(int j = 0;j < 2;j++)
				for(int k = 0;k < v[j].size();k++)
					if(a[i]%v[j][k])
					{
						t[j]|=1<<k;
						if(++u[j][k] <= K)
							e = 1;
					}
			if(e)
			{
				id[C] = i;
				for(int j = 0;j < 1<<k[0];j++)
					for(int l = 0;l < 1<<k[1];l++)
						dp[C+1][j][l] = -1;
				for(int j = 0;j < 1<<k[0];j++)
					for(int l = 0;l < 1<<k[1];l++)
						if(~dp[C][j][l])
							dp[C+1][j|t[0]][l] = j<<1, dp[C+1][j][l|t[1]] = l<<1|1;
				C++;
			}
		}
		if(!C) return printf("NO\n"), 0;
		z[0] = (1<<k[0])-1, z[1] = (1<<k[1])-1;
		if(~dp[C][z[0]][z[1]])
		{
			for(;C;--C)
			{
				int v = dp[C][z[0]][z[1]];
				z[v&1]=v>>1;
				if(!(v&1))
					c[id[C-1]] = 1;
			}
			printf("YES\n");
			for(int i = 0;i < N;i++)
				printf("%d%c", c[i]+1, "\n "[i<N-1]);
			return 0;
		}
		else
			c[s] = 1, q = gcd(q, a[s]);
	}
	int f = 0;
	for(int i = 0;i < N;i++)
		if(!c[i])
			f = gcd(f, a[i]);
	if(f==1)
	{
		printf("YES\n");
		for(int i = 0;i < N;i++)
			printf("%d%c", c[i]+1, "\n "[i<N-1]);
	}
	else
		printf("NO\n");
	return 0;
}