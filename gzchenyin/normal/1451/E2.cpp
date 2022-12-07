#include<cstdio>
using namespace std;
int n,a[100005],f[100005],f1,f2;
void work1(int x)
{
    printf("AND %d %d\n",1,x);
    fflush(stdout);
    scanf("%d",&a[1]);
}
void work2(int x,int y)
{
    int tmp;
    printf("AND %d %d\n",x,y);
    fflush(stdout);
    scanf("%d",&tmp);
    a[1]=a[x]^tmp;
}
void work3(int x,int y)
{
    int tmp1,tmp2;
    printf("AND %d %d\n",1,x);
    fflush(stdout);
    scanf("%d",&tmp1);
    printf("AND %d %d\n",1,y);
    fflush(stdout);
    scanf("%d",&tmp2);
    a[1]=tmp1|tmp2;
}
int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        printf("XOR %d %d\n",1,i);
        fflush(stdout);
        scanf("%d",&a[i]);
        if(f[a[i]]!=0) 
        {
            f1=f[a[i]];
            f2=i;
        }
        f[a[i]]=i;
    }
    if(f[0]!=0) work1(f[0]);
    else if(f1!=0 && f2!=0) work2(f1,f2);
    else work3(f[1],f[2]);
    printf("!");
    for(int i=1;i<=n;i++)
    {
        if(i==1) printf(" %d",a[1]);
        else printf(" %d",a[1]^a[i]);
    }
}