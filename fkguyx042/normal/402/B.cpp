#include<stdio.h>  
#include<string.h>  
#include<algorithm>  
using namespace std;  
int a[1005];  
int main()  
{  
    int n,k;  
    while(scanf("%d%d",&n,&k)!=EOF)  
    {  
        for(int i=1; i<=n; i++)  
        {  
            scanf("%d",&a[i]);  
        }  
        int id;  
        int minn=1005;  
        for(int i=1; i<=n; i++)  
        {  
            int tmp=a[i];  
            int cnt=0; 
            int flag=0;
            for(int j=1; j<=i; j++)  
            {  
                int ans=tmp-(i-j)*k;  
                if(ans!=a[j] && ans>0)  
                    cnt++;  
                if(ans<=0)  
                {  
                    flag=1;  
                    break;  
                }  
            }  
            if(flag==0)  
            {  
                tmp=a[i];  
  
                for(int j=i+1; j<=n; j++)  
                {  
                    int ans=tmp+(j-i)*k;  
                    if(ans!=a[j] && ans>0)  
                        cnt++;  
                    if(ans<=0)  
                    {  
                        flag=1;  
                        break;  
                    }  
  
                }  
            }  
            if(flag==0)  
            {  
                if(cnt<minn)  
                {  
                    minn=cnt;  
                    id=i;  
                }  
            }  
        }  
        if(minn==0)  
        {  
            printf("0\n");  
        }  
        else  
        {  
            printf("%d\n",minn);  
            //printf("%d\n",id);  
            for(int i=1; i<=id; i++)  
            {  
                int ans=a[id]-(id-i)*k;  
                if(a[i]<ans)  
                    printf("+ %d %d\n",i,ans-a[i]);  
                else if(a[i]>ans)  
                    printf("- %d %d\n",i,a[i]-ans);  
            }  
            for(int i=id+1; i<=n; i++)  
            {  
                int ans=(i-id)*k+a[id];  
                if(a[i]<ans)  
                    printf("+ %d %d\n",i,ans-a[i]);  
                else if(a[i]>ans)  
                    printf("- %d %d\n",i,a[i]-ans);  
            }  
        }  
    }  
    return 0;  
}