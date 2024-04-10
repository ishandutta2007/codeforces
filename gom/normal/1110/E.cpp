#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N],b[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    if(a[1]!=b[1]){
        cout<<"No";
        return 0;
    }
    n--;
    for(int i=1;i<=n;i++){
        a[i]=a[i+1]-a[i];
        b[i]=b[i+1]-b[i];
    }
    sort(a+1,a+1+n); sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}