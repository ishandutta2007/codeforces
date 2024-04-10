#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 
#define maxn 200005
using namespace std;
int n, k; 
int t[maxn];
int lenth[maxn], cnt = 0;
int main()
{
	scanf("%d%d", &n, &k);
	int bgpl = -1;
	int len = 0;
	int sum = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	for(int i = 0; i < n; i++)
		if(t[i] < 0)
		{
			bgpl = i;
			break;
		}
	if(bgpl == -1)
	{
		printf("0\n");
		return 0;
	}
	sum += bgpl;
	cnt = 0;
	for(int i = bgpl; i < n; i++)
	{
		if(t[i] < 0)
		{
			if(len) lenth[cnt++] = len, sum += len;	
			len = 0;
		} 
		else len++;
	}
	int lst = len;
	if(sum + k + lst < n)
	{
		printf("-1\n");
		return 0;	
	}	
	sort(lenth, lenth + cnt);
	int ans1, ans2; 
	if(lst)
	{
		int cgs = 2 * cnt + 2;
	
		int lsts = sum + k - n;	
		if(lsts < 0) ans1 = maxn;
		else
		{
			cgs--;
			for(int i = 0; i < cnt; i++)
				if(lenth[i] <= lsts)
					lsts -= lenth[i], cgs -= 2;
			ans1 = cgs;
		}
		cgs = 2 * cnt + 2;
		lsts = sum + k - n + lst;
		for(int i = 0; i < cnt; i++)
			if(lenth[i] <= lsts)
				lsts -= lenth[i], cgs -= 2;
		ans2 = cgs;
		printf("%d\n", min(ans1, ans2));
	}
	else
	{
		int cgs = 2 * cnt + 1;
		int lsts = sum + k - n ;
		for(int i = 0; i < cnt; i++)
			if(lenth[i] <= lsts)
				lsts -= lenth[i], cgs -= 2;
		printf("%d\n", cgs);
	}
	return 0;
}