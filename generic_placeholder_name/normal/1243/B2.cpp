#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(string a, string b) {
    int freq_a[26]={0}, freq_b[26]={0};
    for(int i=0; i<a.length(); i++) {freq_a[a[i]-'a']++; freq_b[b[i]-'a']++;}
    for(int i=0; i<26; i++) if((freq_a[i]+freq_b[i])%2!=0) {cout<<"No\n"; return;}
    cout<<"Yes\n";
    vector<pair<int, int>> change;
    for(int i=0; i<a.length(); i++) {
        if(a[i]!=b[i]) {
            for(int j=i+1; j<a.length(); j++) {
                if(a[j]==a[i]) {
                    swap(a[j], b[i]); change.push_back(make_pair(j, i));
                    break;
                }
                else if(b[j]==a[i]) {
                    swap(b[j], a[i+1]); change.push_back(make_pair(i+1, j));
                    swap(a[i+1], b[i]); change.push_back(make_pair(i+1, i));
                    break;
                }
            }
        }
    }
    cout<<change.size()<<endl;
    for(int i=0; i<change.size(); i++) cout<<change[i].first+1<<" "<<change[i].second+1<<endl;
}

int32_t main() {
    int q; cin>>q; while(q--) {
        int n; string a, b; cin>>n>>a>>b; solve(a, b);
    }
}