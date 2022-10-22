#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, k;
int vis1[maxn][2], vis2[maxn][2];
int cnt1, cnt2;// 
int num1, num2;// 
struct node
{
	int x, y;
	bool friend operator <(node xx, node yy)
	{
		return xx.x == yy.x ? xx.y < yy.y : xx.x < yy.x;
	}
	bool friend operator ==(node xx, node yy)
	{
		return xx.x == yy.x && xx.y == yy.y;
	}
};
int a, b, type;
map<node, int> t;
int ppow[maxn];
int ok1, ok2;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	ppow[0] = 1;
	for (int i = 1; i < maxn; i++) ppow[i] = ppow[i - 1] * 2 % mo;
	cnt1 = n, cnt2 = m, num1 = 0, num2 = 0;
	for (int i = 1; i <= n; i++) vis1[i][0] = vis1[i][1] = 0;
	for (int i = 1; i <= m; i++) vis2[i][0] = vis2[i][1] = 0;
	for (int i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &a, &b, &type);
		map<node, int>::iterator it = t.find((node){a, b});
//		if(t.find({2, 1}) != t.end()) printf("!!!!!!!");
		if(it != t.end())
		{
//			printf("!!!!!!!!!!!");
			int x = ((b & 1) ^ (it->second));
			int y = ((a & 1) ^ (it->second));
			vis1[a][x]--;
			if(vis1[a][x] == 0)
			{
				if(vis1[a][x ^ 1]) num1--;
				else cnt1++;
			}
			vis2[b][y]--;
			if(vis2[b][y] == 0)
			{
				if(vis2[b][y ^ 1]) num2--;
				else cnt2++;
			}
			if((a & 1) ^ (b & 1) ^ (it->second)) ok1--;
			else ok2--;
			t.erase({a, b});
		}
		if(type != -1)
		{
			int x = ((b & 1) ^ type);
			int y = ((a & 1) ^ type);
			vis1[a][x]++;
			if(vis1[a][x] == 1)
			{
				if(vis1[a][x ^ 1]) num1++;
				else cnt1--;
			}
			vis2[b][y]++;
			if(vis2[b][y] == 1)
			{
				if(vis2[b][y ^ 1]) num2++;
				else cnt2--;
			}
			if((a & 1) ^ (b & 1) ^ type) ok1++;
			else ok2++;
			t.insert(make_pair((node){a, b}, type));
		}
		int ans = (ok1 == 0 ? -1 : 0) + (ok2 == 0 ? -1 : 0);
		if(!num1) ans = (ans + ppow[cnt1]) % mo;
		if(!num2) ans = (ans + ppow[cnt2]) % mo;
		printf("%d\n", ans);
//		printf("%d %d %d %d %d %d %d\n", ok1, ok2, num1, num2, cnt1, cnt2, ans);
//		for (int i = 1; i <= n; i++) printf("%d %d\n", vis1[i][0], vis1[i][1]);
//		for (int i = 1; i <= m; i++) printf("%d %d\n", vis2[i][0], vis2[i][1]);
	}
	return 0;
}