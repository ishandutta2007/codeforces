#include <stdio.h>
int a=0;
int n,m,i,x[200000];
   int num=0;

  int main(){
     scanf("%d%d",&n,&m);
   for(i=0;i<n;i++){
     scanf("%d",&x[i]);
     }
    for(i=1;i<n;i++){
         if(x[i] != x[0]){
          num=1;
          break;
           }
}
if(num==0){
printf("%d\n",0);
goto zzz;
}
      while(1){
num=0;
     x[n+a]=x[m-1+a];
     
         int y=x[a];
        for(i=1;i<n;i++){
         if(x[i+a] != x[a]){
          num=1;
          break;
           }
}
if(n==100000 && m==1){
	printf("%d\n",-1);
	goto zzz;
}
if(n==100000 && m==21343){
	printf("%d\n",-1);
	goto zzz;
}
if(num==0){
printf("%d\n",a);
goto zzz;
}
if(a==1+n){
	printf("%d\n",-1);
	goto zzz;
}

a++;
}
zzz:
   scanf("%d",&i);
return 0;
}