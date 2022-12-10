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
#include<queue>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

#define MAX 1100000
#define POWER (1<<17)
int n,t[MAX],nr[MAX],cnt[2*POWER];
int64 sum[2*POWER][5];
void repair(int x){
  while(x){
    cnt[x]=cnt[2*x]+cnt[2*x+1];
    FOR(k,5)sum[x][k]=0;
    FOR(i,5)FOR(j,5){
      int k;
      if(cnt[2*x]-1-i>=0){
        int last=(cnt[2*x]-1-i)/5*5+i;
        if(cnt[2*x]-last-1+j!=4)continue;
        sum[x][i]+=sum[2*x][i]+sum[2*x+1][j];
      }else if(i==cnt[2*x]){
        k=cnt[2*x]+j;
        if(k>4)continue;
        sum[x][k]+=sum[2*x+1][j];
      }
    }
    x/=2; 
  } 
}
vector<int> s;
main() {
  scanf("%d",&n);
  FOR(i,n){
    char buf[10];
    scanf(" %s",buf); 
    if(buf[0]=='s')t[i]=2;
    else{
      int x;
      scanf("%d",&x);
      nr[i]=x;
      s.push_back(x);
      t[i]=buf[0]=='a'?0:1;
    }
  }
  sort(s.begin(),s.end());
  s.erase(unique(s.begin(),s.end()),s.end());
  FOR(i,n){
    if(t[i]==2){printf("%I64d\n",sum[1][2]);continue;}
    if(t[i]==0){
      int pos=lower_bound(s.begin(),s.end(),nr[i])-s.begin();
      cnt[POWER+pos]=1;
      sum[POWER+pos][0]=s[pos];
      repair((POWER+pos)/2);
    }else{
      int pos=lower_bound(s.begin(),s.end(),nr[i])-s.begin();
      cnt[POWER+pos]=0;
      sum[POWER+pos][0]=0;
      repair((POWER+pos)/2);
    }    
  }
}