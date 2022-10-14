#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 10, INF = 0x3f3f3f3f;

struct Node
{
	int lef, cap;
}bottle[N];

int n;
int tot_lef, tot_cap;
int f[N][N][10010];
int cnt;

bool cmp(Node a, Node b)
{
	return (a.cap > b.cap) || (a.cap == b.cap && a.lef > b.lef);
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> bottle[i].lef, tot_lef += bottle[i].lef;
    for (int i = 1; i <= n; i++) cin >> bottle[i].cap, tot_cap += bottle[i].cap;
    
    sort (bottle + 1, bottle + n + 1, cmp);
    // for (int i=1; i<=n;i++) cout<<bottle[i].lef<<' '<<bottle[i].cap<<endl;
    
    // 
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
    	tot += bottle[i].cap;
    	if (tot >= tot_lef) 
    	{
    		cnt = i;
    		break;
		}
	}
	
	memset(f, -63, sizeof(f));
    f[0][0][0]=0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= i; j++)
			for (int k = 0; k <= tot_cap; k++)
			{
				if (j == 0 && k == 0) f[i][j][k] = 0;
				f[i][j][k] = f[i - 1][j][k];
				if (k < bottle[i].cap||j==0) ;
				else f[i][j][k] =max(f[i][j][k], max(f[i - 1][j][k], f[i - 1][j - 1][k - bottle[i].cap] + bottle[i].lef));	
			}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int k = tot_lef; k <= tot_cap; k++)
			ans = max(ans, f[i][cnt][k]);

	cout << cnt << " " << tot_lef - ans << endl;
	
	return 0;
}