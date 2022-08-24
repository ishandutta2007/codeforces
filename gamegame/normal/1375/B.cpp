#include<stdio.h>
#include<stdlib.h>
 
int main(){
  int t;
  scanf("%d", &t);
 
  while(t--){
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m], flag = 1;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++){
	scanf("%d", &a[i][j]);
 
	if( (i == 0 || i == n - 1) && (j == 0 || j == m-1) &&
	    a[i][j] > 2)
	  flag = 0;
 
	else if(( i == 0 || i == n-1 || j == 0 || j == m-1) &&
		a[i][j] > 3)
	  flag = 0;
 
	else if(a[i][j] > 4)
	  flag = 0;
      }
    
    if(!flag)
      printf("NO\n");
    else{
      printf("YES\n");
      for(int i = 0; i < n; i++){
	for(int j = 0; j < m; j++){
	  if((i == 0 || i == n-1) && (j == 0 || j == m-1))
	     printf("2 ");
 
	  else if(i == 0 || i == n-1 || j == 0 || j == m-1)
	    printf("3 ");
 
	  else
	    printf("4 ");
	}
 
	printf("\n");
      }
    }
    
 
  }
 
  return 0;
}