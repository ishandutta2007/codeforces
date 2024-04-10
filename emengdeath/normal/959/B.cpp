#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
map<string,int>f;
int n,m,k;
int v[N],d[N];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k>>m;
    for (int i=1;i<=n;i++){
        cin>>s;
        f[s]=i;
    }
    for (int i=1;i<=n;i++)cin>>v[i];
    for (int i=1;i<=k;i++){
        cin>>d[0];
        for (int j=1;j<=d[0];j++)
            cin>>d[j];
        int vv=v[d[1]];
        for (int j=2;j<=d[0];j++)
            vv=min(vv,v[d[j]]);
        for (int j=1;j<=d[0];j++)
            v[d[j]]=vv;
    }
    long long ans=0;
    for (int i=1;i<=m;i++){
        cin>>s;
        ans+=v[f[s]];
    }
    cout<<ans;
    return 0;
}