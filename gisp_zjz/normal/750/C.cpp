#include<bits/stdc++.h>
#define maxn 230000

using namespace std;
const int inf=21000000;
int n,p,q,k,w,d;

int main(){
    cin >> n; p=inf; q=-inf;
    while (n--){
        scanf("%d%d",&k,&w);
        if (w==1) p=min(p,d); else q=max(q,d);
        d+=k;
    }
    if (q==-inf) printf("Infinity\n"); else
    if (p<=q) printf("Impossible\n"); else printf("%d\n",1899+d-q);
    return 0;
}