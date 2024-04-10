#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+3;
int a[maxn],_,n;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        int pos=-1;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<n;i++) if (abs(a[i]-a[i+1])>=2) pos=i;
        if (pos==-1) puts("NO");
        else printf("YES\n%d %d\n",pos,pos+1);
    }
    return 0;
}