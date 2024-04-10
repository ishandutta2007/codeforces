#include<cstdio>
using namespace std;
int a,b,t,Xor[300005];
int main()
{
    for(int i=1;i<=3e5;i++) Xor[i]=Xor[i-1]^i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        int tmp=Xor[a-1];
        if((tmp^b)==0) printf("%d\n",a);
        else if((tmp^b)!=a) printf("%d\n",a+1);
        else printf("%d\n",a+2);
    }
}