#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int pri(int x) {
    for(int i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
int main() {
    int T,n;
    scanf("%d",&T);
    while(T--) {
        int sum=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
            scanf("%d",a+i);
            sum+=a[i];
        }
        if(pri(sum)) {
            printf("%d\n",n-1);
            int FL=0;
            for(int i=1;i<=n;i++)
                if(a[i]%2) {
                    if(FL)printf("%d ",i);
                    else FL=1;
                } else {
                    printf("%d " ,i);
                }
        } else {
            printf("%d\n",n);
            for(int i=1;i<=n;i++)
                printf("%d ",i);
        }
        puts("");
    }
}