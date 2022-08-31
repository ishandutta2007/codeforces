#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int M=1000000007;
const int maxn=5e5+5;
int a[maxn],n,m,b[maxn];

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) scanf("%d",&a[i]);
    b[m+1]=n+1;
    for (int i=m;i;i--) b[i]=max(i,b[i+1]-a[i]);
    bool flag=1;
    for (int i=1;i<=m;i++) if ((i-1)+a[i]>n) flag=0;
    if (!flag||b[1]!=1) puts("-1");
    else {
        for (int i=1;i<=m;i++) printf("%d ",b[i]);
        puts("");
    }
    return 0;
}