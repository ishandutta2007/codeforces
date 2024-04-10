#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> pos(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        pos[--x]=i;
    }
    set<pair<int,int>> values;
    set<int> free;
    vector<int> indexvalue(n, 1);
    for(int i=0;i<n;i++){
        values.insert(mp(1,i));
        free.insert(i);
    }
    free.insert(n);
    for(int i=0;i<n;i++){
        if(indexvalue[pos[i]]!=(*(values.rbegin())).first){
            cout<<"No\n";
            return;
        }
        values.erase(mp(indexvalue[pos[i]], pos[i]));
        free.erase(pos[i]);
        int next=*(free.upper_bound(pos[i]));
        if(next!=n){
            values.erase(mp(indexvalue[next], next));
            indexvalue[next]+=indexvalue[pos[i]];
            values.insert(mp(indexvalue[next], next));
        }
    }
    cout<<"Yes\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    //precompute();
    while(t--){
        //init();
        solve();
    }
}