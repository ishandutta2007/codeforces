#include <bits/stdc++.h>

using namespace std;

string s,t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s>>t;
    if(s.size()!=t.size()) {
        cout<<"No"; return 0;
    }
    for(int i=0; i<s.size();i++)
    {
        bool v1=0,v2=0;
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') v1=1;
        if(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u') v2=1;
        if(v1!=v2) {
            cout<<"No"; return 0;
        }
    }
    cout<<"Yes";
    return 0;
}