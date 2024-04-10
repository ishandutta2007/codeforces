#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
const string subseq = "codeforces";
void solve(){
    ll k;
    cin>>k;
    ll ans=1;
    multiset<int> values;
    for(int i=0;i<subseq.size();i++){
        values.insert(1);
    }
    while(ans < k){
        int x = *values.begin();
        values.erase(values.begin());
        ans/=x;
        ans*=x+1;
        values.insert(x + 1);
    }
    int idx = 0;
    for(const auto &times : values){
        for(int i=0;i<times;i++){
            cout<<subseq[idx];
        }
        ++idx;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}