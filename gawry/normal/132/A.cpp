#include<cstdio>
char s[110];
int rev(int x){
  int y=0;
  for(int i=0;i<8;i++)if(x&1<<i)y|=1<<7-i;
  return y;
}
main(){
  gets(s);
  int prev=0;
  for(int i=0;s[i];i++){
    int val=rev(s[i]);
    printf("%d\n",(prev+256-val)%256);
    prev=val;
  }
}