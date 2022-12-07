#include<cstdio>
using namespace std;
int t,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        int tmpa=a,tmpb=b;
        while(1)
        {
            if((tmpa | b) == b) break;
            if((a | tmpb) == tmpb) break;
            tmpa++;
            tmpb++;
        }
        if(tmpa==b)
        {
            printf("%d\n",tmpa-a);
        }
        else
        {
            printf("%d\n",tmpa-a+1);
        }
    }
}