#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
const int maxn=2e5+7;
int n,m,u,v,d[maxn];

int main(){
    scanf("%d",&n);
    for (int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        d[u]++; d[v]++;
    }
    for (int i=1;i<=n;i++) if (d[i]==2) {puts("NO");return 0;}
    puts("YES");
}