#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
char a[N], b[N], c[N];
int na, nb, nc;
int f[N], g[N];
int Next[N], Extendb[N], Extendc[N];
void pre_EKMP(char x[],int m,int nxt[])
{
    nxt[0]=m;
    int j=0;
    while(j+1<m && x[j]==x[j+1]) j++;
    nxt[1]=j;
    int k=1;
    for(int i=2;i<m;i++)
    {
        int p=nxt[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1)nxt[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<m && x[i+j]==x[j])j++;
            nxt[i]=j;
            k=i;
        }
    }
}
void EKMP(char x[],int m,char y[],int n,int nxt[],int extend[])
{
    pre_EKMP(x,m,nxt);
    int j=0;
    while(j<n && j<m && x[j]==y[j]) j++;
    extend[0]=j;
    int k=0;
    for(int i=1;i<n;i++)
    {
        int p=extend[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1)
            extend[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<n && j<m && y[i+j]==x[j]) j++;
            extend[i]=j;
            k=i;
        }
    }
}
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int main() {
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    na = strlen(a), nb = strlen(b), nc = strlen(c);
    EKMP(b, nb, a, na, Next, Extendb);
    EKMP(c, nc, a, na, Next, Extendc);
    f[0] = 1;
    for (int i = 0; i <= na; i ++) {
        f[i] = add(f[i], g[i]);
        g[i + 1] = add(g[i + 1], g[i]);
        if (i< na&&a[i] != '0') {
            int l = i + nb - 1;
            if (l >= na)
                continue;
            int r = i + nc - 1;
            if (Extendb[i] != nb ) {
                if (a[i + Extendb[i]] < b[Extendb[i]])
                    ++l;
            }
            if (r >= na) {
                r = na - 1;
            } else {
                if (Extendc[i] != nc) {
                    if (a[i + Extendc[i]] >c[Extendc[i]])
                        r--;
                }
            }
            if (l <= r) {
                g[l + 1] = add(g[l + 1], f[i]);
                g[r + 2] = sub(g[r + 2], f[i]);
            }
        } else
            if (i < na) {
                if (b[0] == '0') {
                    g[i + 1] = add(g[i + 1], f[i]);
                    g[i + 2] = sub(g[i + 2], f[i]);
                }
            }
    }
    printf("%d\n", f[na]);
    return 0;
}