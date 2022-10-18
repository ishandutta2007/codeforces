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
#define MAXM 101

using namespace std;

int main(int argc, char *argv[]){
  int T,M;
  int seq[MAXM];
  int t,i,j,n;
  int id=1;
  scanf("%d%d",&T,&M);
  FOR(i,M) seq[i]=0; //free
  char ch,tmp;
  bool ok;
  FOR(t,T){
    scanf("%c",&ch);
    while(ch<'a'||ch>'z') scanf("%c",&ch);
    scanf("%c",&tmp);
    while(tmp>='a'&&tmp<='z') scanf("%c",&tmp);
    if(ch=='d'){ //defragment
      FOR(i,M){
        if(seq[i]!=0){
          j=i-1;
          if(j>=0&&seq[j]==0){
            while(j>0&&seq[j-1]==0) j--;
            seq[j]=seq[i];
            seq[i]=0;
          }
        }
      }
    }
    if(ch=='a'){ //alloc
      scanf("%d",&n);
      FOR(i,M+2){
        if(n>M-i){ printf("NULL\n"); break;}
        ok=true;
        for(j=i;j<i+n;j++) if(seq[j]!=0){ ok=false; break;}
        if(ok){
          printf("%d\n",id);
          FOR(j,n) seq[i+j]=id;
          id++;
          break;
        }
      }
    }
    if(ch=='e'){ //erase
      ok=false;
      scanf("%d",&n);
      if(n==0){ printf("ILLEGAL_ERASE_ARGUMENT\n"); continue; }
      FOR(i,M){
        if(seq[i]==n){
          ok=true;
          seq[i]=0;
        }
      }
      if(ok==false) printf("ILLEGAL_ERASE_ARGUMENT\n");
    }
  }
  return 0;
}