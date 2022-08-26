#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+20;
int n,m,k,_,a[maxn],b[maxn],t,p;

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d%d",&n,&k,&m);
        for (int i=1;i<=m;i++) scanf("%d",&b[i]); t=0;
        if (b[1]-1>0) a[++t]=b[1]-1;
        for (int i=1;i<m;i++) if (b[i+1]-b[i]-1>0) a[++t]=b[i+1]-b[i]-1;
        if (n-b[m]>0) a[++t]=n-b[m];
        bool ok=0;
        p=(k-1)/2;
        if ((n-m)%(p*2)) {puts("NO");continue;}
        int l=0,r=n-m;
        for (int i=1;i<t;i++){
            l+=a[i];
            r-=a[i];
            ok|=l>=p&&r>=p;
        }
        if (ok) puts("YES"); else puts("NO");
    }
    return 0;
}