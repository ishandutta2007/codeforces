#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char s[110];
int n;
bool t[52][220][2],tt[52][220][2];
main(){
  scanf(" %s %d",s,&n);
  t[0][110][0]=t[0][110][1]=true;
  for(int i=0;s[i];i++){
    memset(tt,0,sizeof(tt));
    for(int cnt=0;cnt<=n;cnt++)for(int pos=1;pos<219;pos++)for(int dir=0;dir<2;dir++)if(t[cnt][pos][dir]){
      if(s[i]=='T'){
        tt[cnt][pos][dir^1]=true;
        tt[cnt+1][pos+2*dir-1][dir]=true;
      }else{
        tt[cnt+1][pos][dir^1]=true;
        tt[cnt][pos+2*dir-1][dir]=true;
      }
    }
    memcpy(t,tt,sizeof(tt));
  }
  int ans=0;
  for(int i=0;i<=n;i++)if((n-i)%2==0)for(int j=0;j<210;j++)for(int k=0;k<2;k++)if(t[i][j][k])ans=max(ans,abs(j-110));
  printf("%d\n",ans);
}