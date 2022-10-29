#include<bits/stdc++.h>
using namespace std;
int bz[1001];
int to[1001];
int n;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&to[i]);
    for (int i=1;i<=n;i++){
        int x=i;
        while (bz[x]!=i){
            bz[x]=i;
            x=to[x];
        }
        printf("%d ",x);
    }
    return 0;
}