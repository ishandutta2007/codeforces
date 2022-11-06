#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
using namespace std;
int a[N];
void work(int l,int r)
{
    if(r-l==1)
    {
        if(a[l]<a[r]){printf("! %d\n",l);exit(0);}
        else{printf("! %d\n",r);exit(0);}
    }
    if(r-l==2)
    {
        printf("? %d\n",l+1);fflush(stdout);
        scanf("%d",&a[l+1]);
        if(a[l]>a[l+1] && a[l+1]<a[r]){printf("! %d\n",l+1);exit(0);}
        if(a[l]<a[l+1]){printf("! %d\n",l);exit(0);}
        printf("! %d\n",r);
        exit(0);
    }
    int mid=(l+r)>>1;int m1=mid+1;
    printf("? %d\n",mid);fflush(stdout);
    scanf("%d",&a[mid]);
    printf("? %d\n",mid+1);fflush(stdout);
    scanf("%d",&a[mid+1]);
    if(a[mid]>a[mid+1]) work(mid+1,r);
    else work(l,mid);
}
int main()
{
    int n;
    scanf("%d",&n);
    if(n==1){puts("! 1");return 0;}
    printf("? %d\n",1);fflush(stdout);
    scanf("%d",&a[1]);
    printf("? %d\n",n);fflush(stdout);
    scanf("%d",&a[n]);
    work(1,n);
    return 0;
}