#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int q; cin>>q; while(q--) {
        int n; cin>>n;string s[n]; int x=0, y=0, odd=0; for(int i=0; i<n; i++) {cin>>s[i];if(s[i].length()%2!=0)odd++;for(int j=0; j<s[i].length(); j++) if(s[i][j]=='0')x++; else y++;}
        if(odd==0) {
            if(x%2==0) cout<<n; else cout<<n-1;cout<<endl;
        }
        else cout<<n<<endl;
    }
}