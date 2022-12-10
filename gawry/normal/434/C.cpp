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
int m;
vi read(){
  int len;
  scanf("%d",&len);
  vi t(len);
  FOR(i,len)scanf("%d",&t[i]);
  return t;
}
vi increase(vi t){
  int cnt=0;
  while(!t.empty()&&t.back()==m-1){
    ++cnt;
    t.pop_back();
  }
  if(t.empty()){
    t.push_back(1);
  }else{
    ++t.back();
  }
  FOR(i,cnt)t.push_back(0);
  return t;
}
const int MOD=1000000000+7;
int n,k,v[200];
vector<int> s[200];
vector<vi> q;
int value[201];
map<vi,int> name;
int transition[201][20];
int mem[201][501][201][2];
int f(vi t){
  //FOR(i,t.size())cout<<t[i]<<" ";cout<<endl;
  memset(mem,0,sizeof(mem));
  mem[0][0][0][0]=1;
  FOR(i,t.size())FOR(j,k+1)FOR(z,q.size())FOR(v,2)if(mem[i][j][z][v])FOR(next,m)if(next||i){
    if(next>t[i]&&!v)continue;
    //cout<<i<<" "<<j<<" "<<z<<" "<<v<<" "<<next<<":"<<mem[i][j][z][v]<<endl;
    int z2=transition[z][next];
    int j2=j+value[z2];
    //cout<<z2<<" "<<j2<<endl;
    if(j2>k)continue;
    int v2=v||next<t[i];
    mem[i+1][j2][z2][v2]+=mem[i][j][z][v];
    if(mem[i+1][j2][z2][v2]>=MOD)mem[i+1][j2][z2][v2]-=MOD;
  }
  int ans=0;
  FOR(j,k+1)FOR(z,q.size()){
    ans+=mem[t.size()][j][z][1];
    if(ans>=MOD)ans-=MOD;
  }
  memset(mem,0,sizeof(mem));
  mem[0][0][0][0]=1;
  FOR(i,t.size()-1)FOR(j,k+1)FOR(z,q.size())FOR(v,2)if(mem[i][j][z][v])FOR(next,m)if(next||i){
    //cout<<i<<" "<<j<<" "<<z<<" "<<v<<" "<<next<<":"<<mem[i][j][z][v]<<endl;
    int z2=transition[z][next];
    int j2=j+value[z2];
    //cout<<z2<<" "<<j2<<endl;
    if(j2>k)continue;
    int v2=v||next<t[i];
    mem[i+1][j2][z2][v2]+=mem[i][j][z][v];
    if(mem[i+1][j2][z2][v2]>=MOD)mem[i+1][j2][z2][v2]-=MOD;
  }
  FOR(i,t.size())FOR(j,k+1)FOR(z,q.size()){
    ans+=mem[i][j][z][0];
    if(ans>=MOD)ans-=MOD;
    ans+=mem[i][j][z][1];
    if(ans>=MOD)ans-=MOD;
  }
  //cout<<ans<<endl;
  return ans;
}
int main(){
  scanf("%d %d %d",&n,&m,&k);
  vector<int> from,to;
  from=read();
  to=read();
  FOR(i,n){
    s[i]=read();
    scanf("%d",&v[i]);
  }
  FOR(i,n)FOR(j,s[i].size()+1){
    vi tmp;
    FOR(k,j)tmp.push_back(s[i][k]);
    q.push_back(tmp);
  }
  q.push_back(vi());
  sort(q.begin(),q.end());
  q.erase(unique(q.begin(),q.end()),q.end());
  FOR(i,q.size())name[q[i]]=i;
/*FOR(i,q.size()){
  FOR(j,q[i].size())cout<<q[i][j]<<" ";
  cout<<endl;
}*/
  map<vi,int> add;
  FOR(i,n)add[s[i]]+=v[i];
  FOR(i,q.size())FOR(j,q[i].size()){
    vi tmp;
    FOR(k,q[i].size()-j)tmp.push_back(q[i][j+k]);
    map<vi,int>::iterator it=add.find(tmp);
    if(it!=add.end())value[i]+=it->second;
  }
  FOR(i,q.size())FOR(j,m){
    vi tmp=q[i];
    tmp.push_back(j);
    while(name.find(tmp)==name.end())tmp.erase(tmp.begin());
    transition[i][j]=name[tmp];
   // cout<<i<<" "<<j<<" "<<name[tmp]<<endl;
  }
  printf("%d\n",(f(increase(to))+MOD-f(from))%MOD);
  return 0;
}