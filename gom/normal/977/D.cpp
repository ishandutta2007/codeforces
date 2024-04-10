#include<bits/stdc++.h>
#define N 105
using namespace std;
typedef long long ll;
int n,k;ll a[N],s;
unordered_map<ll,bool>dp;
unordered_map<ll,bool>use;
unordered_map<ll,ll>nxt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        dp[a[i]]=true;
    }
    for(int i=0;i<=n;i++){
        if(a[i]%3==0&&dp[a[i]/3]){
            nxt[a[i]]=a[i]/3;
            use[a[i]/3]=true;
        }
        else if(dp[a[i]*2]){
            nxt[a[i]]=a[i]*2;
            use[a[i]*2]=true;
        }
    }
    for(int i=1;i<=n;i++){
        if(!use[a[i]])
            s=a[i];
    }

    for(int i=1;i<=n;i++){
        cout<<s<<" ";
        s=nxt[s];
    }
    return 0;
}