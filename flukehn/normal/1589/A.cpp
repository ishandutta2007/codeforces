#include<bits/stdc++.h>
using namespace std;
 
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int u,v;
        cin>>u>>v;
        cout<<1ll*u*u<<" "<<-1ll*v*v<<"\n";
    }
}