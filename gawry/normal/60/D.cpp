#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

typedef long long int64;
typedef pair<int,int> p2;
typedef vector<int> vi;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

int gcd(int x,int y){return y?gcd(y,x%y):x;}
#define MAX 10001000
int d[MAX],n,a[1000000],p[1000000],r;
int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
void join(int x,int y){x=find(x);y=find(y);p[x]=y;}
void check(int nr,int64 x){
  if(x<a[0]||a[n-1]<x)return;
  int pos=lower_bound(a,a+n,x)-a;
  if(a[pos]!=x)return;
  join(nr,pos);
}
int main() {
  for(int i=2;i<MAX;i++)d[i]=i;
  for(int i=2;i<MAX;i+=2)d[i]=2;
  for(int i=3;i*i<MAX;i++)if(d[i]==i)for(int j=i*i;j<MAX;j+=2*i)d[j]=i;
  scanf("%d",&n);
  FOR(i,n)scanf("%d",&a[i]);
  sort(a,a+n);
  FOR(i,n)p[i]=i;
  FOR(i,n)if(a[i]%4==0){
    int t[10],s=0,left=a[i]/2;
    while(left>1){
      int div=d[left];
      t[s]=1;
      while(left%div==0){
        t[s]*=div;
        left/=div;
      }
      s++;
    }
    
//    FOR(j,s)cout<<t[j]<<",";cout<<endl;
    FOR(take,1<<s){
      int n=1,m=1;
      FOR(j,s)if(take&1<<j)n*=t[j];else m*=t[j];
      if(n>=m)continue;
      // n<=m
      // n^2+m^2 oraz (m-n)(m+n)
      check(i,(int64)n*n+(int64)m*m);
      check(i,(int64)(m-n)*(m+n));
    }
  }
  for(int x=1;x*x<MAX;x++)for(int y=1+x%2;y<x;y+=2)if(gcd(x,y)==1){
    int p=x*x+y*y,q=(x-y)*(x+y);
    int pos=lower_bound(a,a+n,p)-a,pos2=lower_bound(a,a+n,q)-a;
    if(pos<n&&a[pos]==p&&pos2<n&&a[pos2]==q)join(pos,pos2);
  }
  FOR(i,n)r+=p[i]==i;
  printf("%d\n",r);
  return 0;
}