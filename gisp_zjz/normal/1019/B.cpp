#include<bits/stdc++.h>
#define maxn 234856

using namespace std;
int a[maxn],l,r,mid,p,n,s,t;
int qry(int pos){
    int x; printf("? %d\n",pos+1);
    fflush(stdout);
    scanf("%d",&x);
    return x;
}

int main(){
    cin >> n;
    if (n%4){
        printf("! -1\n");
        return 0;
    }
    p=n/4;
    for (int i=0;i<4;i++) a[p*i]=qry(p*i);
    if (a[0]==a[p*2]) {
        printf("! 1\n");
        return 0;
    }
    else if (a[p]==a[p*3]){
        printf("! %d\n",p+1);
        return 0;
    }
    else if (a[0]>a[p*2]&&a[p]>a[p*3]){
        l=p; r=p*2;
        while (r-l>1){
            mid=(l+r)/2;
            s=qry(mid); t=qry(mid+p*2);
            if (s==t) {
                printf("! %d\n",mid+1);
                return 0;
            }
            else if (s>t) l=mid; else r=mid;
        }
    }
    else if (a[0]<a[p*2]&&a[p]<a[p*3]){
        l=p; r=p*2;
        while (r-l>1){
            mid=(l+r)/2;
            s=qry(mid); t=qry(mid+p*2);
            if (s==t) {
                printf("! %d\n",mid+1);
                return 0;
            }
            else if (s<t) l=mid; else r=mid;
        }
    }
    else if (a[0]<a[p*2]&&a[p]>a[p*3]){
        l=0; r=p;
        while (r-l>1){
            mid=(l+r)/2;
            s=qry(mid); t=qry(mid+p*2);
            if (s==t) {
                printf("! %d\n",mid+1);
                return 0;
            }
            else if (s<t) l=mid; else r=mid;
        }
    }
    else if (a[0]>a[p*2]&&a[p]<a[p*3]){
        l=0; r=p;
        while (r-l>1){
            mid=(l+r)/2;
            s=qry(mid); t=qry(mid+p*2);
            if (s==t) {
                printf("! %d\n",mid+1);
                return 0;
            }
            else if (s>t) l=mid; else r=mid;
        }
    }
    assert(0);
    return 0;
}