#include <stdio.h>
int dp[1<<24];
int n;
int main(){
  scanf("%d",&n);
  for(int I=0;I<n;I++){
    char s[5]; scanf("%s",&s); int v=0;
    for(int j=0;j<3;j++) v |= (1<<(s[j]-'a'));
    dp[v]++;
  }
  for(int I=0;I<24;I++) for(int j=0;j<(1<<24);j++) if(((j>>I)&1)) dp[j]+=dp[j^(1<<I)];
  int ret=0;
  for(int j=0;j<(1<<24);j++) ret^=(n-dp[j])*(n-dp[j]);
  printf("%d%c",ret,10);
}