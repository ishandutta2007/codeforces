#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    for(int i=2,y;i<=n;i++){
        cin>>y;
        x=__gcd(x,y);
    }
    cout<<x*n;
}