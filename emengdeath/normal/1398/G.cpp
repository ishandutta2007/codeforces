#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 1e6 + 10;
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
int A[N], B[N], c[N];
int n, x, y;
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
void FFT(int*ap,int*bp,int na, int nb,int*cp){
    set(na + nb);
    for (int i = 0; i < na; i ++) a[i] = ap[i];
    for (int i = 0; i < nb; i ++) b[i] = bp[i];
    for (int i = na; i < len; i ++) a[i] = {0, 0};
    for (int i = nb; i < len; i ++) b[i] = {0, 0};
    DFT(a,1),DFT(b,1);
    for (int i=0;i<len;i++)a[i]=a[i]*b[i];
    DFT(a,-1);
    for (int i=0;i < na + nb - 1;i++)cp[i]=int(a[i].x/ld(len)+eps);
}
int f[N];
int main() {
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 0; i <= n;i  ++) {
        int z;
        scanf("%d", &z);
        A[z] = 1;
        B[x - z] = 1;
    }
    FFT(A, B, x + 1, x + 1, c);
    for (int i = 2; i < N ;i += 2)
        for (int j = 1; 1ll * i * j < N; j ++)
            if (i > 2 * y && c[(i - 2 * y) / 2 + x]) {
                f[i * j] = i;
            }
    int q;
    scanf("%d", &q);
    while (q --) {
        int x;
        scanf("%d", &x);
        if (f[x]) printf("%d ", f[x]);
        else
            printf("-1 ");
    }
    return 0;
}