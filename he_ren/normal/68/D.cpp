#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;

map<int,int> sum;
inline int get_sum(int x){ return sum.find(x) == sum.end()? 0: sum[x];}

int main(void)
{
	int h,Q;
	scanf("%d%d",&h,&Q);
	
	while(Q--)
	{
		static char s[10];
		scanf("%s",s+1);
		if(s[1] == 'a')
		{
			int u,x;
			scanf("%d%d",&u,&x);
			while(u) sum[u] += x, u>>=1;
			continue;
		}
		
		#define ls(u) ((u)<<1)
		#define rs(u) ((u)<<1|1)
		
		ldb ans = 0, coef = 1;
		int u = 1, cur = sum[1], mx = 0;
		while(1)
		{
			if(!cur || u >= (1<<h)){ ans += coef * max(cur, mx); break;}
			int l = get_sum(ls(u)), r = get_sum(rs(u));
			
			coef /= 2;
			bool canl = 1, canr = 1;
			if(l <= max(mx, cur - l)) ans += coef * max(mx, cur - l), canl = 0;
			if(r <= max(mx, cur - r)) ans += coef * max(mx, cur - r), canr = 0;
			if(!canl && !canr) break;
			
			if(canl)
				mx = max(mx, cur - l), u = ls(u), cur = l;
			else
				mx = max(mx, cur - r), u = rs(u), cur = r;
		}
		
		printf("%.20lf\n",(double)ans);
	}
	return 0;
}