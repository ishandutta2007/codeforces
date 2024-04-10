#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+3;
int pre[maxn],suf[maxn],n,a[maxn],id;
int ask(int id){
    int x=pre[id-1]|suf[id+1];
    return (a[id]|x)-x;
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    pre[0]=0; for (int i=1;i<=n;i++) pre[i]=pre[i-1]|a[i];
    pre[n+1]=0; for (int i=n;i;i--) suf[i]=suf[i+1]|a[i];
    id=1;
    for (int i=2;i<=n;i++) if (ask(id)<ask(i)) id=i;
    printf("%d",a[id]);
    for (int i=1;i<=n;i++) if (i!=id) printf(" %d",a[i]); puts("");
    return 0;
}