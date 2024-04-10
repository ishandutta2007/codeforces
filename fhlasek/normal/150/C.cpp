/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int N,M,C;
#define MAXN 555555
#define MAX 262144


double e[MAXN];
double p[MAXN];
int X[MAXN];
int left[2*MAX+1],right[2*MAX+1];
double pref[2*MAXN+1],suff[2*MAXN+1],mid[2*MAXN+1];

double get_sum(int x){
  int a = left[x];
  int b = right[x];
  if(a > N) a = N;
  if(b > N) b = N;
  return p[b] - p[a];
}

double get_pref(int v,int l,int r){
  if(l == left[v] && r == right[v]) return pref[v];
  int middle = (left[v] + right[v]) / 2;
  if(middle >= r) return get_pref(2*v,l,r);
  if(middle <= l) return get_pref(2*v+1,l,r);
  double res = 0;
  res = max(res,get_pref(2*v,l,middle));
  res = max(res,get_sum(2*v) + get_pref(2*v+1,middle,r));
  return res;
}

double get_suff(int v,int l,int r){
  if(l == left[v] && r == right[v]) return suff[v];
  int middle = (left[v] + right[v]) / 2;
  if(middle >= r) return get_suff(2*v,l,r);
  if(middle <= l) return get_suff(2*v+1,l,r);
  double res = 0;
  res = max(res,get_suff(2*v+1,middle,r));
  res = max(res,get_sum(2*v+1) + get_suff(2*v,l,middle));
  return res;
}

double get_mid(int v,int l,int r){
//  printf("get_mid: v:%d(left:%d right:%d) l:%d r:%d mid:%lf pref:%lf suff:%lf\n",v,left[v],right[v],l,r,mid[v],pref[v],suff[v]);
  if(l == left[v] && r == right[v]) return mid[v];
  int middle = (left[v] + right[v]) / 2;
  if(middle >= r) return get_mid(2*v,l,r);
  if(middle <= l) return get_mid(2*v+1,l,r);
  double res = 0;
  res = max(res,get_mid(2*v,l,middle));
  res = max(res,get_mid(2*v+1,middle,r));
  res = max(res,get_suff(2*v,l,middle) + get_pref(2*v+1,middle,r));
  return res;
}

int main(int argc, char *argv[]){
  left[1] = 0;
  right[1] = MAX;
  FOR(i,1,MAX){
    left[2*i] = left[i];
    right[2*i] = (left[i]+right[i])/2;
    left[2*i+1] = (left[i]+right[i])/2;
    right[2*i+1] = right[i];
  }
  scanf("%d%d%d",&N,&M,&C);   
  REP(i,N) scanf("%d",X+i);
  int P;
  REP(i,N-1){
    scanf("%d",&P);
    e[i] = (double)(X[i+1] - X[i])/2 - (double)P/100*C;
  }
  N--;
  REP(i,N) p[i+1] = p[i] + e[i];

  FORD(i,2*MAX+1,1){
    if(left[i] + 1 == right[i]){
      if(left[i] < N){
        pref[i] = max(pref[i],e[left[i]]);
        suff[i] = max(suff[i],e[left[i]]);
        mid[i] =  max(mid[i] ,e[left[i]]);
      }
    }
    else{
      pref[i] = max(pref[i], max(pref[2*i], get_sum(2*i) + pref[2*i+1]));
      suff[i] = max(suff[i], max(suff[2*i+1], get_sum(2*i+1) + suff[2*i]));
      mid [i] = max(mid[i] , max( max(mid[2*i], mid[2*i+1]), suff[2*i] + pref[2*i+1]));
    }
  }
  double sum = 0;
  while(M--){
    int a,b;
    scanf("%d%d",&a,&b);
    sum += get_mid(1,a-1,b-1);
  }
  printf("%.9lf\n",sum);
  return 0;
}