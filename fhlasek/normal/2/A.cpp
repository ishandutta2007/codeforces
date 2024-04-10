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

using namespace std;

char name[1001][34];
int p[1001],np[1001];
int names=0;
char inname[1001][34];
int inval[1001];

bool eq(char a[],char b[]){
  int i;
  for(i=0;a[i]==b[i]&&a[i]!='\0'&&b[i]!='\0';i++);
  if(a[i]==b[i]) return true;
  return false;
}

int main(int argc, char *argv[]){
  int N,i,j,m=0;
  bool ok;
  scanf("%d",&N);
  FOR(i,N){ p[i]=0; np[i]=0; }
  FOR(i,N){
    scanf("%s%d",inname[i],inval+i);
    ok=false;
    FOR(j,N) if(eq(name[j],inname[i])){ p[j]+=inval[i]; ok=true; break;}
    if(!ok){
      for(j=0;inname[i][j]!='\0';j++) name[names][j]=inname[i][j];
      name[names][j]='\0';
      p[names]=inval[i];
      names++;
    }
  }
  FOR(i,N) if(p[i]>m) m=p[i];

  FOR(i,N){
    FOR(j,N) if(eq(name[j],inname[i])){
      np[j]+=inval[i];
      if(np[j]>=m&&p[j]==m){
        printf("%s\n",name[j]);
        return 0;
      }
      break;
    }
  }
  return 0;
}