#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1e6;
typedef long double ld;
const ld pi=acosl(-1);
const ld eps=0.5;
struct Z{ld x,y;Z(ld X=0,ld Y=0){x=X,y=Y;}};
Z operator +(Z a,Z b){return Z(a.x+b.x,a.y+b.y);}
Z operator -(Z a,Z b){return Z(a.x-b.x,a.y-b.y);}
Z operator *(Z a,Z b){return Z(a.x*b.x-a.y*b.y,a.x*b.y+b.x*a.y);}
Z a[N],b[N],tp[N],u,v,wi;
int len;
int bz[N];
void DFT(Z*a,int sig){
    for (int i=0;i<len;i++)tp[bz[i]]=a[i];
    for (int i=2,hal,j,k;i<=len;i<<=1)
        for (hal=i>>1,j=0;j<hal;j++){
            wi=Z(cosl(j*pi*sig/hal),sinl(j*pi*sig/hal));
            for (k=j;k<len;k+=i){
                u=tp[k];
                v=tp[k+hal]*wi;
                tp[k]=u+v;
                tp[k+hal]=u-v;
            }
        }
    for (int i=0;i<len;i++)a[i]=tp[i];
}
void set(int n) {
    for (len=1;len<=n;len<<=1);
    for (int i=0,j,k,l;i<len;bz[k]=i++)
        for (j=i,k=0,l=1;l<len;l<<=1,j>>=1)k=(k<<1)+(j&1);
}

pair<int, int> d[26];
int p[26], all[26];
char s[N],t[N];
int Next[N];
int n, m;
int ans[N];
int main() {
    for (int i = 0; i < 26; i ++)
        scanf("%d", &p[i]), p[i] --;
    int cnt = 0;
    for (int i = 0; i < 26; i ++)
        if (!d[i].first){
            ++cnt;
            int x = i;
            int y = 0;
            do{
                d[x] = {cnt, y ++};
                x = p[x];
            } while (!d[x].first);
            all[cnt] = y;
        }
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(s);
    m = strlen(t);
    set(n + m);
    for (int i = 0; i < m; i ++) {
        t[i] -= 'a';
        ld v = (pi - 2 * pi * d[t[i]].second) / all[d[t[i]].first];
        a[i] = {cosl(v), sinl(v)};
    }
    reverse(a, a + m);
    for (int i = 0; i < n; i ++) {
        s[i] -= 'a';
        ld v = 2 * pi * d[s[i]].second / all[d[s[i]].first];
        b[i] = {cosl(v), sinl(v)};
    }
    DFT(a, 1), DFT(b, 1);
    for (int i = 0; i < len; i ++) a[i] = a[i] * b[i];
    DFT(a, -1);
    reverse(a, a + m);
    ld v = 0;
    for (int i = 0; i < n ; i ++)
        v += cosl(pi / all[d[s[i]].first]);
    for (int i = 0; i < m - n + 1; i ++)
        ans[i] = (fabs(v - a[i].x / len) < 0.01);
    Next[0] = 0;
    for (int i = 0; i < n; i ++)
        s[i] = d[s[i]].first;
    for (int i = 0; i < m; i ++)
        t[i] = d[t[i]].first;
    for (int i=1, j = 0 ;i<n;i++){
        while (j && s[i] != s[j]) j = Next[j - 1];
        if (s[i] == s[j]) j ++;
        Next[i] = j;
    }
    for (int i=0, j = 0 ;i<m;i++){
        while (j && t[i] != s[j]) j = Next[j - 1];
        if (t[i] == s[j]) {
            j ++;
        }
        if (i >= n - 1)
            ans[i - n + 1] &= (j == n);
    }
    for (int i = 0; i < m - n + 1; i ++)
        printf("%d", ans[i]);
    return 0;
}