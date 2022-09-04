#include<bits/stdc++.h>
#define N 20005
using namespace std;
main(){
    int a,n;
    scanf("%d %d",&n,&a);
    int ans=0;
    int c[1000];
    for(int i=0;i<n;i++){
            scanf("%d",&c[i]);
    }
    if(c[a-1]==1)
        ans++;
    for(int i=1;a-1+i<n||a-1-i>=0;i++){
        if((a-1+i>=n||c[a-1+i]==1)&&(a-1-i<0||c[a-1-i]==1)){
            if(a-1+i>=n||a-1-i<0)
                ans++;
            else
                ans+=2;
        }
    }
    printf("%d\n",ans);
}