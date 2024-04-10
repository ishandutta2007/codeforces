#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1005;
int n,x[N],y[N],a[N],b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++){
        map<P,bool> mp; bool isans=true;
        for(int j=1;j<=n;j++) mp[P(a[j],b[j])]=true;
        mp[P(a[i],b[i])]=false;
        for(int j=2;j<=n;j++){
            int dx=x[1]+a[i]-x[j],dy=y[1]+b[i]-y[j];
            if(!mp[P(dx,dy)]){
                isans=false;
                break;
            }
        }
        if(isans){
            cout<<x[1]+a[i]<<" "<<y[1]+b[i];
            return 0;
        }
    }
    return 0;
}