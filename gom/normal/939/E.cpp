#include <bits/stdc++.h>
#define N 500005
using namespace std;
typedef double db;
typedef long long ll;
int q,n=1;
ll csum,t,c[N],s=1;
int main()
{
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        int x;
        scanf("%d",&x);
        if(x==1){
            scanf("%llld",&t);
            c[n++]=t;
            csum-=c[n-2];
            csum+=c[n-1];
            while(csum>=s*c[s]&&s<n-1){
                csum+=c[s++];
            }
        }
        else{
            printf("%.11f\n",(db)t-(db)(csum)/s);
        }
    }
    return 0;
}