
#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
     int n;
     scanf("%d",&n);
     int a[n];
     for(int i = 1 ; i <=n ; i++) scanf("%d",&a[i]);
        for(int i = 1 ; i <=n ; i++){ if(i%2==1) if(a[i]<0) a[i]*=-1; if(i%2==0) if(a[i]>0) a[i]*=-1; }
       for(int i = 1 ; i <=n ; i++) printf("%d ",a[i]);
      printf("\n");
      
      
        
    }
    return 0;
}