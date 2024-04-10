#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N = 200005;
int tot_ask = 0;
int n, ans[N], state[N];
inline int Ask(int x, int y, int z)
{
	++tot_ask;
	printf("? %d %d %d\n", x, y, z);
	fflush(stdout);
	int ret = 0;
	scanf("%d", &ret);
	return ret;
}
inline void Solve()
{
	tot_ask = 0;
	n = read();
	int s_zero = 0, s_one = 0;
	For(i, 1, n / 3)
	{
		int x = (i - 1) * 3 + 1;
		state[i] = Ask(x, x + 1, x + 2);
	}
	For(i, 1, n / 3)
		if(state[i]) s_one = i;
		else s_zero = i;
	int x = (s_one - 1) * 3 + 1, y = (s_zero - 1) * 3 + 1;
	int zero = -1, one = -1;
	For(i, y, y + 2)
	{
		if(!Ask(x, x + 1, i)) 
			zero = i;
	}
	if(zero == -1)
	{
		one = x;
		ans[x] = ans[x + 1] = 1;

		if(!Ask(y, y + 1, x))  zero = y;
		if(!Ask(y, y + 2, x)) 	zero = y;
		if(!Ask(y + 1, y + 2, x)) zero = y+1;
	}
	else
	{
		if(Ask(x, x + 1, zero))  one = x;
		if(Ask(x, x + 2, zero)) 	one = x;
		if(Ask(x + 1, x + 2, zero)) one = x+1;
	}

	For(i, 1, n / 3)
	{
		if(state[i])
		{
			int x = (i - 1) * 3 + 1;
			int s12 = Ask(x, x + 1, zero);
			int s13 = Ask(x, x + 2, zero);
			if(s12 && s13) ans[x] = ans[x + 1] = ans[x + 2] = 1;
			else
			{
				if(s12) ans[x] = ans[x + 1] = 1, ans[x + 2] = 0;
				else 
				if(s13)	ans[x] = ans[x + 2] = 1, ans[x + 1] = 0;
				else 
						ans[x + 1] = ans[x + 2] = 1, ans[x] = 0;
			}
		}
		else
		{
			int x = (i - 1) * 3 + 1;
			int s12 = Ask(x, x + 1, one);
			int s13 = Ask(x, x + 2, one);
			if(!s12 && !s13) ans[x] = ans[x + 1] = ans[x + 2] = 0;
			else
			{
				if(!s12) ans[x] = ans[x + 1] = 0, ans[x + 2] = 1;
				else 
				if(!s13)	ans[x] = ans[x + 2] = 0, ans[x + 1] = 1;
				else 
						ans[x + 1] = ans[x + 2] = 0, ans[x] = 1;
			}
		}
	}
	int top = 0;
	For(i, 1, n)	if(!ans[i])	++top;
	putchar('!');
	printf(" %d", top);
	For(i, 1, n)	if(!ans[i])	printf(" %d",i);
	puts("");
	fflush(stdout);
	// writeln(tot_ask);
}
int main()
{
	int T = read();
	while(T--)
		Solve();
}
/*
1
6

0 0 1 0 1 1 
*/