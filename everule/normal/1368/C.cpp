#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n;
    cin>>n;
    cout<<3*n + 4<<'\n';
    cout<<"0 0\n0 1\n1 0\n1 1\n";
    int x=1;
    int y=2;
    for(int i=0;i<n;i++){
        cout<<x<<" "<<y<<"\n";
        cout<<x+1<<" "<<y<<"\n";
        cout<<x+1<<" "<<y-1<<'\n';
        ++y;++x;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}