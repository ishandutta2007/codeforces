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

    int a, b, c, d;
    cin>>a>>b>>c>>d;
    if(a != d){
        cout<<0<<endl;
    }else if(c == 0){
        cout<<1<<endl;
    }else if(c != 0 && a == 0){
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
    }
}