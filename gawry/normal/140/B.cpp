#include<cstdio>
int n,t[310][310],p[310],r[310],when[310],best[310][2];
main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&t[i][j]);
  for(int j=1;j<=n;j++)scanf("%d",&p[j]); 
  best[0][0]=best[0][1]=n+1;
  for(int j=1;j<=n;j++){
    best[j][0]=best[j-1][0];
    best[j][1]=best[j-1][1];
    int pos=1;
    while(p[pos]!=j)++pos;
    if(pos<best[j][0]){
      best[j][1]=best[j][0];
      best[j][0]=pos;
    }else if(pos<best[j][1]){
      best[j][1]=pos;
    }
  }
  for(int i=1;i<=n;i++)for(int j=n;j>=1;j--){
    int nr=t[i][j];
    if(nr==i)continue;
    for(int k=1;k<=n;k++)if(p[best[k][0]]==nr||p[best[k][0]]==i&&p[best[k][1]]==nr){
      r[i]=k;
  //    printf("%d %d %d\n",i,j,k);
    }
  }
  for(int j=1;j<=n;j++)printf("%d%c",r[j],j<n?' ':'\n');
}