#include <bits/stdc++.h>

using namespace std;

long long n,k,x;

int main() {
    cin>>n;
    while(n--) {
        cin>>k>>x;
        cout<<9*(k-1)+x<<"\n";
    }
    return 0;
}