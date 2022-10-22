#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k,a[205],ans,res;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        res=0,ans=0;
        for(int i=1;i<=k;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            int res=-1;
            for(int j=1;j<=k;j++){
                if(res==-1)
                    res=abs(i-a[j]);
                else
                    res=min(res,abs(i-a[j]));
            }
            ans=max(ans,res);
        }
        printf("%d\n",ans+1);
    }
}