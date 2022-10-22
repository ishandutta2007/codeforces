#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000*100+1;

int b,k;
bool a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>b>>k;
    for(int x,i=0; i<k;i++) {
        cin>>x;
        a[i]=x%2;
    }
    bool even = 1;
    for(int i=0; i<k-1;i++) {
        if((b%2)*(a[i])==1)
            even=!even;
    }
    if(a[k-1]==1) even=!even;
    if(even) cout<<"even\n";
    else cout<<"odd\n";
    return 0;
}