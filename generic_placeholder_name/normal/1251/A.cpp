#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int q; cin>>q; while(q--) {
        string s; cin>>s; for(int i=1; i<s.length(); i++) if(s[i]==s[i-1]) {s.erase(i-1, 2);i--;}sort(s.begin(), s.end()); for(int i=1; i<s.length(); i++) if(s[i]==s[i-1]) {s.erase(i, 1); i--;}
        cout<<s<<endl;
    }
}