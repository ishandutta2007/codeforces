#include<cstdio>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
int num[100005];  
int main()  
{  
    int n,k;  
    bool flag=false;  
    scanf("%d%d",&n,&k);  
    for(int i=1;i<=n;++i)  
        scanf("%d",num+i);  
    for(int i=n;i>k;--i)  
        if(num[i]!=num[k])  
        {  
            flag=true;  
            break;  
        }  
    if(flag) printf("-1\n");  
    else  
    {  
        int idx=0;  
        for(int i=n;i>=1;--i)  
            if(num[i]!=num[k])  
            {  
                idx=i;  
                break;  
            }  
        printf("%d\n",idx);  
    }  
    return 0;  
}