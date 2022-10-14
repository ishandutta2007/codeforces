#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int q; cin>>q; while(q--) {
        int n, r, p, s; cin>>n>>r>>p>>s; string S, ans; cin>>S; int cnt=0;
        for(int i=0; i<n; i++) ans.push_back('0');
        for(int i=0; i<n; i++) {
            if(S[i]=='R'&&p>0) {ans[i]='P'; p--; cnt++;}
            else if(S[i]=='P'&&s>0) {ans[i]='S'; s--; cnt++;}
            else if(S[i]=='S'&&r>0) {ans[i]='R'; r--; cnt++;}
        }
        for(int i=0; i<n; i++) {
            if(ans[i]=='0') {
                if(r>0) {ans[i]='R'; r--;}
                else if(p>0) {ans[i]='P'; p--;}
                else {ans[i]='S'; s--;}
            }
        }
        if(cnt<(n+1)/2) cout<<"NO\n";
        else {cout<<"YES\n"; for(int i=0; i<n; i++) cout<<ans[i]; cout<<endl;}
    }
}