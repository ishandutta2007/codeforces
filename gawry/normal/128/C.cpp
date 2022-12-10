#include<cstdio>
#define MOD (1000000000+7)
int f[1010][1010],n,m,k;
main(){
  scanf("%d %d %d",&n,&m,&k);
  for(int i=1;i<=1000;i++){
    f[i][0]=1;
    for(int j=1;j<=k;j++){
      f[i][j]=f[i-1][j]*2%MOD;
      if(i>=2)f[i][j]=(f[i][j]+f[i-2][j-1])%MOD;
      if(i>=2)f[i][j]=(f[i][j]+MOD-f[i-2][j])%MOD;
    }
  }
  printf("%d\n",(int)((long long)f[n][k]*f[m][k]%MOD));
}