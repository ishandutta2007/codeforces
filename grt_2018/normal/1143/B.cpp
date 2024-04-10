#include <bits/stdc++.h>

using namespace std;

string s;
int ans;

int product(string q) {
    int an = 1;
    for(int i=0; i<q.size();i++) an*=(q[i]-'0');
    return an;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    ans = product(s);
    for(int i=s.size()-1; i>=1;i--) {
        s[i]='9';
        if(s[i-1]=='0') continue;
        if(s[i-1]>'1') s[i-1] = s[i-1]-1;
        ans=max(ans,product(s));
    }
    cout<<ans;
    return 0;
}