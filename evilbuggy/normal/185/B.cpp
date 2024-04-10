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

    ld s, a, b, c;
    cin>>s>>a>>b>>c;
    if(s == 0){
        cout<<0<<" "<<0<<" "<<0<<endl;
    }else if(a == 0 && b == 0 && c == 0){
        cout<<0<<" "<<0<<" "<<0<<endl;
    }else{
        ld ss = a + b + c;
        cout<<a*s/ss<<" "<<b*s/ss<<" "<<c*s/ss<<endl;
    }
}