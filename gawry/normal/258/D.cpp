#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,p[1010],a[1010],b[1010];
double t[1010][1010],prev[1010][1010];
main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)scanf("%d",&p[i]);
  for(int i=1;i<=m;i++){
    scanf("%d %d",&a[i],&b[i]);
    --a[i];
    --b[i];
  }
  for(int i=0;i<n;i++)for(int j=i+1;j<=n;j++)t[i][j]=p[i]>p[j];
  for(int z=1;z<=m;z++){
/*for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++)printf("%.3lf ",t[i][j]);
  puts("");
}*/
    int _a=a[z],_b=b[z];
    if(_a>_b)swap(_a,_b);

    for(int i=0;i<n;i++){
      prev[_a][i]=t[_a][i];
      prev[_b][i]=t[_b][i];
      prev[i][_a]=t[i][_a];
      prev[i][_b]=t[i][_b];
    }

    for(int i=0;i<_a;i++){
      t[i][_a]=(prev[i][_a]+prev[i][_b])/2;
    }
    for(int i=_a+1;i<_b;i++){
      t[_a][i]=(prev[_a][i]+1.0-prev[i][_b])/2;
    }
    for(int i=_b+1;i<n;i++){
      t[_a][i]=(prev[_a][i]+prev[_b][i])/2;
    }

    for(int i=0;i<_a;i++){
      t[i][_b]=(prev[i][_b]+prev[i][_a])/2;
    }
    for(int i=_a+1;i<_b;i++){
      t[i][_b]=(prev[i][_b]+1.0-prev[_a][i])/2;
    }
    for(int i=_b+1;i<n;i++){
      t[_b][i]=(prev[_b][i]+prev[_a][i])/2;
    }

    t[_a][_b]=0.5;
/*for(int i=0;i<n;i++){
  for(int j=i+1;j<n;j++)printf("%.3lf ",t[i][j]);
  puts("");
}*/
  }
  double ans=0;
  for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)ans+=t[i][j];
  printf("%.6lf\n",ans);
}