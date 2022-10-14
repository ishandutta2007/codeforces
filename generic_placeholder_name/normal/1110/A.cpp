#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int b, k, odd=0; cin>>b>>k; int a[k]; for(int i=0; i<k; i++) cin>>a[i];
    if(b%2==0) cout<<(a[k-1]%2==0?"even":"odd");
    else {
        for(int i=0; i<k; i++) {
            if (a[i]%2==1) odd++;
        }
        cout<<(odd%2==0?"even":"odd");
    }
}