#include <bits/stdc++.h>

using namespace std;

int n;
int a[101];
int c[101],d[101];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ile=0,ile2=0;
    for(int i=0; i<n;i++) {
        if(i%2==0){c[i/2] = a[i];ile++;}
        else {d[i/2] = a[i];ile2++;}
    }
    for(int i=ile2-1; i>=0;i--) {
        c[ile] = d[i];
        ile++;
    }
    for(int i=0; i<n;i++) cout<<c[i]<<" ";
    return 0;
}