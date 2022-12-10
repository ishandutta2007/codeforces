#include<cstdio>
#include<cstring>
char t[110000];
int n;
main(){
  gets(t);
  n=strlen(t);
  int pos=0;
  while(pos<n&&t[pos]=='1')++pos;
  if(pos<n){
    while(pos<n){
      t[pos]=t[pos+1];
      ++pos;
    }
  }else{
    t[n-1]=0;
  }
  puts(t);
}