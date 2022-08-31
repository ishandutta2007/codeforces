#include<bits/stdc++.h>
using namespace std;
int _,n,a[1000005];
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        bool flag=0;
        for (int i=1;i<n;i++) flag|=a[i]>a[i+1];
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}