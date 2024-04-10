    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <time.h>
    #include <iostream>
    #include <algorithm>
    #include <fstream>
    #include <iomanip>
    #include <vector>
    #include <bitset>
    #include <stack>
    #include <queue>
    #include <set>
    #include <map>
     
    using namespace std;
     
    typedef double db;
     
    const int MAXN = 1605;
     
    int n,m,tot;
    int a[MAXN][MAXN];
    int sz[MAXN * MAXN];
    int ans[MAXN * MAXN];
    int cnt[MAXN * MAXN];
    int fa1[MAXN * MAXN];
    int fa2[MAXN * MAXN];
     
    db v[MAXN][MAXN];
    db t[MAXN][MAXN];
     
    int getroot(int *fa,int u)
    {
    	return u == fa[u] ? u : fa[u] = getroot(fa,fa[u]);
    }
     
    void run()
    {
    	memcpy(t,v,sizeof(t));
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			if (a[i][j])
    			{
    				db sum = 0,cnt = 0;
    				for (int k = i - 4;k <= i + 4;k++)
    					for (int l = j - 4;l <= j + 4;l++)
    						if (k >= 1 && k <= n && l >= 1 && l <= m && (i - k) * (i - k) + (j - l) * (j - l) <= 25)
    							sum += t[k][l],cnt++;
    				v[i][j] = sum / cnt;
    			}
    }
     
    void merge(int *fa,int xa,int ya,int xb,int yb)
    {
    	if (!a[xa][ya] || !a[xb][yb])
    		return;
    	fa[getroot(fa,(xa - 1) * m + ya)] = getroot(fa,(xb - 1) * m + yb);
    }
     
    int main()
    {
    	scanf("%d%d",&n,&m);
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			fa1[(i - 1) * m + j] = fa2[(i - 1) * m + j] = (i - 1) * m + j;
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			scanf("%d",&a[i][j]);
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			if (a[i][j])
    			{
    				v[i][j] = 1;
    				if (i > 1)
    					merge(fa1,i,j,i - 1,j);
    				if (i < n)
    					merge(fa1,i,j,i + 1,j);
    				if (j > 1)
    					merge(fa1,i,j,i,j - 1);
    				if (j < m)
    					merge(fa1,i,j,i,j + 1);
    			}
    	run();
    	run();
    	run();
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			if (a[i][j] && v[i][j] < 0.2)
    			{
    				if (i > 1 && v[i - 1][j] < 0.2)
    					merge(fa2,i,j,i - 1,j);
    				if (i < n && v[i + 1][j] < 0.2)
    					merge(fa2,i,j,i + 1,j);
    				if (j > 1 && v[i][j - 1] < 0.2)
    					merge(fa2,i,j,i,j - 1);
    				if (j < m && v[i][j + 1] < 0.2)
    					merge(fa2,i,j,i,j + 1);
    			}
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			if (a[i][j] && v[i][j] < 0.2)
    				sz[getroot(fa2,(i - 1) * m + j)]++;
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			if (a[i][j] && v[i][j] < 0.2 && getroot(fa2,(i - 1) * m + j) == (i - 1) * m + j && sz[(i - 1) * m + j] >= 5)
    				cnt[getroot(fa1,(i - 1) * m + j)]++;
    	for (int i = 1;i <= n;i++)
    		for (int j = 1;j <= m;j++)
    			if (a[i][j] && getroot(fa1,(i - 1) * m + j) == (i - 1) * m + j)
    				ans[++tot] = cnt[(i - 1) * m + j];
    	sort(ans + 1,ans + tot + 1);
    	printf("%d\n",tot);
    	for (int i = 1;i <= tot;i++)
    		printf("%d ",ans[i]);
    	printf("\n");
    	return 0;
    }