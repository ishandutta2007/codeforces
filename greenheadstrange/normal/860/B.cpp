#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define maxn 70005
using namespace std;
struct str
{
	int num;
	int l, id;
	bool operator < (const str &a)const
	{
		if(l != a.l) return l < a.l;
		return num < a.num;
	}
}p[maxn * 100], ans[maxn];
bool hv[maxn];
int pw[10];
int main()
{
	int cnt = 0;
	int n;
	scanf("%d", &n);
	pw[0] = 1;
	for(int j = 1; j < 10; j++)
		pw[j] = pw[j - 1] * 10;
	int ncnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int num;
		scanf("%d", &num);
		for(int l = 1; l <= 9; l++)
		{
			int nm[10];
			for(int j = 0; j < 10 - l; j++)
			{
				nm[j] = (num / pw[j]) % pw[l];
				bool flag = 0;
				for(int k = 0; k < j; k++)
					if(nm[k] == nm[j])
						flag = 1;
				if(flag) continue;
				p[ncnt].l = l, p[ncnt].id = i, p[ncnt].num = nm[j], ncnt++;
			}
		}
	}
	sort(p, p + ncnt);
	for(int i = 0; i < ncnt; )
	{
		
		int pl = i + 1;
		while(pl < ncnt && p[pl].l == p[i].l && p[pl].num == p[i].num)
			pl++;
		if(pl != i + 1) 
		{
			i = pl;
			continue;
		}
		if(!hv[p[i].id])
			hv[p[i].id] = 1, 
			ans[p[i].id] = p[i];
		i = pl;
	}
	for(int i = 1; i <= n; i++)
	{
		int otp[10];
		int ncnt = 0;
		while(ans[i].num)
			otp[ncnt] = ans[i].num % 10, 
			ans[i].num /= 10, 
			ncnt++;
		for(int j = ncnt; j < ans[i].l; j++)
			otp[j] = 0;
		for(int j = ans[i].l - 1; j >= 0; j--)
			printf("%d", otp[j]);
		printf("\n");
	}
	return 0;
}