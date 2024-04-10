#include <stdio.h>
#include <string.h>

int main()
{
   int m,s,i,n[200],ns=0;
   scanf("%d %d",&m,&s);
   
   if(s==0 && m==1) puts("0 0");
   
   else if(s<1 || s>9*m) puts("-1 -1"); 
   
   else {
   //menor numero
    memset(n,0,sizeof(n));
    n[0]=1;
    ns=1;
    for(i=m-1;i>=0;i--)
    {
           if(s-ns > 9-n[i])
           {
                   ns = ns + 9 - n[i];
                   n[i]=9;
           }
           else
           {
                   n[i] = n[i] + s - ns;
                   break;
           }       
    }
    for(i=0;i<m;i++) printf("%d",n[i]);
    printf(" ");
    
    //maior numero
    for(i=0;i<200;i++) n[i] = 9;
    ns=9*m;
    for(i=m-1;i>=0;i--)
    {
           if(ns-s > 9)
           {
                   ns = ns - 9;
                   n[i]=0;
           }
           else
           {
                   n[i] = n[i] + s - ns;
                   break;
           }       
    }
    for(i=0;i<m;i++) printf("%d",n[i]);
    puts("");
   }
   
    return 0;
}