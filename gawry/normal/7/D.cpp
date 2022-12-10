#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;
typedef long long int64;

#define MAX (6*1000000)
char tab[2*MAX];
int r[MAX],pref[2*MAX],n;
int f(int j,int k){
  k=max(k,j);
  int i=k-j;
  while (k<=n&&tab[i]==tab[k-1]) { i++;  k++; }
  return k-j;
}
int main() {
  scanf(" %s",tab);
  n=strlen(tab);
  FOR(i,n)tab[n+i]=tab[n-1-i];
  int i=1;
  pref[1]=-1; 
  n*=2;
  for (int j=2; j<=n; ++j){
    int l=j-i+1;
    if (l<=pref[i] && j+pref[l]<i+pref[i])
      pref[j]=pref[l];
    else{
      pref[j]=f(j,i+pref[i]);
      i=j;
    }
  }
  n/=2;
//  puts(tab);
  FOR(i,n)if(pref[2*n-i]>=(i+1)/2){
//     printf("%d %d:%d\n",i,2*n-i,pref[2*n-1]);
     r[i]=1+(i?r[(i-1)/2]:0);
  }
  printf("%d\n",accumulate(r,r+n,0));
  return 0;
}