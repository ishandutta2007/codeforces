#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
int arr[1000005];
long long val[1000005];
long long total;
vector<ii> v;
int front_f[1000005],back_f[1000005];
void front_inc(int i){
  while (i!=0){
    front_f[i]++;
    i-=(i&(-i));
  }
}
int front_query(int i){
  int x=0;
  while (i<=n){
    x+=front_f[i];
    i+=(i&(-i));
  }
  return x;
}
void back_inc(int i){
  while (i<=n){
    back_f[i]++;
    i+=(i&(-i));
  }
}
int back_query(int i){
  int x=0;
  while (i!=0){
    x+=back_f[i];
    i-=(i&(-i));
  }
  return x;
}
int main(){
  //freopen("input.txt","r",stdin);
  scanf("%d",&n);
  for (int x=0;x<n;x++){
    scanf("%d",&arr[x]);
    v.push_back(ii(arr[x],x));
  }
  sort(v.begin(),v.end());
  for (int x=0;x<n;x++){
    val[x]=front_query(v[x].second+1);
    front_inc(v[x].second+1);
  }
  for (int x=n-1;x>=0;x--){
    //printf("%d %d\n",val[x],back_query(v[x].second+1));
    total+=val[x]*back_query(v[x].second+1);
    back_inc(v[x].second+1);
  }
  printf("%lld\n",total);
}