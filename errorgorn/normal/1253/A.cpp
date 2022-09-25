#include <cstdio>
using namespace std;
int n;
int a[200005];
int b[200005];
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        scanf("%d",&n);
        for (int x=0;x<n;x++) scanf("%d",&a[x]);
        for (int x=0;x<n;x++) scanf("%d",&b[x]);

        int p1=0;
        int p2=n-1;
        int k;

        while (a[p1]==b[p1] && p1<n) p1++;
        if (p1==n){
            printf("YES\n");
            goto _end;
        }

        while (a[p2]==b[p2]) p2--;

        k=b[p1]-a[p1];
        if (k<0){
            printf("NO\n");
            goto _end;
        }

        for (int x=p1;x<=p2;x++){
            if (b[x]-a[x]!=k){
                printf("NO\n");
                goto _end;
            }
        }

        printf("YES\n");
        _end:;
    }
}