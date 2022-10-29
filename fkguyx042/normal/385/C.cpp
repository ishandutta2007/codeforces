#include<stdio.h>  
#include<string.h>  
#include<math.h>  
#define LL int   
#define M 10000005  
bool a[M];  
LL vis[M],c[M];  
void isprime()  
{     
    for(LL i=2;i<M;i++)  
    {  
        if(!a[i]){  
            for(LL j=i;j<M;j+=i)  
            {  
                a[j]=1;  
          
                c[i]+=vis[j];  
            }  
        }  
    }  
    for(LL i=2;i<M;i++)  
    c[i]+=c[i-1];  
}  
int main()  
{  
    LL n,i,j,k,x,m,l,r;  
    while(scanf("%d",&n)!=EOF)  
    {  
        memset(c,0,sizeof(c));  
        memset(a,false,sizeof(a));  
        memset(vis,0,sizeof(vis));  
        for(i=0;i<n;i++)  
        {  
            scanf("%d",&x);  
            vis[x]++;  
        }  
        isprime();  
        scanf("%d",&m);  
        while(m--)  
        {  
            scanf("%d%d",&l,&r);  
            if(l>M)l=M-1;  
            if(r>M)r=M-1;   //  
            printf("%d\n",c[r]-c[l-1]);  
        }  
    }  
    return 0;  
}