#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool vis[2000];

int main(){
    int n,m;
    int a,b;
    int ans;
    cin>>n>>m;
    memset(vis,true,sizeof(vis));
    while(m--){
         cin>>a>>b;
         vis[a]=false;
         vis[b]=false;
    }
    for(int i=1;i<=n;i++){
         if(vis[i]){
            ans=i;
            break;
         }
    }
    printf("%d\n",n-1);
    for(int  i=1;i<=n;i++){
         if(ans!=i)
         printf("%d %d\n",ans,i);
    }
    return 0;
}