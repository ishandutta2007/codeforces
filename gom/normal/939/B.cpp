#include <bits/stdc++.h>
#define N 100005
using namespace std;
long long n,k,a[N],ans,res,num=1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    res=n;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        if(res>n%a[i]){
            ans=n/a[i];
            res=n%a[i];
            num=i;
        }
    }
    cout<<num<<" "<<ans;
    return 0;
}