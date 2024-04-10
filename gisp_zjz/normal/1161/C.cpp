#include<bits/stdc++.h>
using namespace std;
int a[100],n,mn,c;
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    mn=a[1]; for (int i=2;i<=n;i++) mn=min(mn,a[i]);
    for (int i=1;i<=n;i++) if (mn==a[i]) ++c;
    if (c<=n/2) puts("Alice"); else puts("Bob");
    return 0;
}