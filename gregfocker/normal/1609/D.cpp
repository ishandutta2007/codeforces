#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e3+7;
int n,q,t[N],sz[N],useless;

int root(int a){
  if (t[a]==a)return a;
  return t[a]=root(t[a]);
}

void unite(int a,int b){
  a=root(a);
  b=root(b);
  if(a==b){
    useless++;
    return;
  }
  t[a]=b;
  sz[b]+=sz[a];
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n>>q;
  for (int i=1;i<=n;i++){
    t[i]=i;
    sz[i]=1;
  }
  while (q--){
    int a,b;
    cin>>a>>b;
    unite(a,b);
    vector<int>sol;
    for (int i=1;i<=n;i++)if (t[i]==i)sol.push_back(sz[i]);
    sort(sol.rbegin(),sol.rend());
    int cnt=min(useless+1,(int)sol.size());
    int kek=0;
    for (int i=0;i<cnt;i++){
      kek+=sol[i];
    }
    cout<<kek-1<<"\n";
  }
  return 0;
}