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
int n,t[300];
main(){
  scanf("%d",&n);
  FOR(i,2*n-1)scanf("%d",&t[i]);
  vi pos,neg;
  FOR(i,2*n-1)if(t[i]<0)neg.push_back(t[i]);else pos.push_back(t[i]);
  int ans=0;
  if(neg.size()%2&&n%2==0){
    FOR(i,neg.size())pos.push_back(-neg[i]);
    sort(pos.begin(),pos.end());
    FOR(i,pos.size())ans+=i?pos[i]:-pos[i];
  }else{
    FOR(i,neg.size())neg[i]*=-1;
    FOR(i,pos.size())ans+=pos[i];
    FOR(i,neg.size())ans+=neg[i];
  }
  printf("%d\n",ans);
}