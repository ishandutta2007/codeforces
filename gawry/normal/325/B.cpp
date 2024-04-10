#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
main(){
  int64 n;
  cin>>n;
  vector<int64> ans;
  int64 pow=1;
  while(pow-1<=n){
    int64 z=pow-1,from=0,to=1;
    while((2*to+1)*(z+to)<=n)to*=2;
    while(from+1<to){
      int64 middle=(from+to)/2;
      if((2*middle+1)*(z+middle)<=n)from=middle;else to=middle;
    }
    if((2*from+1)*(z+from)==n)ans.push_back((2*from+1)*pow);
    pow*=2;
  }
  sort(ans.begin(),ans.end());
  if(ans.empty())puts("-1");
  for(int i=0;i<ans.size();i++)printf("%I64d\n",ans[i]);
}