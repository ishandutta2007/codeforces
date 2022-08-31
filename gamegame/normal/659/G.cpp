#include<iostream>
using namespace std;
long long mod(long long x){
    return x%((long long)1e9+7);
}
long long s[1000001],h[1000002];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long ans=0;
    for(int i=1; i<=n ;i++){
        cin >> h[i];
        ans=mod(ans+h[i]-1);
    }
    h[n+1]=1e9+1;
    s[1]=0;
    h[0]=1e9+1;        //kitten
    for(int i=1; i<n ;i++){
        s[i+1]=mod(s[i]*(min(min(h[i-1],h[i+1]),h[i])-1)+min(h[i],h[i+1])-1);
        ans=mod(ans+(min(h[i+1],h[i])-1)*s[i+1]);
    }
    cout << ans << endl;
}