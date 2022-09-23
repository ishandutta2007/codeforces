#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, q;
int a[N];
bool pre;

void upd(int x, int y)
{
    while(x <= n){
        a[x] += y;
        x += x & -x;
    }
}

int f(int x)
{
    int cnt = 0;
    while(x){
        cnt += a[x];
        x -= x & -x;
    }
    return cnt;
}

int get(int l, int r)
{
    if(l > r)
        swap(l, r);
    return f(r) - f(l);
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    sc("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        upd(i, 1);
    int cl = 1,
        cr = n;
    for(int i = 1; i <= q; i++){
        int t, l, r;
        sc("%d", &t);
        if(t == 1){
            int sz = cr - cl + 1;
            sc("%d", &l);
            if(l > sz / 2){
                pre = !pre;
                l = sz - l;
            }
            if(pre){
                for(int j = 0; j < l; j++)
                    upd(cr - l - j, get(cr - l + j, cr - l + j + 1));
                cr -= l;
            }
            else{
                for(int j = 0; j < l; j++)
                    upd(cl + l + j, get(cl + l - j - 1, cl + l - j - 2));
                cl += l;
            }
        }
        else{
            sc("%d%d", &l, &r);
            l++;
            if(pre)
                pr("%d\n", get(cr - r, cr - l + 1));
            else
                pr("%d\n", get(cl + l - 2, cl + r - 1));
        }
    }
}