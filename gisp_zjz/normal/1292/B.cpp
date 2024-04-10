#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const ll inf=2e16+10;
ll x[205],y[205],ax,bx,ay,by,t,xs,ys;
int n,ans;

int main(){
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    while (1){
        ++n;
        x[n]=ax*x[n-1]+bx;
        y[n]=ay*y[n-1]+by;
        if (x[n]>=inf||y[n]>=inf) break;
    }
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++){
        if (abs(x[i]-x[j])+abs(y[i]-y[j])+abs(xs-x[i])+abs(ys-y[i])<=t) ans=max(ans,max(i,j)-min(i,j)+1);
    }
    cout << ans << endl;
    return 0;
}