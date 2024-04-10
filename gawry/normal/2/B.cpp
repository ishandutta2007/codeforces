#include<cstdio>
int cnt(int x,int d){
  int r=0;
  while(x%d==0){r++;x/=d;}
  return r;
}
int n,t[1010][1010],m[1010][1010],f[1010][1010];
void calc(int d){
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)m[i][j]=i+j?1000000000:0;
  for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    int c=t[i][j]?m[i][j]+cnt(t[i][j],d):1000000000;
    if(i+1<n&&c<m[i+1][j]){m[i+1][j]=c;f[i+1][j]=1;}
    if(j+1<n&&c<m[i][j+1]){m[i][j+1]=c;f[i][j+1]=0;}
  }
  m[n-1][n-1]=t[n-1][n-1]?m[n-1][n-1]+cnt(t[n-1][n-1],d):1000000000;
}
char ans[2010],*next;
void go(int x,int y){
  if(x+y)if(f[x][y]){
    go(x-1,y);
    *next++='D';
  }else{
    go(x,y-1);
    *next++='R';
  }
}
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&t[i][j]);
  calc(2);
  next=ans;
  go(n-1,n-1);
  int tmp=m[n-1][n-1];
  calc(5);
  if(m[n-1][n-1]<tmp){next=ans;go(n-1,n-1);tmp=m[n-1][n-1];}
  bool zero=0;for(int i=0;i<n;i++)for(int j=0;j<n;j++)zero|=!t[i][j];
  if(!zero||!tmp)printf("%d\n%s\n",tmp>0?tmp:0,ans);else for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(!t[i][j]){
    printf("1\n");
    for(int ii=0;ii<i;ii++)printf("D");
    for(int jj=0;jj<j;jj++)printf("R");
    for(int ii=i;ii+1<n;ii++)printf("D");
    for(int jj=j;jj+1<n;jj++)printf("R");
    puts("");
    return 0;
  }
}