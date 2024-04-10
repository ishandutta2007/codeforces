#include <bits/stdc++.h>

using namespace std;

int n;
int last1,last0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        bool t;
        cin>>t;
        if(t) last1 = i+1;
        else last0 = i+1;
    }
    cout<<min(last1,last0);
    return 0;
}