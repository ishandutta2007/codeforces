#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MOD=1000000000+9;
int n,h,t[31][31][31][16],tt[31][31][31][16];
void add(int a,int b,int c,int left,int delta){
  a=min(a,h);
  b=min(b,h);
  c=min(c,h);
  if(a==h)left&=~1;
  if(b==h)left&=~2;
  if(c==h)left&=~4;
  if(!(left&1))a=h;
  if(!(left&2))b=h;
  if(!(left&4))c=h;
  tt[a][b][c][left]+=delta;
  while(tt[a][b][c][left]>=MOD)tt[a][b][c][left]-=MOD;
}
main(){
  scanf("%d %d",&n,&h);
  t[0][0][0][15]=1;
  while(n--){
    memset(tt,0,sizeof(tt));
    for(int a=0;a<=h;a++)for(int b=0;b<=h;b++)for(int c=0;c<=h;c++)for(int left=1;left<16;left++)if(t[a][b][c][left]){
      int aa=left&1,bb=(left&2)>0,cc=(left&4)>0,dd=(left&8)>0;
      add(a+1,b+1,c+1,left,t[a][b][c][left]);
      add(a+1,b+1,0+1,aa+2*bb+4*dd+8*cc,t[a][b][c][left]);
      add(a+1,c+1,0+1,aa+2*cc+4*dd+8*bb,t[a][b][c][left]);
      add(b+1,c+1,0+1,bb+2*cc+4*dd+8*aa,t[a][b][c][left]);
    }
    memcpy(t,tt,sizeof(tt));
  }
  long long ans=0;
  for(int a=0;a<=h;a++)for(int b=0;b<=h;b++)for(int c=0;c<=h;c++)for(int left=1;left<16;left++){
    ans+=t[a][b][c][left];
  }
  ans%=MOD;
  printf("%d\n",(int)ans);
}