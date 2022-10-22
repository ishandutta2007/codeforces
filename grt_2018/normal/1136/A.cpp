#include <bits/stdc++.h>

using namespace std;

int n;
int chap[100*100+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int a,b,i=0; i<n;i++) {
        cin>>a>>b;
        for(int j=a; j<=b;j++)
            chap[j]=i+1;
    }
    int k;
    cin>>k;
    cout<<n - chap[k] + 1;
    return 0;
}