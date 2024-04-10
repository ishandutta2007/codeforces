#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int a, b; cin>>a>>b; if(a==b) cout<<a<<"1 "<<b<<"2";
    else if(a+1==b) cout<<a<<" "<<b;
    else if(a==9&&b==1) cout<<"9 10";
    else cout<<-1;
}