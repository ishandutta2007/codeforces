#include<bits/stdc++.h>
using namespace std;
int a,b,ans,n;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    cin>>s;
    for (int i=0;i<n;i++)
        if (s[i]=='.'){
            if (i&&s[i-1]=='B'){
                if (a)a--,s[i]='A',ans++;
            }else
            if (i&&s[i-1]=='A'){
                if (b)b--,s[i]='B',ans++;
            }else
            if (a>=b){
                if (a)a--,s[i]='A',ans++;
            }else
                if (b)b--,s[i]='B',ans++;
        }
    cout<<ans;
    return 0;
}