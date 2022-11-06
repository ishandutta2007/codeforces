#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
string s;
signed main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;s="";
        for(register int i=0;i<n;i++)s+="()";
        cout<<s<<endl;
        for(register int i=0;i<n-1;i++){
            s[2*n-i-2]=')';
            s[2*n-(i+1)*2-1]='(';
            cout<<s<<endl;
        }
    }
    return 0;
}
//()(())