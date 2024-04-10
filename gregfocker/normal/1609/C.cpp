#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll


const int N=(int)1e6+7;
bool is[N];

int lol(vector<int>v){
  int sol=0,n=(int)v.size();
  for (auto &x:v){
    assert(x==1||is[x]);
  }
  vector<int>pz;
  for (int i=0;i<n;i++){
    if (is[v[i]])pz.push_back(i);
  }
  for (int i=0;i<(int)pz.size();i++){
    int l;
    if (i==0)l=0;
    else l=pz[i-1]+1;
    int r;
    if (i==(int)pz.size()-1)r=n-1;
    else r=pz[i+1]-1;
    sol+=(pz[i]-l+1)*(r-pz[i]+1)-1;
  }
  return sol;
}

int solve(vector<int> v){
  int sol=0;
  int n=(int)v.size();
  int l=0;
  while (l<n){
    if (v[l]>1&&!is[v[l]]){l++;continue;}
    int r=l;
    while (r+1<n&&(v[r+1]==1||is[v[r+1]]))r++;

    vector<int>kek;
    for (int i=l;i<=r;i++)kek.push_back(v[i]);
    sol+=lol(kek);

    l=r+1;
  }
  return sol;
}

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

//  freopen ("input","r",stdin);
//
  is[2]=1;
  for (int i=3;i<N;i+=2)is[i]=1;
  for (int i=3;i*i<N;i+=2){
    if (is[i]){
      for (int j=i*i;j<N;j+=2*i)is[j]=0;
    }
  }
  {
    int cnt=0;
    for (int i=1;i<=100;i++)cnt+=is[i];
    assert(cnt==25);
  }

  int t;
  cin>>t;

  while (t--){
    int n,e;
    cin>>n>>e;
    vector<vector<int>>inds(e);
    vector<int>a(n);
    for (int i=0;i<n;i++){
      cin>>a[i];
      inds[i%e].push_back(i);
    }
    int sol=0;
    for (int r=0;r<e;r++){
      vector<int>v;
      for (auto &i:inds[r])v.push_back(a[i]);
      sol+=solve(v);
    }
    cout<<sol<<"\n";
  }


  return 0;
}