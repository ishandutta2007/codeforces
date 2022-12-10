#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int64 r,p[20]={1};
void check(int len,int64 from,int64 to){
//  cout<<len<<" "<<from<<" "<<to<<endl;
  int64 t=p[len]-1;
  r=max(r,from*(t-from));
  r=max(r,to*(t-to));
  for(int64 x=t/2-1000;x<=t/2+1000;x++)if(from<=x&&x<=to)r=max(r,x*(t-x));
}
main(){
  int64 from,to;
  FOR(i,19)p[i+1]=p[i]*10;
  cin>>from>>to;
  int from_len=1,to_len=1;
  while(p[from_len]<=from)++from_len;
  while(p[to_len]<=to)++to_len;
  if(from_len==to_len){
    check(from_len,from,to);
  }else{
    check(from_len,from,p[from_len]-1);
    for(int i=from_len+1;i<to_len;i++)check(i,p[i-1],p[i]-1);
    check(to_len,p[to_len-1],to);
  }

  cout<<r<<endl;
}