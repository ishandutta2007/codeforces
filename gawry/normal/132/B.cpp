#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int n,m,T,nr[110][110],next_nr,min_x[110*110],max_x[110*110],min_y[110*110],max_y[110*110];
char s[110][110];
void next(int &block,int &dir,int &choose){
  int x,y;
  if(dir==0)x=min_x[block]-1,y=choose>0?max_y[block]:min_y[block];
  if(dir==1)y=max_y[block]+1,x=choose>0?max_x[block]:min_x[block];
  if(dir==2)x=max_x[block]+1,y=choose>0?min_y[block]:max_y[block];
  if(dir==3)y=min_y[block]-1,x=choose>0?min_x[block]:max_x[block];
  if(x<0||y<0||x>=n||y>=m||!nr[x][y]){
    if(choose==-1)choose=1;else {
      choose=-1;
      dir=(dir+1)%4;
    }
  }else{
    block=nr[x][y];
  }
}
void go(int x,int y){
  if(nr[x][y]==next_nr)return;
  nr[x][y]=next_nr;
  min_x[next_nr]=min(min_x[next_nr],x);
  min_y[next_nr]=min(min_y[next_nr],y);
  max_x[next_nr]=max(max_x[next_nr],x);
  max_y[next_nr]=max(max_y[next_nr],y);
  if(x&&s[x-1][y]==s[x][y])go(x-1,y);
  if(y&&s[x][y-1]==s[x][y])go(x,y-1);
  if(x+1<n&&s[x+1][y]==s[x][y])go(x+1,y);
  if(s[x][y+1]==s[x][y])go(x,y+1);
}
int seen[110*110][4][2];
main(){
  scanf("%d %d",&n,&T);
  for(int i=0;i<n;i++)scanf(" %s",s[i]);
  m=strlen(s[0]);
  for(int i=0;i<n;i++)for(int j=0;s[i][j];j++)if(s[i][j]!='0'&&!nr[i][j]){
    ++next_nr;
    min_x[next_nr]=min_y[next_nr]=110;
    max_x[next_nr]=max_y[next_nr]=-1;
    go(i,j);
  }
  int step=1,block=1,dir=1,choose=-1;
  while(T){
    if(seen[block][dir][choose==1]){
      T%=step-seen[block][dir][choose==1];
    }
    if(!T)break;
    seen[block][dir][choose==1]=step++;
    next(block,dir,choose);
    --T;
  }
  printf("%c\n",s[min_x[block]][min_y[block]]);
}