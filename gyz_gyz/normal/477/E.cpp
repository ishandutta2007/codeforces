#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define abs(x) ((x)>0?(x):-(x))
#define mx 1000000
#define inf 1000000000
using namespace std;
int n,q,a[mx][20],b[mx][20],c[mx][20],bt[mx],r2[20],x1,y1,x2,y2;
int d,mi,sx,l,r,m;
inline int dis(int x,int y1,int y2){
    int d=abs(y1-y2);
    d=min(d,y2+1);d=min(d,a[x][0]-y2+1);
    return d;
}
inline int f(int l,int r){
    int pp=bt[r-l+1];if(!pp)return a[l][0];
    return min(a[l][pp-1],a[r-r2[pp-1]+1][pp-1]);
}
inline int f1(int l,int r){
    int pp=bt[r-l+1];if(!pp)return b[l][0];
    return min(b[l][pp-1],b[r-r2[pp-1]+1][pp-1]);
}
inline int f2(int l,int r){
    int pp=bt[r-l+1];if(!pp)return c[l][0];
    return min(c[l][pp-1],c[r-r2[pp-1]+1][pp-1]);
}
int main(){
    r2[0]=1;rep(i,1,19)r2[i]=r2[i-1]*2;
    scanf("%d",&n);
    rep(i,1,n){
        if(i>r2[q])q++;
        bt[i]=q;
    }
    rep(i,1,n)rep(j,0,19)a[i][j]=inf,b[i][j]=inf,c[i][j]=inf;
    rep(i,1,n)scanf("%d",&a[i][0]);
    rep(i,1,n)b[i][0]=a[i][0]+i*2,c[i][0]=a[i][0]+(n-i+1)*2;
    rep(j,1,19)rep(i,1,n){
        a[i][j]=min(a[i][j-1],a[i+r2[j-1]][j-1]);
        b[i][j]=min(b[i][j-1],b[i+r2[j-1]][j-1]);
        c[i][j]=min(c[i][j-1],c[i+r2[j-1]][j-1]);
    }       
    scanf("%d",&q);
    rep(o,1,q){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1<=x2){
            mi=f(x1,x2);sx=min(mi,y1);
            d=min(abs(sx-y2),y2+1);
            l=x1;r=x2;m=(l+r)/2;
            for(;l<r;m=(l+r)/2){
                mi=f(m,x2);if(mi>=y2)r=m;else l=m+1;
            }
            mi=f(m,x2);d=min(d,mi-y2+1);
            if(m>x1){
                mi=f(m-1,x2);d=min(d,y2-mi+1);
            }else{
                l=1;r=x1;m=(l+r)/2;
                for(;l<r;m=(l+r)/2){
                    mi=f(m,x2);if(mi>=y2)r=m;else l=m+1;
                }
                sx=f(m,x2);
                if(m>1){
                    mi=f(m-1,x2);if(y1<=mi)mi--;d=min(d,y2-mi+(x1-m+1)*2);
                }
                l=1;r=x1+1;m=(l+r)/2;
                for(;l<r;m=(l+r)/2){
                    mi=f(m,x2);if(mi>sx)r=m;else l=m+1;
                }
                if(m>1){
                    mi=f2(m-1,x1)-(n-x1+1)*2;if(y1<mi)mi++;d=min(d,mi-y2);
                }
            }
            l=x2;r=n;m=(l+r+1)/2;
            for(;l<r;m=(l+r+1)/2){
                mi=f(x2,m);if(mi>=y2)l=m;else r=m-1;
            }
            sx=f(x2,m);
            if(m<n){
                mi=f(x2,m+1);if(min(f(x1,x2),y1)<mi)mi--;d=min(d,y2-mi+(m-x2+1)*2);
            }
            l=x2-1;r=n;m=(l+r+1)/2;
            for(;l<r;m=(l+r+1)/2){
                mi=f(x2,m);if(mi>sx)l=m;else r=m-1;
            }
            if(m<n){
                mi=f1(x2,m+1)-x2*2;if(min(f(x1,x2),y1)<mi)mi++;d=min(d,mi-y2);
            }
            d+=x2-x1;printf("%d\n",d);
        }
        if(x1>x2){
            mi=f(x2,x1);sx=min(mi,y1);
            d=min(abs(sx-y2),y2+1);
            l=x2;r=x1;m=(l+r+1)/2;
            for(;l<r;m=(l+r+1)/2){
                mi=f(x2,m);
                if(mi>=y2)l=m;else r=m-1;
            }
            mi=f(x2,m);d=min(d,mi-y2+1);
            if(m<x1){
                mi=f(x2,m+1);d=min(d,y2-mi+1);
            }else{
                l=x1;r=n;m=(l+r+1)/2;
                for(;l<r;m=(l+r+1)/2){
                    mi=f(x2,m);if(mi>=y2)l=m;else r=m-1;
                }
                sx=f(x2,m);
                if(m<n){
                    mi=f(x2,m+1);if(y1<mi)mi--;d=min(d,y2-mi+(m-x1+1)*2);
                }
                l=x1-1;r=n;m=(l+r+1)/2;
                for(;l<r;m=(l+r+1)/2){
                    mi=f(x2,m);if(mi>sx)l=m;else r=m-1;
                }
                if(m<n){
                    mi=f1(x1,m+1)-x1*2;if(y1<mi)mi++;d=min(d,mi-y2);
                }
            }
            l=1;r=x2;m=(l+r)/2;
            for(;l<r;m=(l+r)/2){
                mi=f(m,x2);if(mi>=y2)r=m;else l=m+1;
            }
            sx=f(m,x2);
            if(m>1){
                mi=f(m-1,x2);if(min(f(x2,x1),y1)<mi)mi--;d=min(d,y2-mi+(x2-m+1)*2);
            }
            l=1;r=x2+1;m=(l+r)/2;
            for(;l<r;m=(l+r)/2){
                mi=f(m,x2);if(mi>sx)r=m;else l=m+1;
            }
            if(m>1){
                mi=f2(m-1,x2)-(n-x2+1)*2;if(min(f(x2,x1),y1)<mi)mi++;d=min(d,mi-y2);
            }
            d+=x1-x2;printf("%d\n",d);
        }
    }
}