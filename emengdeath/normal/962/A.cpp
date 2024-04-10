#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n;
long long a[N];
long long all;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    for (int i=1;i<=n;i++)
        if (a[i]*2>=a[n]){
            cout<<i;
            return 0;
        }
    return 0;
}