#include<cstdio>
#include<set>
#include<map>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int n,t[15],best[1<<15][15*14/2+1],prev[500000][15];
int calc(vector<int> &s){
//  for(int i=0;i<s.size();i++)cout<<s[i]<<" ";cout<<endl;
  
  int b=n*(n-1)/2+1;
  for(int i=0;i<=b;i++)best[0][i]=s.size();
  for(int i=0;i<s.size();i++){
    for(int j=0;j<n;j++)prev[i][j]=i?prev[i-1][j]:-1000000;
    prev[i][s[i]]=i;
  }
  for(int left=1;left<(1<<n);left++){
    for(int i=0;i<=b;i++)best[left][i]=-1000000;
    int add=0;
    for(int i=0;i<n;i++)if(left&1<<i){
      for(int j=0;j<=b;j++)if(best[left-(1<<i)][j]>=0){
        int pos=best[left-(1<<i)][j]-1;
        if(pos>=0&&prev[pos][i]>=0){
          pos=prev[pos][i];
          best[left][j+add]=max(best[left][j+add],pos);
        }
      }
      ++add;
    }
//cout<<"left="<<left<<endl;
//for(int j=0;j<=b;j++)cout<<best[left][j]<<",";cout<<endl;
  }
  int ans=0;
  while(ans<=b&&best[(1<<n)-1][ans]<0)++ans;
  //cout<<ans<<" "<<best[(1<<n)-1][ans]<<endl;
  return ans<=b?ans:1000;
}
map<string,int> nr;
char buf[100];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%s",buf);
    if(nr.find(buf)==nr.end())nr[buf]=i;
    t[i]=nr[buf];
  }
//  for(int i=0;i<n;i++)cout<<t[i]<<",";cout<<endl;
  int m;
  scanf("%d",&m);
  int where=0,best=1000;
  for(int z=1;z<=m;z++){
    int k;
    scanf("%d",&k);
    vector<int> s;
    while(k--){
      scanf("%s",buf);
      map<string,int>::iterator it=nr.find(buf);
      if(it!=nr.end())s.push_back(it->second);
    }
    int cur=calc(s);
    if(cur<best){
      best=cur;
      where=z;
    }
  }
  if(!where){
    puts("Brand new problem!");
  }else{
    printf("%d\n",where);
    printf("[:");
    for(int i=0;i<n*(n-1)/2-best+1;i++)printf("|");
    printf(":]\n");
  }
}