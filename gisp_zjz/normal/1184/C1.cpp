#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int x[maxn],y[maxn],n,p[maxn],q[maxn];
bool check(){
    int xa,xb,ya,yb;
    xa=xb=p[0];
    ya=yb=q[0];
    for (int i=1;i<n*4;i++) xa=min(xa,p[i]),xb=max(xb,p[i]),ya=min(ya,q[i]),yb=max(yb,q[i]);
    for (int i=0;i<n*4;i++) if (!(xa==p[i]||xb==p[i]||ya==q[i]||yb==q[i])) return 0;
    if (yb-ya!=xb-xa) return 0;
    return 1;
}
int main(){
    cin >> n;
    for (int i=0;i<=n*4;i++) cin >> x[i] >> y[i];
    for (int i=0;i<=n*4;i++){
        int c=0;
        for (int j=0;j<=n*4;j++) if (i!=j) p[c]=x[j],q[c++]=y[j];
        if (check()) {cout << x[i] << ' ' << y[i] << endl;return 0;}
    }
    assert(0);
}