#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int a[N];
int n,k1,k2,k;
bool cmp(const int x,const int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k1>>k2;
    k=k1+k2;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[i]=abs(a[i]-x);
    }
    sort(a+1,a+n+1,cmp);
    int l=1,r=1;
    while (r<n&&a[r+1]==a[r])r++;
    l==r;
    while (k){
        while (r<n&&(a[r+1]==a[r]||a[r]==0))r++;
        if (!l||a[l]==0)l=r;
        if (!a[l])break;
        a[l]--;
        l--;
        k--;
    }
    if (k){
        cout<<(k&1);
    }else{
        long long ans=0;
        for (int i=1;i<=n;i++)
            ans+=(long long)a[i]*a[i];
        cout<<ans;
    }
    return 0;
}