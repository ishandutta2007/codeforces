#include<bits/stdc++.h>
using namespace std;
#define int long long
struct Node{
    int x,id;
    inline bool operator <(const Node &p)const{
        return x<p.x;
    }
}a[100005];
int t,n,b[100005][2];
const int mod=1e9+7;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=1;
        for(int i=1;i<=n;i++)cin>>a[i].x,a[i].id=i;
        sort(a+1,a+n+1);
        b[0][0]=n+1;
        for(int k=1;k<=n;k++)b[k][0]=min(b[k-1][0],a[k].id),b[k][1]=max(b[k-1][1],a[k].id);
        for(int k=1;k<=n;k++)if(a[k+1].id<=b[k][1]&&a[k+1].id>=b[k][0]){
            ans*=max(b[k][1]-b[k][0]+1-k,1ll);
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}