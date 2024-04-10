#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+3;
int _,n,a[maxn],b[maxn],mx;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    mx=0;
    for (int i=1;i<=n;i++){
        a[i]=b[i]+mx;
        mx=max(mx,a[i]);
    }
    for (int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
    return 0;
}