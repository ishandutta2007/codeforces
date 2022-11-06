#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,a[4][4]={1,0,0,1,0,1,1,0,0,1,1,0,1,0,0,1};
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=m;j++)cout<<a[(j-1)%4][(i-1)%4]<<' ';
    }
    return 0;
}
/*
1 0 0 1 1 0 0 1
0 1 1 0 0 1 1 0
0 1 1 0 0 1 1 0
1 0 0 1 1 0 0 1
*/