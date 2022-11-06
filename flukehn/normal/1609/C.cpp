#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
int np[N],p[N],tot;
const int M=2e5+11;
int n,e;
int a[M];
long long cal(vector<int> b){
//  for(int i:b)cerr<<i<<" ";cerr<<endl;
  int m=b.size();
  long long ret=0;
  for(int i=0,j;i<m;++i){
    int p=i;
    for(j=i;j<m&&!b[j];++j);
    i=j;
    if(j>=m||b[j]==-1){
      continue;
    }
    for(++j;j<m&&!b[j];++j);
    ret+=1ll*(i-p+1)*(j-i);
  } 
  return ret;
}
long long work(){
  cin>>n>>e;
  for(int i=1;i<=n;++i)cin>>a[i];
  long long ans=0;
  for(int i=1;i<=e;++i){
    vector<int> b;
    for(int j=i;j<=n;j+=e){
      int w=a[j]==1?0:(np[a[j]]?-1:1);
      b.push_back(w);
    }
    ans+=cal(b);
  }
  for(int i=1;i<=n;++i)
    if(!np[a[i]])--ans;
  return ans;
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  np[1]=1;
  for(int i=2;i<N;++i){
    if(!np[i]){
      p[tot++]=i;
    }
    for(int j=0,k;j<tot&&(k=i*p[j])<N;++j){
      np[k]=1;
      if(i%p[j]==0){
        break;
      }
    }
  }
  int t;
  cin>>t;
  while(t--)
    cout<<work()<<"\n";
}