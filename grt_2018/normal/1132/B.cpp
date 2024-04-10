#include <bits/stdc++.h>

using namespace std;

int n,m;
long long s;
int a[3*1000*100+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {cin>>a[i]; s+=a[i];}
    sort(a,a+n);
    reverse(a,a+n);
    cin>>m;
    while(m--) {
        int b;
        cin>>b;
        cout<<s - a[b-1]<<"\n";
    }
    return 0;
}