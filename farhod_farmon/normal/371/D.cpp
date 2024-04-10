#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n;
int l[N];
int r[N];
int a[N];
int b[N];
int y;

int upd(int h)
{
    if(h > n)
        return h;
    if(b[h] + y >= a[h]){
        y = y - (a[h] - b[h]);
        b[h] = a[h];
        return r[h] = upd(r[h]);
    }
    b[h] += y;
    return h;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d", &n);
    for(int i = 1; i <= n; i++){
        sc("%d", &a[i]);
        r[i] = i + 1;
    }
    int m;
    sc("%d", &m);
    for(int i = 1; i <= m; i++){
        int t, x;
        sc("%d", &t);
        if(t == 1){
            sc("%d%d", &x, &y);
            upd(x);
        }
        else{
            sc("%d", &x);
            pr("%d\n", b[x]);
        }
    }
}