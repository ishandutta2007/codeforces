#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int q; cin>>q; while(q--) {
        int n; ll k; cin>>n>>k;
        string s; cin>>s; vector<int> pos; for(int i=0; i<n; i++) if (s[i]=='0') pos.push_back(i);
        int curr=0, tg=0;
        while(k>0&&curr<pos.size()) {
            if (pos[curr]-tg<=k) {
                swap(s[pos[curr]], s[tg]);
                k-=pos[curr]-tg;
                curr++; tg++;
            }
            else {
                swap(s[pos[curr]-k], s[pos[curr]]); k=0;
            }
        }
        cout<<s<<endl;
    }
}