#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int maxn=1e6+3;
int a[maxn],_,n,m1,m2;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d%d",&n,&m1,&m2);
        int p1=0,p2=0;
        for (int i=1;i<=m1;i++){
            int x;scanf("%d",&x);
            p1=max(p1,x);
        }
        for (int i=1;i<=m2;i++){
            int x;scanf("%d",&x);
            p2=max(p2,x);
        }
        if (p1>p2) puts("YES"); else puts("NO");
    }
    return 0;
}