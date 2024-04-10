#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char s[10][10];
bool ok[10][10],ok2[10][10];
main(){
  for(int i=0;i<8;i++)scanf(" %s",s[i]);
  for(int i=0;i<8;i++)for(int j=0;j<8;j++)ok[i][j]=s[i][j]=='M';
  for(int z=0;z<100;z++){
    memset(ok2,0,sizeof(ok2));
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)if(ok[i][j])for(int ii=max(0,i-1);ii<=min(7,i+1);ii++)for(int jj=max(0,j-1);jj<=min(7,j+1);jj++)ok2[ii][jj]=s[ii][jj]!='S';
    memcpy(ok,ok2,sizeof(ok));
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)if(ok[i][j]&&s[i][j]=='A'){
      puts("WIN");
      return 0;
    }
    for(int i=7;i;i--)for(int j=0;j<8;j++)s[i][j]=s[i-1][j]!='A'?s[i-1][j]:'.';
    for(int j=0;j<8;j++)s[0][j]='.';
    s[0][7]='A';
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)ok[i][j]&=s[i][j]!='S';
  }

  puts("LOSE");
}