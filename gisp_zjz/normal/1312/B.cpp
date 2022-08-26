#include<bits/stdc++.h>
using namespace std;
int a[1555],_,n;
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a,a+n);
        for (int i=n-1;i>=0;i--) cout << a[i] << ' '; cout << endl;
    }
}