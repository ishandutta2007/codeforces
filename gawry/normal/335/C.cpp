#include<cstdio>
#include<cassert>
int f(char a,char b){
  if(a=='.'&&b=='.')return 0;
  if(a=='.'&&b=='x')return 2;
  if(a=='x'&&b=='.')return 1;
  assert(0);
}
char a[110],b[110];
int n,r,g[110][3][3],seen[1000000],next;
main(){
  g[1][0][0]=1;
  g[1][1][1]=1;
  g[1][2][2]=1;
  g[1][1][0]=1;
  g[1][0][1]=1;
  g[1][2][0]=1;
  g[1][0][2]=1;
  for(int len=2;len<110;len++)for(int left=0;left<=2;left++)for(int right=0;right<=2;right++){
    ++next;
    for(int i=1;i<=len;i++)for(int j=1;j<=2;j++)if(i>1&&i<len||i==1&&(!left||j!=left)||i==len&&(!right||j!=right)){ 
      int tmp=0;
      tmp^=g[i-1][left][3-j];
      tmp^=g[len-i][3-j][right];
      seen[tmp]=next;
    }
    while(seen[g[len][left][right]]==next)++g[len][left][right];
  }

  scanf("%d %d",&r,&n);
  a[0]=b[0]='x';
  a[r+1]=b[r+1]='x';
  for(int i=1;i<=r;i++)a[i]=b[i]='.';
  while(n--){
    int x,y;
    scanf("%d %d",&x,&y);
    if(y==1){
      a[x]='x';
      if(x>1)a[x-1]='x';
      if(x<r)a[x+1]='x';
      b[x]='x';
    }else{
      a[x]='x';
      b[x]='x';
      if(x>1)b[x-1]='x';
      if(x<r)b[x+1]='x';
    }
  }
//  puts(a);
//  puts(b);
  int ans=0,pos=0;
  while(pos<=r)if(a[pos]=='x'&&b[pos]=='x'){
    int pos2=pos+1;
    while(a[pos2]!='x'||b[pos2]!='x')++pos2;
    if(pos2==pos+1){
      ++pos;
      continue;
    }
    int len=pos2-pos-1;
    int prev=f(a[pos+1],b[pos+1]),next=f(a[pos2-1],b[pos2-1]);
  //  printf("%d %d %d\n",len,prev,next);
    ans^=g[len][prev][next];
    pos=pos2;
  }else ++pos;
  printf(ans?"WIN\n":"LOSE\n");
}