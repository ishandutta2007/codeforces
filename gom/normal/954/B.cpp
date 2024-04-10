#include <bits/stdc++.h>
#define N 105
using namespace std;
int n,ans;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    ans=n;
    for(int i=1;i<=n;i+=2){
        bool yes=true;
        for(int j=0;j<=i/2;j++){
            if(s[j]!=s[j+i/2+1]){
                yes=false;
                break;
            }
        }
        if(yes)
            ans=min(ans,n-1-i+(i+1)/2+1);
    }
    cout<<ans;
    return 0;
}