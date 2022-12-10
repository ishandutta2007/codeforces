#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MOD 51123987
int n,t[3][151][151][151],choose[510][510];
char s[160];
main(){
  for(int i=0;i<500;i++){
    choose[i][0]=1;
    for(int j=0;j<i;j++)choose[i][j+1]=(choose[i-1][j]+choose[i-1][j+1])%MOD;
  }
  scanf("%d %s",&n,s);
  int prev[3]={-1,-1,-1},cnt[3]={};
  for(int i=0;i<n;i++){
    memset(t[s[i]-'a'],0,sizeof(t[s[i]-'a']));
    for(int x=0;x<=cnt[0];x++)for(int y=0;y<=cnt[1];y++)for(int z=0;z<=cnt[2];z++)for(int k=0;k<3;k++)if(k!=s[i]-'a'&&t[k][x][y][z]){
#define add(a,b) a=(a+b)%MOD
      add(t[s[i]-'a'][x+(s[i]=='a')][y+(s[i]=='b')][z+(s[i]=='c')],t[k][x][y][z]);
    }
    t[s[i]-'a'][(s[i]=='a')][(s[i]=='b')][(s[i]=='c')]=1;
    prev[s[i]-'a']=i;
    cnt[s[i]-'a']++;
  }
  int r=0;
  for(int a=0;a<=n;a++)for(int b=0;b<=n;b++){
    int c=n-a-b;
    if(abs(a-b)>1||abs(a-c)>1||abs(b-c)>1)continue;
    for(int x=0;x<=a;x++)for(int y=0;y<=b;y++)for(int z=0;z<=c;z++){
      int s=(t[0][x][y][z]+t[1][x][y][z]+t[2][x][y][z])%MOD;
      if(!s)continue;
      if(!x&&a||!y&&b||!z&&c)continue;
      r=(r+(long long)(a?choose[a-1][x-1]:1)*(b?choose[b-1][y-1]:1)%MOD*(c?choose[c-1][z-1]:1)%MOD*s)%MOD;
    }
  }
  printf("%d\n",r);
}