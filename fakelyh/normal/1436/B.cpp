#include<bits/stdc++.h>
using namespace std;
int t,n;
inline bool prime(int x){
    if(x<2)return 0;
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int i=1;
        for(;i<=100000;i++)if((!prime(i))&&prime(i+n-1))break;
        // printf("%d\n",prime(i+n-1));
        for(int j=1;j<=n;j++,puts(""))
        for(int k=1;k<=n;k++)printf("%d ",k^j?1:i);
    }
    return 0;
}