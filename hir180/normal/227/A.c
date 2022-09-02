#include <stdio.h>
  int main(){
	  double ax,ay,bx,bz,cx,cy;
	  scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&bz,&cx,&cy);
	  if(ax==bx){
		  if(ay>bz){
			  if(cx>ax){
				  printf("LEFT\n");
				  goto aaa;
			  }else if(cx<ax){
				  printf("RIGHT\n");
				  goto aaa;
			  }else{
				  printf("TOWARDS\n");
				  goto aaa;
			  }
		  }
		  if(ay<bz){
			  if(cx<ax){
				  printf("LEFT\n");
				  goto aaa;
			  }else if(cx>ax){
				  printf("RIGHT\n");
				  goto aaa;
			  }else{
				  printf("TOWARDS\n");
				  goto aaa;
			  }
		  }
	  }
	  if(cx==bx){
		  if(cy>bz){
			  if(cx>ax){
				  printf("LEFT\n");
				  goto aaa;
			  }else if(cx<ax){
				  printf("RIGHT\n");
				  goto aaa;
			  }else{
				  printf("TOWARDS\n");
				  goto aaa;
			  }
		  }
		  if(cy<bz){
			  if(cx<ax){
				  printf("LEFT\n");
				  goto aaa;
			  }else if(cx>ax){
				  printf("RIGHT\n");
				  goto aaa;
			  }else{
				  printf("TOWARDS\n");
				  goto aaa;
			  }
		  }
	  }
	 double ab=(ay-bz)/(ax-bx);
	 double bc=(bz-cy)/(bx-cx);
	 if(ab==bc){
		 printf("TOWARDS\n");
		 goto aaa;
	 }
	 if(ab>=0){
		 if(ax>bx){
			 if(bx>cx){
				 printf("RIGHT\n");
				  goto aaa;
			 }else if(bx<cx){
				 printf("LEFT\n");
				  goto aaa;
			 }
		 }
		 else if(ax<bx){
			 if(bx>cx){
				 printf("LEFT\n");
				  goto aaa;
			 }else if(bx<cx){
				 printf("RIGHT\n");
				  goto aaa;
			 }
		 }
	 }else{
		 if(ax<bx){
			 if(bx>cx){
				 printf("RIGHT\n");
				  goto aaa;
			 }else if(bx<cx){
				 printf("LEFT\n");
				  goto aaa;
			 }
		 }
		 else if(ax>bx){
			 if(bx>cx){
				 printf("LEFT\n");
				  goto aaa;
			 }else if(bx<cx){
				 printf("RIGHT\n");
				  goto aaa;
			 }
		 }
	 }
aaa:
	 return 0;
  }