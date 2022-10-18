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
#define INF 2000000001

using namespace std;

char names[7][20]={"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"};
bool l[8][8];
char name[30];
int A,B,C;

int get(){
  int i,j;
  FOR(i,7){
    for(j=0;name[j]!='\0'&&names[i][j]!='\0'&&name[j]==names[i][j];j++);
    if(name[j]==names[i][j]) return i;
  }
  return false;
}

int main(int argc, char *argv[]){
  int i,N,a,j,ii,jj;
  scanf("%d",&N); 
  FOR(i,N){
    scanf("%s",name);
    a=get();
    scanf("%s",name);
    scanf("%s",name);
    l[a][get()]=true;
  }
  scanf("%d%d%d",&A,&B,&C);
  int best=INF,aa,bb,cc,diff;
  int f,ff;
  vector<int> x;
  FOR(i,7) x.push_back(i);
  do{
    for(i=1;i<7;i++){
      for(j=1;j<7&&i+j<7;j++){
        aa=A/i;
        bb=B/j;
        cc=C/(7-i-j);
        diff=max(max(abs(aa-bb),abs(aa-cc)),abs(bb-cc));
        if(diff>best) continue;
        ff=0;
        FOR(ii,i) FOR(jj,i) if(l[x[ii]][x[jj]]) ff++;
        FOR(ii,j) FOR(jj,j) if(l[x[i+ii]][x[i+jj]]) ff++;
        FOR(ii,7-i-j) FOR(jj,7-i-j) if(l[x[i+j+ii]][x[i+j+jj]]) ff++;
        if(diff<best||ff>f){
          best=diff;
          f=ff;
        }
      }
    }
  }while(next_permutation(x.begin(),x.end()));
  printf("%d %d\n",best,f);
  return 0;
}