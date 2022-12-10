#include<cstdio>
int n;
char t[110][110];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf(" %s",t[i]);
  bool ok=true;
  for(int i=0;i<n;i++){
    bool found=false;
    for(int j=0;j<n;j++)found|=t[i][j]=='.';
    ok&=found;
  }
  if(ok){
    for(int i=0;i<n;i++){
      int j=0;
      while(t[i][j]=='E')++j;
      printf("%d %d\n",i+1,j+1);
    }
  }else{
    ok=true;
    for(int i=0;i<n;i++){
      bool found=false;
      for(int j=0;j<n;j++)found|=t[j][i]=='.';
      ok&=found;
    }
    if(ok){
      for(int i=0;i<n;i++){
        int j=0;
        while(t[j][i]=='E')++j;
        printf("%d %d\n",j+1,i+1);
      }
    }else{
      puts("-1");
    }
  }
}