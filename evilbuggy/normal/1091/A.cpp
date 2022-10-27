#include <bits/stdc++.h>
using namespace std;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r,b,y;
    cin>>y>>b>>r;
    cout<<min(min(r-2, b-1), y)*3 + 3<<endl;

}