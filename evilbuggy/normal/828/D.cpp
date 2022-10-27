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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int n, k;
    cin>>n>>k;
    if((n-1)%k == 0){
        cout<<2*((n-1)/k)<<endl;
    }else if((n-1)%k == 1){
        cout<<2*((n-1)/k) + 1<<endl;
    }else{
        cout<<2*((n-1)/k) + 2<<endl;
    }
    for(int i = 1; i < n; i++){
        if(i <= k)cout<<"1 "<<i + 1<<endl;
        else cout<<(i - k + 1)<<" "<<i + 1<<endl;
    }
}