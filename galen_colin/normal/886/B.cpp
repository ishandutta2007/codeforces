#include <bits/stdc++.h>
using namespace std;
int main(){
    int pos[500005];
    memset(pos,0,sizeof(pos));
    int n; cin >> n;
    int w;
    for(int i=0;i<n;i++){
        int x;cin>>x;pos[x] = i + 1; w=x;
    }
    for(int x=0;x<300005;x++){
        if(pos[x]<pos[w]&&pos[x]>0)w=x;
    }
    cout<<w<<'\n';
}