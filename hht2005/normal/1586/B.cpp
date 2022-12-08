#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int in[N];
int main() {
    int T,n,m,a,b,c;
    scanf("%d",&T);
    while(T--) {
        int rt=-1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            in[i]=0;
        for(int i=1;i<=m;i++) {
            scanf("%d%d%d",&a,&b,&c);
            in[b]=1;
        }
        for(int i=1;i<=n;i++)
            if(!in[i]) {
                rt=i;
                break;
            }
        for(int i=1;i<=n;i++)
            if(i!=rt)printf("%d %d\n",i,rt);
    }
    return 0;
}