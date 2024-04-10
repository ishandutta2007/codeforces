#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,c,cs;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='('&&c*2<k){
            c++;cs++;
            cout<<'(';
        }
        if(s[i]==')'&&cs){
            cout<<')';
            cs--;
        }
    }
    return 0;
}