#include<stdio.h>
main(){
   char s[10010];
   scanf("%s",s);
   int m;
   scanf("%d",&m);
   while(m--){
    int l,r,k;
    scanf("%d %d %d",&l,&r,&k);
    l--;
    r--;
    k=k%(r-l+1);
    char s1[10010];
    for(int i=0;s[i]!=0;i++)
        s1[i]=s[i];

    int l1=l+((r-l+1)-k);
    for(int i=l;i<=r;i++,l1++){
        if(l1>r)
            l1=l;
        s1[i]=s[l1];
    }
    for(int i=0;s[i]!=0;i++)
        s[i]=s1[i];

   }
    printf("%s",s);
}