#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t, even=0, odd=0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        if(t&1) odd++;
        else even++;
    }
    cout << min(even, odd);
}