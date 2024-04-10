#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int n; cin>>n; int a[n]; for(int i=0; i<n; i++) cin>>a[i];
    bool c=0;
    for(int i=0; i<n; i++) {
        if (a[i]%2==0) a[i]/=2;
        else if (c==0) {
            a[i]=(a[i]-1)/2; c=1;
        }
        else {
            a[i]=(a[i]+1)/2; c=0;
        }
    }
    for(int i=0; i<n; i++) cout<<a[i]<<endl;
}