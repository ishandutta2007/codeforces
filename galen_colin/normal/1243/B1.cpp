#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main(){
    int t;cin>>t;
    
    while(t--){
        ll c[500][500];
        memset(c,0,sizeof(c));
        int n; string s,t;
        cin>>n>>s>>t;
        ll ct=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                ++ct;
                ++c[s[i]][t[i]];
            }
        }
        
        bool pos = 1;
        if(ct==2){
            for(int i=0;i<300;i++)for(int j=0;j<300;j++)if(c[i][j]!=2&&c[i][j]!=0)pos=0;
        }else pos=0;
        cout<<(pos?"Yes\n":"No\n");
    }
}