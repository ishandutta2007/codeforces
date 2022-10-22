#include <bits/stdc++.h>
#define N 5005
#define INF 5000000
using namespace std;
typedef long long ll;
int n,q,l,r,dp1[N][N],dp2[N][N],mx[N];
ll a[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        dp1[i][i]=a[i];
        dp2[i][i]=a[i];
        dp1[i][i+1]=a[i]^a[i+1];
        mx[i]=a[i];
    }
    for(int d=2;d<=n;d++){
        for(int i=1;i+d<=n;i++){
                int j=i+d;
                dp1[i][j]=dp1[i][j-1]^dp1[i+1][j];
        }
    }
    for(int d=1;d<=n;d++){
        for(int i=1;i+d<=n;i++){
            int j=i+d;
            dp2[i][j]=max({dp2[i][j-1],mx[j],dp1[i][j]});
            mx[j]=max(dp2[i][j],dp2[i][j]);
        }
    }
    cin>>q;
    while(q-->0){
        cin>>l>>r;
        cout<<dp2[l][r]<<'\n';
    }
    return 0;
}