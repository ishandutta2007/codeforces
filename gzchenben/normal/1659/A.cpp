// 6 13
// 1B2B3B4B5B6B7
#include<cstdio>
using namespace std;
int n,t,r,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&r,&b);
        int tmp = r/(b+1); // seg : tmp / tmp+1
        int L = r - tmp * (b+1);
        int S = (b+1) - L; 
        for(int i=1;i<=S;i++)
        {
            for(int j=1;j<=tmp;j++) printf("R");
            if(i!=S) printf("B");
        }
        for(int i=1;i<=L;i++)
        {
            printf("B");
            for(int j=1;j<=tmp+1;j++) printf("R");
        }
        printf("\n");
    }
}