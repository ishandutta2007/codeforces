#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int x[100005],y[100005];
int up[2000005],down[2000005];
int A=1000000;

bool on(int i,int j,int nx,int ny) {
    return 1LL*(x[j]-x[i])*(ny-y[i])-1LL*(y[j]-y[i])*(nx-x[i])==0;
}

bool cw(int i,int j,int nx,int ny) {
    return 1LL*(x[j]-x[i])*(ny-y[i])-1LL*(y[j]-y[i])*(nx-x[i])>=0;
}

bool ccw(int i,int j,int nx,int ny) {
    return 1LL*(x[j]-x[i])*(ny-y[i])-1LL*(y[j]-y[i])*(nx-x[i])<=0;
}

double solveX(int n) {
    for(int i=-A;i<=A;++i) {
        up[i+A]=-2*A;
        down[i+A]=2*A;
    }
//  bool ok1=cw(0,1,x[2],y[2]),ok2=ccw(0,1,x[2],y[2]);
//  if (ok1) ok2=false;
    bool ok1=false,ok2=false;
    for(int i=2;i<n;++i)
        if (!on(i-2,i-1,x[i],y[i])) {
            ok1=cw(i-2,i-1,x[i],y[i]);
            ok2=ccw(i-2,i-1,x[i],y[i]);
            break;
        }
    for(int i=0;i<n;++i) {
        int lx=min(x[i],x[i+1]),rx=max(x[i],x[i+1]);
        if (lx==rx) {
            up[lx+A]=max(up[lx+A],max(y[i],y[i+1]));
            down[lx+A]=min(down[lx+A],min(y[i],y[i+1]));
        } else
        for(int j=lx;j<=rx;++j) {
            long double ny=(1.0*(y[i+1]-y[i])*(j-x[i])/(x[i+1]-x[i]));
//          if (ny<0) ny-=1e-9;
//          else ny+=1e-9;
//          ny-=1e-9;
            int u=ny+y[i]-2;
            if (ok1) {
                if (!cw(i,i+1,j,u)) {
                    ++u;
                    while (!cw(i,i+1,j,u)) {
                        ++u;
                    }
                    down[j+A]=u;
                }
                else {
                    while(cw(i,i+1,j,u+1)) ++u;
                    up[j+A]=u;
                }
            }
            if (ok2) {
                if (!ccw(i,i+1,j,u)) {
                    ++u;
                    while (!ccw(i,i+1,j,u)) {
                        ++u;
                    }
                    down[j+A]=u;
                }
                else {
                    while(ccw(i,i+1,j,u+1)) ++u;
                    up[j+A]=u;
                }
            }
/*          while (ok2&&!ccw(i,i+1,j,u)) {
                ++u;
            }*/
//          up[j+A]=max(up[j+A],u);
//          down[j+A]=min(down[j+A],u);
        }
    }
    long double ret=0;
    long long sum=0,total=0;
    for(int i=-A;i<=A;++i) {
        if (up[i+A]>=down[i+A]) {
            total+=(up[i+A]-down[i+A]+1);
            ret+=1LL*i*i*(up[i+A]-down[i+A]+1);
            sum+=1LL*i*(up[i+A]-down[i+A]+1);
        }
    }
    for(int i=-A;i<=A;++i) {
        if (up[i+A]>=down[i+A]) {
            ret-=1.0*i*(up[i+A]-down[i+A]+1)/total*sum;
        }
    }
//  cout << total << endl;
/*  for(int i=16;i<=859;++i) {
        if (ok2&&(!ccw(0,1,i,down[i+A])||!ccw(1,2,i,down[i+A])||!ccw(2,3,i,down[i+A])))
            cout << "fail1\n";
        if (ok2&&(!ccw(0,1,i,up[i+A])||!ccw(1,2,i,up[i+A])||!ccw(2,3,i,up[i+A])))
            cout << "fail2\n";
        cout << down[i+A] << "  " << up[i+A] << endl;
    }*/
    return ret/(total-1);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d%d",&x[i],&y[i]);
    x[n]=x[0]; y[n]=y[0];
    
    double ans=solveX(n);
    for(int i=0;i<=n;++i)
        swap(x[i],y[i]);
    memset(up,0,sizeof(up));
    memset(down,0,sizeof(down));
    ans+=solveX(n);
    printf("%.7lf\n",ans);
    return 0;
}