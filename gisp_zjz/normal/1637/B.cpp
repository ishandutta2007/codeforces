#include<bits/stdc++.h>
using namespace std;
int _,n,a[1000005];
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        int sum=0;
        for (int i=1;i<=n;i++){
            int r=i*(n-i+1);
            if (!a[i]) sum+=2*r; else sum+=r;
        }
        cout << sum << endl;
    }
    return 0;
}