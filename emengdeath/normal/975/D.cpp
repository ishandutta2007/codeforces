#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N];
long long n,A,B,sum1,sum2,sum3;
struct point{
    int x,y;
}b[N];
long long did(long long x){
    return x*(x-1);
}
bool cmp(const point&a,const point&b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>A>>B;
    for (int i=1;i<=n;i++){
        long long x,vx,vy;
        cin>>x>>vx>>vy;
        a[i]=-vx*A+vy*1;
        b[i].x=vx,b[i].y=vy;
        if (!a[i]){
            if (vx==0&&vy==0)sum1++;
            else
            if (vx*1+vy*A<0) sum2++;
            else
                sum3++;
        }
    }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1,cmp);
    int l=1;
    long long ans=0;
    for (int i=1;i<=n;i++)
        if (a[l]!=a[i]){
            if (a[l])ans+=did(i-l);
            l=i;
        }
    if (a[l])ans+=did(n-l+1);
    ans+=(sum2+sum3)*sum1*2+sum2*sum3*2;
    l=1;
    for (int i=1;i<=n;i++)
        if (b[l].x!=b[i].x||b[l].y!=b[i].y){
            if ((b[l].x||b[l].y)&&(-b[l].x*A+b[l].y))ans-=did(i-l);
            l=i;
        }
    if ((b[l].x||b[l].y)&&(-b[l].x*A+b[l].y))ans-=did(n-l+1);
    cout<<ans;
    return 0;
}