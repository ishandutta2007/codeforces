#include<bits/stdc++.h>
using namespace std;
const int maxn=6e5+3;
int x[maxn],y[maxn],n;
bool flag=1;

int main(){
    cin >> n;
    for (int i=0;i<n;i++) cin >> x[i] >> y[i];
    if (n%2) flag=0;
    for (int i=0;i<n/2;i++) if (x[i]+x[i+n/2]!=x[0]+x[n/2]) flag=0;
    for (int i=0;i<n/2;i++) if (y[i]+y[i+n/2]!=y[0]+y[n/2]) flag=0;
    if (flag) puts("YES"); else puts("NO");
    return 0;
}