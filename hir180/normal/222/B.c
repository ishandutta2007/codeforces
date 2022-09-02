int b[1001][1001],r[1001],c[1001];
int n,m,k;

int main()
{
  int i,j,x,y,a;
  char op;
  scanf("%d%d%d",&n,&m,&k);
      for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&b[i][j]);
    for(i=1;i<=n;i++) r[i]=i;
    for(i=1;i<=m;i++) c[i]=i;
    while(k--)
    {
      getchar();
      scanf("%c %d %d",&op,&x,&y);
      if(op=='r') {
a=r[x];r[x]=r[y];r[y]=a;
}
      if(op=='c') {
a=c[x];c[x]=c[y];c[y]=a;
}
      if(op=='g')
 printf("%d\n",b[r[x]][c[y]]);
    }
    return 0;
}