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
const int MAX=210000;
int n,q,a[MAX];
const int POWER=1<<18;
struct tab {
  int len,t[31],add;
} s[2*POWER];
int len,t[64];
void gauss(const tab &a,const tab &b,tab &c){
  len=0;
  for(int i=0;i<a.len;i++){
    t[len++]=a.t[i]; 
  }
  for(int i=0;i<b.len;i++){
    t[len++]=b.t[i]; 
  }
  int next=0;
  for(int i=0;i<=30;i++){
    int j=next;
    while(j<len&&!(t[j]&1<<i)){
      ++j;
    }
    if(j==len)continue;
    swap(t[next],t[j]);
    for(j=0;j<len;j++)if(j!=next&&(t[j]&1<<i)){
      t[j]^=t[next];
    }
    ++next;
  }
  c.len=next;
  for(int i=0;i<next;i++){
    c.t[i]=t[i];
  }
}
void fix(tab &a,int add){
  for(int i=0;i<a.len;i++)if(a.t[i]>>30){
    a.t[i]^=add;
  }
}
void recalc(int pos){
  if(pos>=POWER){
    return;
  }
  gauss(s[2*pos],s[2*pos+1],s[pos]);
  fix(s[pos],s[pos].add);
}
int main(){
  scanf("%d %d",&n,&q);
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    s[POWER+i].len=1;
    s[POWER+i].t[0]=a[i]|1<<30;
  }
  for(int i=POWER-1;i;i--){
    gauss(s[2*i],s[2*i+1],s[i]);
  }
  while(q--){
    int type,from,to,k;
    scanf("%d %d %d",&type,&from,&to);
    --from;--to;
    if(type==1){
      scanf("%d",&k);
      from+=POWER;
      s[from].t[0]^=k;
      to+=POWER;
      if(from<to){
        s[to].t[0]^=k;
      }
      while(from+1<to){
        recalc(from);
        recalc(to);
        if(from%2==0){
          s[from+1].add^=k;
          fix(s[from+1],k);
        }
        if(to%2){
          s[to-1].add^=k;
          fix(s[to-1],k);
        }
        from/=2;
        to/=2;
      }
      while(from){
        recalc(from);
        from/=2;
      }
      while(to){
        recalc(to);
        to/=2;
      }
    }else if(type==2){
      from+=POWER;
      tab left=s[from];
      to+=POWER;
      tab right=s[to];
      while(from+1<to){
        if(from%2==0){
          gauss(left,s[from+1],left);
        }
        if(to%2){
          gauss(right,s[to-1],right);
        }
        from/=2;
        to/=2;
        fix(left,s[from].add);
        fix(right,s[to].add);
      }
      while(from/=2){
        fix(left,s[from].add);
      }
      while(to/=2){
        fix(right,s[to].add);
      }
      tab result;
      for(int i=0;i<left.len;i++){
        left.t[i]&=~(1<<30);
      }
      for(int i=0;i<right.len;i++){
        right.t[i]&=~(1<<30);
      }
      gauss(left,right,result);
      printf("%d\n",1<<result.len);
    }
  }
  return 0;
}