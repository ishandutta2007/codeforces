#include <stdio.h>
  int main(){
	  int x[101][7];
	  int n,y,i,j,num=0;
	  scanf("%d%d",&n,&y);
	   x[1][1]=y;
	   x[1][6]=7-y;
	  for(i=1;i<=n;i++){
		 scanf("%d%d",&x[i][2],&x[i][3]);
		  x[i][5]=7-x[i][2];
		  x[i][4]=7-x[i][3];
	  }
	  for(i=2;i<=n;i++){
		 if(x[i][2]==x[i-1][6]){
			 num=1;
			 break;
		 }
		 if(x[i][5]==x[i-1][6]){
			 num=1;
			 break;
		 }
		 if(x[i][3]==x[i-1][6]){
			 num=1;
			 break;
		 }
		 if(x[i][4]==x[i-1][6]){
			 num=1;
			 break;
		 }
                 x[i][6]=x[i-1][6];
	  }
	  if(num==0){
		  printf("YES\n");
	  }else{
		  printf("NO\n");
	  }
	  return 0;
  }