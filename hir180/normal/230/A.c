#include <stdio.h>
  int main(){
	  int n,m,a[1000],b[1000],c[1000]={},d[1000]={},i,num=0,sum=0;
	  scanf("%d%d",&n,&m);
	  for(i=0;i<m;i++){
		  scanf("%d%d",&a[i],&b[i]);
	  }num=1;
	  while(num==1){
		  num=0;
		  for(i=0;i<m;i++){
			  if(d[i]==0){
		  if(n>a[i]){
			  n+=b[i];
			  num=1;
			  c[i]=1;
			  d[i]=1;
		  }
			  }}
	  }
	  for(i=0;i<m;i++){
		  sum+=c[i];
	  }
	  if(sum==m) printf("YES\n");
	  else printf("NO\n");
	  return 0;
  }