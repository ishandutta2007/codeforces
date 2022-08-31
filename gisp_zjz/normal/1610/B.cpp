#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=998244353;
int n,a[maxn],b[maxn],m,_;
bool check(int x){
    m=0;
    for (int i=1;i<=n;i++) if (a[i]!=x) b[++m]=a[i];
    for (int i=1;i<=m/2;i++) if (b[i]!=b[m+1-i]) return 0;
    return 1;
}
int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int p=-1,q=-1;
        for (int i=1;i<=n/2;i++) if (a[i]!=a[n+1-i]) {p=a[i];q=a[n+1-i];break;}
        if (p==-1) {puts("YES");continue;}
        if (check(p)||check(q)) puts("YES"); else puts("NO");
    }
    return 0;
}