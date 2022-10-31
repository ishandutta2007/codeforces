#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 1000020
using namespace std;

char s[N];
int f[N], h[N];
vector<int> g;

bool Check(int n, int m)
{
    int i, j;
    char *t;

    t = s + n - m;
    h[0] = h[1] = 0;
    for(i = 1; i < m; i ++)
    {
        j = h[i];
        while(j && t[i] != t[j])
            j = h[j];
        h[i + 1] = t[i] == t[j] ? j + 1 : 0;
    }

    // cout<<t<<endl;
    // for(i=0;i<=m;i++)cout<<h[i]<<' ';cout<<endl;

    for(i = 1, j = 0; i < n - 1; i ++)
    {
        while(j && s[i] != t[j])
            j = h[j];
        j = s[i] == t[j] ? j + 1 : 0;
        // printf("at %d : %d %d\n",i,j,m);
        if(j == m)
            return true;
    }

    return false;
}

void BSFind(int n)
{
    int l, m, r;

    for(l = -1, r = g.size(); l + 1 < r; )
        if(Check(n, g.at(m = (l + r) >> 1)))
            l = m;
        else
            r = m;

    if(l == -1)
        printf("Just a legend\n");
    else
        printf("%s\n", s + n - g.at(l));

    return;
}

int main(void)
{
    int n;
    int i, j;

    scanf("%s", s);
    n = strlen(s);

    f[0] = f[1] = 0;
    for(i = 1; i < n; i ++)
    {
        j = f[i];
        // cout<<i<<' '<<f[i]<<endl;
        while(j && s[i] != s[j])
            j = f[j];
        f[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }

    // for(i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
    // puts("OK");
    for(i = f[n]; i; i = f[i])
    {
        // cout<<i<<endl;
        g.push_back(i);
    }
    // puts("OK2");
    reverse(g.begin(), g.end());
    // for(int x:g)cout<<x<<' ';cout<<endl;
    BSFind(n);

    return 0;
}