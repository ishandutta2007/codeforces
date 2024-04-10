#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+10;
int n;
int a[MAXN];
int cnt[MAXN];
vector<int>incr;
vector<int>decr;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<n;i++) {
        cnt[a[i]]++;
        if(cnt[a[i]]==3) {
            cout<<"NO\n";
            return 0;
        }
        if(cnt[a[i]]==1) {
            incr.push_back(a[i]);
        }
        else {
            decr.push_back(a[i]);
        }
    }
    sort(incr.begin(),incr.end());
    sort(decr.begin(),decr.end());
    reverse(decr.begin(),decr.end());
    cout<<"YES\n"<<incr.size()<<"\n";
    for(auto it:incr) cout<<it<<" ";
    cout<<"\n"<<decr.size()<<"\n";
    for(auto it:decr) cout<<it<<" ";
    return 0;
}