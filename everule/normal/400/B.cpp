#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n,m;
    cin>>n>>m;
    set<int> dist;
    for(int i=0;i<n;i++){
        int gidx, sidx;
        for(int j=0;j<m;j++){
            char x;
            cin>>x;
            if(x=='G') gidx = j;
            if(x=='S') sidx = j;
        }
        dist.insert(sidx - gidx);
    }
    if(*dist.begin() < 0){
        cout<<"-1\n";
        return;
    }
    cout<<dist.size()<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}