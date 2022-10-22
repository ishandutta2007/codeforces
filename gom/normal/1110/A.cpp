#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int b,k,a[N],c=1,res;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>b>>k;
    for(int i=1;i<=k;i++) cin>>a[i];
    for(int i=1;i<=k;i++){
        (res+=a[k+1-i]*c)%=2;
        (c*=b)%=2;
    }
    if(!res) cout<<"even";
    else cout<<"odd";
    return 0;
}