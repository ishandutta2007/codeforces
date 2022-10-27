#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int b, k, x;
    cin>>b>>k;
    int ans = 0;
    b %= 2;
    for(int i = 1; i < k; i++){
        cin>>x;
        ans += b*(x%2);
    }
    cin>>x;
    ans += (x%2);
    if(ans&1)cout<<"odd"<<endl;
    else cout<<"even"<<endl;
}