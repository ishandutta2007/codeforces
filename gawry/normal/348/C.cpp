#include<cstdio>
#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
const int MAX=100000+12345;
const int BOUND=1500;
int n,m,q,cnt,tmp,a[MAX];
vector<int> s[MAX],big,where[MAX];
int t[MAX/BOUND][MAX],nr[MAX];
long long sum_a[MAX],change[MAX],acc[MAX],delayed[MAX];
main(){
  scanf("%d %d %d",&n,&m,&q);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){
    scanf("%d",&cnt);
    while(cnt--){
      scanf("%d",&tmp);
      s[i].push_back(tmp);
      where[tmp].push_back(i);
      sum_a[i]+=a[tmp];
    }
    if(s[i].size()>BOUND){
      nr[i]=big.size();
      big.push_back(i);
    }else nr[i]=-1;
  }
  for(int i=0;i<big.size();i++){
    int x=big[i];
    for(int j=0;j<s[x].size();j++){
      int y=s[x][j];
      for(int k=0;k<where[y].size();k++)++t[i][where[y][k]];
    }
  }
  while(q--){
    char c;
    int x,y;
    scanf(" %c %d",&c,&x);
    if(c=='?'){
      long long ans=sum_a[x];
      for(int i=0;i<big.size();i++)ans+=change[i]*t[i][x];
      if(nr[x]>-1){
        ans+=delayed[nr[x]];
      }else{
        for(int i=0;i<s[x].size();i++)ans+=acc[s[x][i]];
      }
      cout<<ans<<endl;
    }else{
      scanf("%d",&y);
      if(nr[x]==-1){
        for(int i=0;i<s[x].size();i++)acc[s[x][i]]+=y;
        for(int i=0;i<big.size();i++)delayed[i]+=(long long)y*t[i][x];
      }else{
        change[nr[x]]+=y;
      }
    }
  }
}