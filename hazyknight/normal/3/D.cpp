#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
 
using namespace std;

const int MAXN = 50004;

int n,cnt,a,b;

long long ans;

char s[MAXN];

priority_queue<pair<int,int> > Q;
 
int main()
{
	scanf("%s",s);
	n = strlen(s);
	for (int i = 0;i < n;i++)
	{
		if (s[i] == '(')
			cnt++;
		if (s[i] == ')')
			cnt--;
		if (s[i] == '?')
		{
			scanf("%d%d",&a,&b);
			ans += b;
			Q.push(make_pair(b - a,i));
			s[i] = ')';
			cnt--;
		}
		if (cnt < 0)
		{
			if (Q.empty())
			{
				puts("-1");
				return 0;
			}
			ans -= Q.top().first;
			s[Q.top().second] = '(';
			Q.pop();
			cnt += 2;
		}
	}
	if (cnt)
	{
		puts("-1");
		return 0;
	}
	printf("%lld\n",ans);
	for (int i = 0;i < n;i++)
		putchar(s[i]);
	putchar('\n');
	return 0;
}