#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,s,k;
        scanf("%d%d%d",&n,&s,&k);
        map<int,int> m;
        for(int i=1,x;i<=k;i++)scanf("%d",&x),m[x]=1;
        for(int i=0;i<=k;i++){
            int t=max(s-i,1),y=min(s+i,n);
            if(!m[t]||!m[y]){
                printf("%d\n",i);
                break;
            }
        }
    }
}