#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,a[1000000],b[1000000];
vector<int> t[41];
main(){
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  for(int i=0;i<m;i++){
    scanf("%d",&b[i]);
    t[b[i]].push_back(1);
  }
  int ans=0;
  for(int i=0;i<40;i++){
    int odd=0;
    for(int j=0;j<n;j++)odd+=a[j]%2;
    int take=min(odd,(int)t[i].size());
    sort(t[i].begin(),t[i].end());
    for(int j=0;j<take;j++){
      ans+=t[i].back();
      t[i].pop_back();
    }
    while(t[i].size()>=2){
      int tmp=t[i].back();
      t[i].pop_back();
      tmp+=t[i].back();
      t[i].pop_back();
      t[i+1].push_back(tmp);
    }
    if(t[i].size())t[i+1].push_back(t[i].back());
    for(int j=0;j<n;j++)a[j]/=2;
  }
  printf("%d\n",ans);
}