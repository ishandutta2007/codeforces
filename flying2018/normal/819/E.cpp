#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(n&1)
    {
        printf("%d\n",(n-1)+(n-1)*((n-3)/2)/2);
        for(int i=2;i<=n;i+=2)
        {
            printf("%d %d %d %d\n%d %d %d %d\n",3,1,i,i+1,3,1,i,i+1);
            for (int j=2;j<i;j+=2)
            printf("%d %d %d %d %d\n%d %d %d %d %d\n",4,i,j,i+1,j+1,4,i,j,i+1,j+1);
        }
    }
    else
    {
        printf("%d\n4 1 2 3 4\n4 1 3 4 2\n4 1 4 2 3\n",(n-2)*(n-2)/4+(n-2));
        for (int i=5;i<=n;i+=2)
        {
            printf("%d %d %d %d\n",3,1,i,i+1);
            printf("%d %d %d %d\n",3,2,i,i+1);
            printf("%d %d %d %d %d\n",4,1,i,2,i+1);
            for(int j=3;j<i;j+=2)
            printf("%d %d %d %d %d\n%d %d %d %d %d\n",4,i,j,i+1,j+1,4,i,j,i+1,j+1);
        }
    }
}