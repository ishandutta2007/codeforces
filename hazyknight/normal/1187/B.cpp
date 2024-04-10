#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 200005;

int n,m,ans;
int cnt[26];

char s[MAXN];

vector<int> pos[26];

int main()
{
	scanf("%d%s",&n,s + 1);
	for (int i = 0;i < 26;i++)
		pos[i].push_back(0);
	for (int i = 1;i <= n;i++)
		pos[s[i] - 'a'].push_back(i);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%s",s + 1);
		n = strlen(s + 1);
		memset(cnt,0,sizeof(cnt));
		for (int i = 1;i <= n;i++)
			cnt[s[i] - 'a']++;
		ans = 0;
		for (int i = 0;i < 26;i++)
			ans = max(ans,pos[i][cnt[i]]);
		printf("%d\n",ans);
	}
	return 0;
}