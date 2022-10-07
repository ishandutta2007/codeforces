#include<stdio.h>
char a[100];
int n,i;
int main(){
scanf("%s%d",a,&n);
for(i=0;a[i];i++){
if(a[i]%32<n+1){
a[i]-=32;
if(a[i]<65)a[i]+=32;
}
else{
a[i]+=32;
if(a[i]<0)a[i]-=32;
}
}
printf("%s",a);
}