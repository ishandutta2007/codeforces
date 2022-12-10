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
#include<queue>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
vector<long long> calc(vector<int> t,int penalty,int k){
  vector<long long> ans;
  priority_queue<int> q;
  for(int i=0;i<t.size();i++)q.push(t[i]);
  long long cur=0;
  ans.push_back(cur);
  for(int i=1;i<=k;i++){
    int best=q.top();
    q.pop();
    cur+=best;
    ans.push_back(cur);
    q.push(best+penalty);
  }
  return ans;
}
int n,m,k,p,a[1010][1010];
int main(){
  scanf("%d %d %d %d",&n,&m,&k,&p);
  for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
  int max_column=0,max_row=0;
  vector<int> rows,cols;
  for(int i=1;i<=n;i++){
    int cur=0;
    for(int j=1;j<=m;j++)cur+=a[i][j];
    rows.push_back(cur);
  }
  for(int j=1;j<=m;j++){
    int cur=0;
    for(int i=1;i<=n;i++)cur+=a[i][j];
    cols.push_back(cur);
  }
  vector<long long> x=calc(rows,-p*m,k),y=calc(cols,-p*n,k);

//for(int i=0;i<=k;i++)cout<<x[i]<<" ";cout<<endl;
//for(int i=0;i<=k;i++)cout<<y[i]<<" ";cout<<endl;

  long long ans=-1LL<<60;
  for(int i=0;i<=k;i++){
    ans=max(ans,-1LL*p*i*(k-i)+x[i]+y[k-i]);
  }
  cout<<ans<<endl;
  return 0;
}