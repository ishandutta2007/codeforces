#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;
const int MX = 10010;

using namespace std;

int n;
int a[N];
int b[N];
int c[N];
vector < int > v[N];

int get(int pos, int x)
{
    if(v[x].empty() || v[x].back() < pos)
        return 0;
    int l = 0,
        r = v[x].size() - 1;
    while(l < r){
        int m = (l + r) / 2;
        if(v[x][m] < pos)
            l = m + 1;
        else
            r = m;
    }
    return v[x].size() - l;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d", &n);
    for(int i = 1; i <= n; i++){
        sc("%d%d", &a[i], &b[i]);
        v[a[i]].pb(i);
    }
    int q;
    sc("%d", &q);
    for(int i = 1; i <= q; i++){
        int k;
        sc("%d", &k);
        for(int j = 1; j <= k; j++)
            sc("%d", &c[j]);
        int l = 0,
            r = n;
        while(l < r){
            int m = (l + r) / 2 + 1;
            int cnt = 0;
            for(int j = 1; j <= k; j++)
                cnt += get(m, c[j]);
            if(cnt <= n - m)
                l = m;
            else
                r = m - 1;
        }
        if(l == 0){
            pr("0 0\n");
            continue;
        }
        int x = a[l];
        l = 0;
        r = v[x].size() - 1;
        while(l < r){
            int m = (l + r) / 2;
            int cnt = v[x].size() - m;
            for(int j = 1; j <= k; j++)
                cnt += get(v[x][m], c[j]);
            if(cnt < n - v[x][m] + 1)
                l = m + 1;
            else
                r = m;
        }
        pr("%d %d\n", x, b[v[x][l]]);
    }
}