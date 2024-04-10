#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
using namespace std;
char t[maxn], p[maxn];
int lfr[maxn], led[maxn];
int del[maxn];
int n, m;
int ndel[maxn];
int ans[maxn];
int cnt[maxn];
void Sort(int l, int r)
{
	memset(cnt, 0, sizeof(cnt));
	for(int i = l; i <= r; i++)
		cnt[ndel[i]]++;
	for(int i = 1; i < maxn; i++)
		cnt[i] += cnt[i - 1];
	for(int i = l; i <= r; i++)
		ans[(--cnt[ndel[i]]) + l] = ndel[i];
	for(int i = l; i <= r; i++) ndel[i] = ans[i];
}
bool judge(int x)
{
	for(int i = x; i < n; i++)
		ndel[i] = del[i];
	//sort(ndel + x, ndel + n);
	Sort(x, n - 1);
	int ans = 0;
	for(int i = x; i < n; i++)
	{
	//	cout<<i<<":"<<ndel[i]<<endl;
		if(ans < m && t[ndel[i]] == p[ans]) ans++;
	}
//	cout<<x<<" "<<ans<<endl;
	if(ans >= m) return true;
	return false; 
}
int main()
{
	scanf("%s", t);
	scanf("%s", p);
	n = strlen(t);
	m = strlen(p);
	for(int i = 0; i < n; i++)
		scanf("%d", &del[i]), del[i]--;
	int l = 0, r = n - 1;
	while(l < r) // find the max l that can ans
	{
		int mid = (l + r) / 2;
		if(judge(mid + 1)) l = mid + 1;
		else r = mid;
	}
	printf("%d\n", l);
}