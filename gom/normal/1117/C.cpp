#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,x1,y1,x2,y2,l=1,r=1e18,ans=1e18;
ll sx[N],sy[N]; string s;
bool pos(ll m)
{
    ll nx=x1+m/n*sx[n]+sx[m%n];
    ll ny=y1+m/n*sy[n]+sy[m%n];
    if(abs(x2-nx)+abs(y2-ny)<=m) return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>x1>>y1>>x2>>y2;
    cin>>n>>s;
    for(int i=1;i<=n;i++){
        ll dx=0,dy=0;
        if(s[i-1]=='U') dy=1;
        if(s[i-1]=='D') dy=-1;
        if(s[i-1]=='L') dx=-1;
        if(s[i-1]=='R') dx=1;
        sx[i]=sx[i-1]+dx;
        sy[i]=sy[i-1]+dy;
    }
    if(!pos(1e18)){
        cout<<-1;
        return 0;
    }
    while(l<=r){
        ll m=(l+r)/2LL;
        if(pos(m)){
            r=m-1LL;
            ans=m;
        }
        else l=m+1LL;
    }
    cout<<ans;
    return 0;
}