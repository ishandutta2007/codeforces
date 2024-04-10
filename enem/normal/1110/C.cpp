#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int a;
        scanf("%d",&a);
        int x=4;
        for(int i=2;i<=25;i++)
        {
            if(a==x-1)
            {
                if(i==4)
                {
                    printf("5\n");
                }
                else if(i==6)
                {
                    printf("21\n");
                }
                else if(i==8)
                {
                    printf("85\n");
                }
                else if(i==9)
                {
                    printf("73\n");
                }
                else if(i==10)
                {
                    printf("341\n");
                }
                else if(i==11)
                {
                    printf("89\n");
                }
                else if(i==12)
                {
                    printf("1365\n");
                }
                else if(i==14)
                {
                    printf("5461\n");
                }
                else if(i==15)
                {
                    printf("4681\n");
                }
                else if(i==16)
                {
                    printf("21845\n");
                }
                else if(i==18)
                {
                    printf("87381\n");
                }
                else if(i==20)
                {
                    printf("349525\n");
                }
                else if(i==21)
                {
                    printf("299593\n");
                }
                else if(i==22)
                {
                    printf("1398101\n");
                }
                else if(i==23)
                {
                    printf("178481\n");
                }
                else if(i==24)
                {
                    printf("5592405\n");
                }
                else if(i==25)
                {
                    printf("1082401\n");
                }
                else
                {
                    printf("1\n");
                }
                break;
            }
            else if(a<x-1)
            {
                printf("%d\n",x-1);
                break;
            }
            x*=2;
        }
    }
    return 0;
}