#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector <int> t[260];
const int T=250;
int f[105],n,ans,a,b;
char s[105];
int calc(){
    int ret=0;
    for (int i=0;i<n;i++) ret+=f[i];
    return ret;
}

int main(){
    cin >> n >> s;
    for (int i=0;i<n;i++) f[i]=(s[i]=='1'); ans=calc();
    for (int i=0;i<n;i++){
        cin >> a >> b;
        while (b<=T) t[b].pb(i),b+=a;
    }
    for (int i=1;i<=T;i++){
        for (auto x:t[i]) f[x]^=1;
        ans=max(ans,calc());
    }
    cout << ans << endl;
}