#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 400020
using namespace std;
 
int a[N];
vector<int> v;
int c[N], t[N], s[N];
vector<int> k[N], f;
int o[N];
 
int main(void)
{
    int n, m, w, h;
    int i, j, p, x, y;
 
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    m = v.size();
    for(i = 0; i < n; i ++)
        t[a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin()] ++;
    for(i = 0; i < m; i ++)
        c[t[i]] ++;
    // for(i=0;i<m;i++)cout<<t[i]<<' ';cout<<endl;
    for(i = n; i > 0; i --)
        c[i] += c[i + 1];
    for(i = 1; i <= n; i ++)
        c[i] += c[i - 1];
 
    // for(i=0;i<=n;i++)cout<<c[i]<<" ";cout<<endl;
 
    for(i = 1; i <= n; i ++)
        for(s[i] = s[i - 1]; c[s[i]] < i; s[i] ++)
            ;
    for(i = 1, h = w = 0; i <= n; i ++)
        for(j = i; (long long)i * j <= n; j ++)
            if(s[i * j] <= min(i, j) && h * w <= i * j)
            {
                h = i;
                w = j;
            }
 
    for(i = 0; i < m; i ++)
        for(j = 1; j <= t[i]; j ++)
            k[j].push_back(i);
    for(i = 1; i <= n; i ++)
        for(j = 0; j < (signed)k[i].size(); j ++)
            f.push_back(k[i][j]);
    sort(f.begin(), f.begin() + h * w);
    for(i = 0; i < m; i ++)
        t[i] = 0;
    for(i = 0; i < h * w; i ++)
        t[f[i]] ++;
    for(i = 1; i <= n; i ++)
        k[i].clear();
    for(i = 0; i < m; i ++)
        k[t[i]].push_back(i);
    f.clear();
    for(i = n; i >= 1; i --)
        for(j = 0; j < (signed)k[i].size(); j ++)
            for(p = 0; p < i; p ++)
                f.push_back(k[i][j]);
    // for(int xx:f)cout<<v[xx]<<' ';cout<<endl;

    printf("%d\n%d %d\n", h * w, h, w);
    p = x = y = 0;
    for(i = 0; i < h * w; i ++)
    {
        // printf("%d %d\n",x,y);
        // if(x<0||y<0||x>=h||y>=w){printf("got %d %d\n",x,y);throw;}
        o[x * w + y] = v[f[i]];
        x ++;
        y ++;
        if(x >= h || y >= w)
        {
            p ++;
            if(p <= w - h)
            {
                x = 0;
                y = p;
            }
            else if((p - (w - h)) & 1)
            {
                x = 0;
                y = w - h + ((p - (w - h)) >> 1) + 1;
            }
            else
            {
                x = h - ((p - (w - h)) >> 1);
                y = 0;
            }
        }
    }
    for(i = 0; i < h; i ++)
        for(j = 0; j < w; j ++)
            printf("%d%c", o[i * w + j], " \n"[j == w - 1]);
 
    return 0;
}