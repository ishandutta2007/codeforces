#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=1e6+3;
struct pi{
    db x,y;
    pi operator- (const pi &u){return (pi){x-u.x,y-u.y};}
    db operator^ (const pi &u){return x*u.y-y*u.x;}
}b[maxn];
db S[maxn];
int n,top,c[maxn];
ll a[maxn];

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    db sum=0;
    for (int i=1;i<=n;i++){
        sum+=a[i]; S[i]=sum;
        pi res=(pi){(db)i,sum};
        //cout<<i<<' '<<sum<<endl;
        while (top>=1&&((b[top]-b[top-1])^(res-b[top]))<0) top--;
        b[++top]=res; c[top]=i;
    }
    for (int i=1;i<=top;i++){
        //cout<<b[i].x<<' '<<b[i].y<<' '<<c[i]<<endl;
        int num=c[i]-c[i-1];
        db val=S[c[i]]-S[c[i-1]];
        for (int j=0;j<num;j++) printf("%.10f\n",val/num);
    }
    return 0;
}