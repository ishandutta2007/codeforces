#include <stdio.h>
#include <string.h>
char x[30001][21];
int n,h=0;
int main(){
scanf("%d",&n);
for(int i=0;i<n;i++){
scanf("%s",x[i]);
}
for(int i=0;i<strlen(x[0]);i++){
for(int j=0;j<n-1;j++){
if(x[j][i]!=x[j+1][i]){
h=1;
break;
}
}
if(h==1){
printf("%d\n",i);
break;
}
}
return 0;
}