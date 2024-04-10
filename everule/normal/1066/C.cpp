#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
const int MAXID=2e5;
void solve(){
    int Q;
    cin>>Q;
    vector<int> map(MAXID+1);
    int lidx=0;
    int ridx=1;
    while(Q--){
        char type;
        cin>>type;
        if(type=='L'){
            int id;
            cin>>id;
            map[id]=lidx;
            --lidx;
        }
        else if(type=='R'){
            int id;
            cin>>id;
            map[id]=ridx;
            ++ridx;
        }
        else{
            int id;
            cin>>id;
            int ans;
            ans=min(map[id]-lidx, ridx-map[id])-1;
            cout<<ans<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}