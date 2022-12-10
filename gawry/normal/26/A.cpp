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

int n,d[3010],r;
main() {
  for(int i=2;i<3010;i++)d[i]=i;
  for(int i=2;i<3010;i++)if(d[i]==i)for(int j=i;j<3010;j+=i)d[j]=i;
  scanf("%d",&n);  
  for(int i=2;i<=n;i++){
    int j=i,cnt=0;
    while(j>1){
      cnt++;
      int div=d[j];
      while(j%div==0)j/=div; 
    }
    r+=cnt==2;
  }
  printf("%d\n",r);
}