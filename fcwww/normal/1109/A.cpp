#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
#define N 300050
#define M 1500050
typedef long long ll;ll ans;
int n,a[N],s[N],c[M][2];
int main() {
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++) scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
    c[0][0]++;
    for(i=1;i<=n;i++) {
        ans+=c[s[i]][i&1];
        c[s[i]][i&1]++;
    }printf("%lld\n",ans);
}