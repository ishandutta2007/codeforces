#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAX 100002

using namespace std;

char a[MAX],b[MAX],c[MAX];
int fa[MAX],fb[MAX],fc[MAX],A,B,C;

int solve(char *x,char *y,char *z,int *fx,int *fy,int *fz){
  int X,Y,Z;
  for(X=0;x[X]!='\0';X++);
  for(Y=0;y[Y]!='\0';Y++);
  for(Z=0;z[Z]!='\0';Z++);
  int posy=0,posz=0,j;
  j = 0;
  while(true){
    if(j==X) break;
    if(posy==Y){
      Y=X;
      X=0;
      posy=0;
      y=x;
      break;
    }
    if(x[j]==y[posy]) { posy++; j++; }
    else if(posy) posy = fy[posy];
    else j++;
  }
  j = 0;
  while(true){
    if(j==Y) break;
    if(posz==Z){
      Z=0;
      posz=0;
      break;
    }
    if(y[j]==z[posz]) { posz++; j++; }
    else if(posz) posz = fz[posz];
    else j++;
  }
  return X+Y+Z-posy-posz;
}

int main(int argc, char *argv[]){
  int i,j;
  scanf("%s",a);
  scanf("%s",b);
  scanf("%s",c);
  for(A=0;a[A]!='\0';A++);
  for(B=0;b[B]!='\0';B++);
  for(C=0;c[C]!='\0';C++);

  fa[0]=fa[1]=0;
  for(i=2;i<=A;i++){
    j=fa[i-1];
    while(true){
      if(a[j]==a[i-1]){ fa[i]=j+1; break; }
      if(j==0){ fa[i]=0; break; }
      j=fa[j];
    }
  }

  fb[0]=fb[1]=0;
  for(i=2;i<=B;i++){
    j=fb[i-1];
    while(true){
      if(b[j]==b[i-1]){ fb[i]=j+1; break; }
      if(j==0){ fb[i]=0; break; }
      j=fb[j];
    }
  }

  fc[0]=fc[1]=0;
  for(i=2;i<=C;i++){
    j=fc[i-1];
    while(true){
      if(c[j]==c[i-1]){ fc[i]=j+1; break; }
      if(j==0){ fc[i]=0; break; }
      j=fc[j];
    }
  }
  printf("%d\n",min(min(solve(a,b,c,fa,fb,fc),solve(a,c,b,fa,fc,fb)),min(min(solve(b,a,c,fb,fa,fc),solve(b,c,a,fb,fc,fa)),min(solve(c,a,b,fc,fa,fb),solve(c,b,a,fc,fb,fa)))));
  return 0;
}