#include<bits/stdc++.h>
using namespace std;
int n,k,m,a,b,i;
int main(){
    cin>>n>>k;
    m=k<<1|1;
    a=(n+m-1)/m,b=n%m;
    if(b and b<k+1) k=0;
    cout<<a<<"\n";
    for(;i<a;++i) cout<<k+1+i*m<<" ";
    return 0;
}