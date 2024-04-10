#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
char a[303][303];  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        getchar();  
        for(int i=1;i<=n;i++)  
        {  
            for(int j=1;j<=n;j++)  
            {  
                scanf("%c",&a[i][j]);  
            }  
            getchar();  
        }  
        char c=a[1][1];  
        int flag=0;  
        int k=n;  
        for(int i=1;i<=n;i++)  
        {  
            if(a[i][i]!=c || a[i][k]!=c)  
            {  
                flag=1;  
                break;  
            }  
            a[i][i]='&';  
            a[i][k]='&';  
            k--;  
        }  
        if(flag==1)  
        {  
            printf("NO\n");  
        }  
        else  
        {  
            char d=a[1][2];  
            if(d==c)  
            {  
                printf("NO\n");  
            }  
            else  
            {  
                int flag1=0;  
            for(int i=1;i<=n;i++)  
            {  
                for(int j=1;j<=n;j++)  
                {  
                    if(a[i][j]!='&')  
                    {  
                        if(a[i][j]!=d)  
                        {  
                            flag1=1;  
                            break;  
                        }  
                    }  
                }  
                if(flag1==1)  
                break;  
            }  
            if(flag1==1)  
            {  
                printf("NO\n");  
            }  
            else  
            {  
                printf("YES\n");  
            }  
            }  
  
        }  
    }  
    return 0;  
}