#include<cstdio>
#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
#define MAX 500000
int n,m,w[MAX],c[MAX],a[MAX],W,s[MAX];
double t[MAX];
double r_fraction;
long long r_integer;
void take(int nr,int amount){
  if(!amount)return;
  r_integer+=(long long)amount*c[nr]/w[nr];
  int p=(long long)amount*c[nr]%w[nr],q=w[nr];
  r_fraction+=(double)p/q;
  while(r_fraction>=1){
    r_fraction--;
    r_integer++;
  }
}
void select(int from,int to,int left){
  if(from==to)return;
  if(from+1==to){
    take(s[from],left);
    return;
  }
  long double middle_t=t[s[(from+to)/2]];
  int middle=from;
  for(int i=from;i<to;i++)if(t[s[i]]<middle_t)swap(s[i],s[middle++]);
  long long less_sum=0,eq_sum=0;
  for(int i=from;i<middle;i++)less_sum+=w[s[i]];
  if(less_sum>=left){
    select(from,middle,left);
    return;
  }
  for(int i=from;i<middle;i++){
    take(s[i],w[s[i]]);
    left-=w[s[i]];
  }
  int middle2=middle;
  for(int i=middle;i<to;i++)if(t[s[i]]==middle_t)swap(s[i],s[middle2++]);
  for(int i=middle;i<middle2;i++)eq_sum+=w[s[i]];
  if(eq_sum>=left){
    take(s[middle],left);
    return;
  }
  take(s[middle],eq_sum);
  left-=eq_sum;
  select(middle2,to,left);
}
main(){
  scanf("%d %d %d",&n,&m,&W);
  for(int i=0;i<m;i++)scanf("%d",&w[i]);
  for(int i=0;i<m;i++)scanf("%d",&c[i]);
  for(int i=0;i<m;i++)scanf("%d",&a[i]);
  for(int i=0;i<m;i++){
    t[i]=(long double)c[i]/w[i];
    s[i]=i;
  }
  random_shuffle(s,s+m);
  for(int z=0;z<n;z++){
    select(0,m,W);
    for(int i=0;i<m;i++){
      t[i]-=(long double)a[i]/w[i];
      c[i]-=a[i];
    }
  }
  char buf[20];
  sprintf(buf,"%.12lf",r_fraction);
  if(buf[0]=='1')r_integer++;
  cout<<r_integer<<buf+1<<endl;
}