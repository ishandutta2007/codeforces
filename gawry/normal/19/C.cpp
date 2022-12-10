#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAX 101000
int t[MAX],n,h[MAX],p[MAX];
typedef pair<int,int> p2;
p2 w[MAX];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&t[i]);
    w[i].first=t[i];
    w[i].second=i;
  }
  sort(w,w+n);
  for(int i=n-1;i>=0;i--){
#define MOD 1000000009    
#define PRIME 1337
    h[i]=((long long)h[i+1]*PRIME+t[i])%MOD;    
  }
  p[0]=1;
  for(int i=1;i<=n;i++)p[i]=(long long)p[i-1]*PRIME%MOD;
  vector<p2> s;
  for(int i=0;i<n;i++){
    int j=i+1;
    while(j<n&&w[j].first==w[i].first){
      int len=w[j].second-w[i].second,start=w[i].second;
      long long tmp=h[start]-(long long)h[start+len]*p[len];
      tmp-=h[start+len]-(long long)h[start+2*len]*p[len];
      if(tmp%MOD==0)s.push_back(p2(len,start));
      j++; 
    } 
  }
  sort(s.begin(),s.end());
  int first=0;
  for(int i=0;i<s.size();i++)if(s[i].second>=first){
//    cout<<s[i].first<<" "<<s[i].second<<endl; 
    first=s[i].second+s[i].first;
  }
  printf("%d\n",n-first);
  for(int i=first;i<n;i++)printf("%d%c",t[i],i+1<n?' ':'\n');
}