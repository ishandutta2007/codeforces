#include <stdio.h>
  int main(){
   int a,b,c,d,num=0;
   scanf("%d%d%d%d",&a,&b,&c,&d);
   if(a==b){
	   num++;
   }
   if(a==c){
	   num++;
   }
   if(a==d){
	   num++;
   }
   if(b==c){
	   num++;
   }
   if(b==d){
	   num++;
   }
   if(c==d){
	   num++;
   }
   if(num==0){
	   printf("%d\n",0);
   }else if(num==1){
	   printf("%d\n",1);
   }else if(num==2){
	   printf("%d\n",2);
   }else if(num==3){
	   printf("%d\n",2);
   }else if(num==6){
	  printf("%d\n",3);
   }int i;
   scanf("%d",&i);
return 0;
}