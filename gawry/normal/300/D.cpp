#include<cstdio>
#include<cstring>
const int MOD=7340033;
int q,n,k,t[40][1010],z[1010],zz[1010];
main(){
  t[0][0]=1;
  for(int cnt=1;cnt<40;cnt++){
    for(int i=0;i<1010;i++)z[i]=t[cnt-1][i];
    for(int k=0;k<2;k++){
      memset(zz,0,sizeof(zz));
      for(int i=0;i<1010;i++)for(int j=0;i+j<1010;j++){
        zz[i+j]=(zz[i+j]+(long long)z[i]*z[j])%MOD;
      }
      memcpy(z,zz,sizeof(z));
    }
    t[cnt][0]=1;
    for(int i=1;i<1010;i++){
      t[cnt][i]=z[i-1];
    }
  }
  //printf("%d\n",t[2][2]);

  scanf("%d",&q);
  while(q--){
    scanf("%d %d",&n,&k);
    int cnt=0;
    while(n>1&&n%2){
      ++cnt;
      n/=2;
    }
    printf("%d\n",t[cnt][k]);
  }
}