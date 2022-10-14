#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int q; cin>>q; while(q--) {
        string s; cin>>s; vector<int> n[2];
        for(int i=0; i<s.length(); i++) n[(s[i]-48)%2].push_back(s[i]-48);
        int ptr0=0, ptr1=0;
        while (ptr0<n[0].size()&&ptr1<n[1].size()) {
            if(n[0][ptr0]<n[1][ptr1]) {cout<<n[0][ptr0]; ptr0++;}
            else {cout<<n[1][ptr1]; ptr1++;}
        }
        if(ptr0<n[0].size()) for(;ptr0<n[0].size(); ptr0++) cout<<n[0][ptr0];
        if(ptr1<n[1].size()) for(;ptr1<n[1].size(); ptr1++) cout<<n[1][ptr1];
        cout<<endl;

    }
}