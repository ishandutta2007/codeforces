#include <bits/stdc++.h>

using namespace std;

int a,b,c,d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d;
    if(a!=d) {
        cout<<"0";
        return 0;
    }
    if(a==0&&c>0) {
        cout<<"0";
        return 0;
    }
    cout<<"1";
    return 0;
}