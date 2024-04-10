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
#define MAXN 100001

using namespace std;

typedef struct{
  int capacity;
  int id;
}Vehicle;

Vehicle kayak[MAXN],catamaran[MAXN];
int res[MAXN];

bool mycompare(Vehicle a,Vehicle b){ return a.capacity>b.capacity; }

int main(int argc, char *argv[]){
  int N,V,k=0,c=0,i,j,type,carry;
  scanf("%d%d",&N,&V);
  FOR(i,N){
    scanf("%d%d",&type,&carry);
    if(type==1){ kayak[k].capacity=carry; kayak[k].id=i+1; k++;}
    else{ catamaran[c].capacity=carry; catamaran[c].id=i+1; c++;}
  }
  sort(kayak,kayak+k,mycompare);
  sort(catamaran,catamaran+c,mycompare);
  int sum=0,posk,posc,best=0,bestposk=0,bestposc=0;
  if(V/2>c) posc=c;
  else posc=V/2;
  if(V-2*posc>k) posk=k;
  else posk=V-2*posc;
  FOR(i,posk) sum+=kayak[i].capacity;
  FOR(i,posc) sum+=catamaran[i].capacity;
  best=sum;
  bestposk=posk;
  bestposc=posc;
  while(posc>0){
    posc--;
    sum-=catamaran[posc].capacity;
    if(posk<k){ sum+=kayak[posk].capacity; posk++; }
    if(posk<k){ sum+=kayak[posk].capacity; posk++; }
    if(sum>best){
      best=sum;
      bestposk=posk;
      bestposc=posc; 
    }
  }
  int pos=0;
  printf("%d\n", best);
  FOR(i,bestposk){ res[pos]=kayak[i].id; pos++; }
  FOR(i,bestposc){ res[pos]=catamaran[i].id; pos++; }
  sort(res,res+pos);
  FOR(i,pos) printf("%d ",res[i]);
  printf("\n");
  return 0;
}