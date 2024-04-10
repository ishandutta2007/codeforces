#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
long long did(long long r){
    long long rr=(r&(-r));
    return rr;
}
void work(long long n,long long v,long long rr){
    if (n==1)return;
    if (n&1){
        ans+=v*(n/2)+did(rr);
        work(n/2,v*2,rr-v*2);
    }else{
        ans+=v*(n/2);
        work(n/2,v*2,rr-v);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    work(n,1,n-1);
    cout<<ans;
    return 0;
}