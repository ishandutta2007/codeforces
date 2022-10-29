#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long a[N],b[N];
int n,q,l;
long long get(int l,int r){
    return a[l]-a[r+1];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    for (int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
    for (int i=n-1;i;i--)a[i]+=a[i+1]; 
    l=1;
    for (int i=1;i<=q;i++){
        long long x;
        cin>>x;
        if (a[l+1]+b[l]<=x){
            cout<<n<<endl;
            l=1,b[1]=a[1]-a[2];
            continue;
        }
        if (b[l]>=x){
            b[l]-=x;
            if (b[l]==0)l++,b[l]=a[l]-a[l+1];
            cout<<n-l+1<<endl;
            continue;
        }
        int ll=l+1,rr=n,mid,s=n;
        while (ll<=rr){
            if (get(l+1,mid=(ll+rr)/2)+b[l]>=x)rr=mid-1,s=min(s,mid);
            else
                ll=mid+1;
        }
        x-=get(l+1,s-1)+b[l];
        l=s;
        b[l]=a[l]-a[l+1]-x;
        if (!b[l]){
            l++;
            b[l]=a[l]-a[l+1];
        }
        cout<<n-l+1<<endl;
    }
    return 0;
}