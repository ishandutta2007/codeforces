#include <bits/stdc++.h>

using namespace std;

int n,res,s=1e4,d=1e9+7,f[1005][20005];
//lel copy antimatter

main(){cin>>n;
    for(int i=1,x;i<=n;++i){
        cin>>x,++f[i][s-x],++f[i][s+x];
        for(int k=-s;k<=s;++k)
            f[i][s+k]=(f[i][s+k]+(f[i-1][s+k-x]+f[i-1][s+k+x]))%d;
            res=(res+f[i][s])%d;
    }
    cout<<res;
}