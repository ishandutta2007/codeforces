#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int _,n;
ll sum;
int main(){
    cin >> _;
    while (_--){
        sum=0; cin >> n;
        int x=0;
        for (int i=0;i<n;i++){
            cin >> x;
            sum+=x;
        }
        if (sum%n) puts("1"); else puts("0");
    }
    return 0;
}