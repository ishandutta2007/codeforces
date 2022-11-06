#include<bits/stdc++.h>
using namespace std;
int t,n,a,last;
int main(){
    scanf("%d",&t);
    // printf("%d\n",t);
    while(t--){
        scanf("%d",&n);last=0;
        // printf("%d\n",n);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            if(a&&!last){last=i;/*printf("%d\n",last);*/continue;}
            if(a)ans+=i-last-1,last=i;
        }
        printf("%d\n",ans);
    }
    return 0;
}