#include<iostream>
#include<fstream>
using namespace std;

char c[234567];

int n,a,b,i,cnt,flag=2;

int main()
{
    scanf("%d %d %d\n",&n,&a,&b);
    for(i=0;i<n;i++)
    {
        scanf("%c",&c[i]);
        if(a==0&&b==0)break;
        if(c[i]=='.')
        {
            if(flag==1&&a>0)
            {
                cnt++;
                a--;
                flag=0;
            }
            else if(flag==0&&b>0)
            {
                cnt++;
                b--;
                flag=1;
            }
            else if(flag==2)
            {
                cnt++;
                if(a>b)
                {
                    a--;
                    flag=0;
                }
                else
                {
                    b--;
                    flag=1;
                }
            }
            else
            {
                flag=2;
            }
        }
        else
        {
            flag=2;
        }
    }
    printf("%d",cnt);
    return 0;
}