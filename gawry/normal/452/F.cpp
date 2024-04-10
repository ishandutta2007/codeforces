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
const int MAX=310000;
int n,where[MAX];
bool ok=true;
vector<int> t;
void check(int i,int j){
  if(i<0||i>=n||j<0||j>=n||i==j)return;
  if(i>j)swap(i,j);
  int middle=(t[i]+t[j]);
  if(middle%2)return;
  middle/=2;
  if(middle<1||middle>n)return;
  if(where[middle]>i&&where[middle]<j)ok=false;
}
void go(vector<int> _t){
  if(!ok)return;
  t=_t;
  for(int i=0;i<t.size();i++)where[t[i]]=i;
  n=t.size();
  if(n<20){
    for(int i=0;i<n;i++)for(int j=0;j<i;j++)check(i,j);
    return;
  }
  int half=n/2-6;
  for(int i=0;i<half;i++)ok&=t[i]%2==t[1]%2;
  for(int i=0;i<half;i++)ok&=t[n-1]%2==t[n-1-i]%2;
  for(int i=half;i<=n-half;i++)for(int j=0;j<n;j++)check(i,j);
  vector<int> left,right;
  for(int i=0;i<t.size();i++)if(t[i]%2)right.push_back((t[i]+1)/2);else left.push_back(t[i]/2);
  go(left);
  go(right);
}
int main(){
  scanf("%d",&n);
  t=vi(n);
  for(int i=0;i<n;i++){
    scanf("%d",&t[i]);
    //t[i]=i;
    where[t[i]]=i;
  }
  for(int i=0;i<100000;i++){
    int x=rand()%n;
    int y=rand()%n;
    check(x,y);
  }
  go(t);
  printf(ok?"NO\n":"YES\n");
  return 0;
}