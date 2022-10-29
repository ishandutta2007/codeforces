#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<long long,bool>f;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++){
        string s;
        cin>>s;
        long long v=0;
        for (auto j:s)
            v|=((long long)1<<(j-'a'));
        if (!f[v]){
            f[v]=1;
            ans++;   
        }
    }
    cout<<ans;
    return 0;
}