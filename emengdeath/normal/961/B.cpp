#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int a[N],t[N];
int ans,all;
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++){
        cin>>t[i]; 
        if (t[i]==1)all+=a[i],a[i]=0;
        a[i]+=a[i-1];
    }
    for (int i=1;i<=n-m+1;i++)
        ans=max(ans,a[i+m-1]-a[i-1]);
    cout<<ans+all;
    return 0;
}