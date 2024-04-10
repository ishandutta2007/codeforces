#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string want = "abacaba";
    int t = want.size();
    int l = -1;
    auto check = [&](int x){
        string curr = s;
        for(int i=x;i<x+t;i++){
            if(curr[i]!=want[i-x] && curr[i]!='?'){
                return false;
            }
            curr[i] = want[i-x];
        }
        int ans = 0;
        for(int i=0;i<n-t+1;i++){
            bool poss = 1;
            for(int j=0;j<t;j++){
                if(curr[i+j] != want[j]){
                    poss = 0;
                }
            }
            if(poss){
                ++ans;
            }
        }
        if(ans==1){
            return true;
        }
        return false;
    };
    for(int i=0;i<n-t+1;i++){
        if(check(i)){
            l = i;
        }
    }
    if(l==-1){
        cout<<"No\n";
        return;
    }
    for(int i=l;i<l+t;i++){
        s[i] = want[i-l];
    }
    cout<<"Yes\n";
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            s[i]='d';
        }
        cout<<s[i];
    }
    cout<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}