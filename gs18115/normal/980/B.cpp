#include<iostream>
#include<fstream>
using namespace std;

int n,k,i,j,cnt;

int main()
{
    scanf("%d%d",&n,&k);
    puts("YES");
    if(k%2)
    {
        k--;
        for(i=0;i<4;i++)
        {
            cnt=0;
            for(j=0;j<n;j++)
            {
                if(i==0||i==3||j==0||j==n-1)
                {
                    printf(".");
                }
                else if(j==n/2)
                {
                    if(i==1)
                    {
                        printf("#");
                    }
                    else
                    {
                        printf(".");
                    }
                }
                else if(j<n/2)
                {
                    if(k<2)
                    {
                        printf(".");
                    }
                    else
                    {
                        k=k-2;
                        printf("#");
                        cnt++;
                    }
                }
                else
                {
                    if(j<n-cnt-1)
                    {
                        printf(".");
                    }
                    else
                    {
                        printf("#");
                    }
                }
            }
            puts("");
        }
    }
    else
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0||i==3||j==0||j==n-1)
                {
                    printf(".");
                }
                else if(j<=k/2)
                {
                    printf("#");
                }
                else
                {
                    printf(".");
                }
            }
            puts("");
        }
    }
    return 0;
}