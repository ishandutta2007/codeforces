#include<bits/stdc++.h>
using namespace std;
int n;
int l,r;
void did(int &x,int y){
    printf("? %d\n",y);
    fflush(stdout);
    scanf("%d",&x);
}
int main() {
    scanf("%d",&n);
    if ((n/2)&1){
        printf("! -1");
        fflush(stdout);
        return 0;
    } 
    while (1){
        printf("? 1\n");
        fflush(stdout);
        int x,y;
        int l=1,r=n/2;
        scanf("%d",&x);
        printf("? %d\n",n/2+1);
        fflush(stdout);
        scanf("%d",&y);
        if (x==y){
            printf("! %d\n",1);
            fflush(stdout);
            return 0;
        }
        int xx=x,yy=y;
        while (l<=r){
            int mid=(l+r)/2;
            did(xx,mid);
            did(yy,mid+n/2);
            if (xx==yy){
                printf("! %d\n",mid);
                fflush(stdout);
                return 0;
            }
            if ((xx<yy)==(x<y))l=mid+1;
            else
                r=mid-1;
        }
    }
    return 0;
}