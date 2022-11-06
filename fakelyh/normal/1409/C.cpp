#include<bits/stdc++.h>
using namespace std;
int t,n,a[55],x,y;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&x,&y);
        register long long ans=1ll<<60;
        for(register int i=1;i<=y-x;i++){
            if((y-x)%i)continue;
            register int k=x/i,z,q;
            if(k*i==x)k--;
            q=z=x-k*i;
            k++;
            k+=(y-x)/i;
            // if(i==6&&n==6)printf("%d %d\n",k,z);
            while(k>n)z+=i,k--,q+=i;
            while(z+(n-1)*i<y)z+=i,q+=i;
            if(q>x)continue;
            if(z+(n-1)*i<ans){
                ans=y+(n-k)*i;
                for(register int j=1;j<=n;j++)a[j]=q,q+=i;
            }
        }
        for(register int j=1;j<=n;j++)printf("%d ",a[j]);puts("");
    }
    return 0;
}