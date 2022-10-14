#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool valid(int n) {
    int chk[10]={0};
    while(n>0) {
        if(chk[n%10]==1) return 0;
        else chk[n%10]=1;
        n/=10;
    }
    return 1;
}

int main () {
    int a, b; cin>>a>>b;
    
    for(int i=a; i<=b; i++) {
        if(valid(i)) {
            cout<<i; return 0;
        }
    }
    cout<<-1;
}