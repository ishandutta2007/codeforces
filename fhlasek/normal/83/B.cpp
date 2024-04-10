#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)
#define MAXN 111111

using namespace std;

int N,out,red;
long long K,d;
pair< int,int > a[MAXN];
vector<int> res;

bool mycompare(pair<int, int> x,pair<int,int> y){ return x.second<y.second; }

void print(){
  if(N==0){ printf("\n"); return; }
  sort(a+out,a+out+N,mycompare);
  int i,R;
  long long k=K%N;
  FOR(i,N) if(i+k<N||a[(i+k)%N+out].first-red-K/N-1) res.push_back(a[(i+k)%N+out].second);
  R=res.size();
  FOR(i,R){
    if(i) printf(" ");
    printf("%d",res[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]){
  int i;
  out=0;
  red=0;
  cin >> N >> K;
  FOR(i,N){ scanf("%d",&(a[i].first)); a[i].second=i+1; }
  sort(a,a+N);
  while(N){
    d=(long long)(a[out].first-red)*N;
    if(d>K){ print(); return 0; }
    K-=d;
    red=a[out].first;
    N--;
    out++;
  }
  if(K==0){ print(); return 0; }
  else printf("-1\n");
  return 0;
}