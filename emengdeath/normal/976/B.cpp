#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    k++;
    if (k<=n){
        cout<<k<<' '<<1;
        return 0;
    }
    k-=n;
    long long x=(k-1)/(m-1);
    long long y=k-x*(m-1);
    if (x&1)y=m-y+1;
    else
        y++;
    x=n-x;
    cout<<x<<' '<<y;
    return 0;
}