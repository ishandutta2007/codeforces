#include<cstdio>
#include<cassert>
#include<vector>
using namespace std;
const int MAX=2*100000+1;
int n,m,a[MAX],b[MAX],c[MAX],r[MAX],needs[MAX];
vector<int> s[MAX];
void process(int x){
  assert(!needs[x]);
  for(int i=0;i<s[x].size();i++)if(!r[s[x][i]]){
    int y=a[s[x][i]]^b[s[x][i]]^x;
    needs[y]-=c[s[x][i]];
    r[s[x][i]]=y==a[s[x][i]]?1:-1;
    if(!needs[y])process(y);
  }
}
main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<m;i++){
    scanf("%d %d %d",&a[i],&b[i],&c[i]);
    needs[a[i]]+=c[i];
    needs[b[i]]+=c[i];
    s[a[i]].push_back(i);
    s[b[i]].push_back(i);
  }
  for(int i=1;i<n;i++)needs[i]/=2;
  needs[1]=0;
  process(1);
  for(int i=0;i<m;i++)printf("%d\n",r[i]==1?1:0);
}