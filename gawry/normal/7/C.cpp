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
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;
typedef long long int64;

int64 power(int64 x,int64 k,int64 p) {
  int r=1;
  while (k) {
    if (k&1)
      r=((int64)r*x)%p;
    k>>=1;
    x=((int64)x*x)%p;
  }
  return r;
}

int64 alfa,beta;

int64 gcd(int64 a,int64 b) {
  if (!b) {
    alfa=1;
    beta=0;
    return a;
  }
  int64 d=gcd(b,a%b),z=beta;
  //alfa*b+(a-a/b*b)*beta=beta*a+(alfa-a/b*beta)*b
  beta=alfa-a/b*beta;
  alfa=z;
  return d;
}

int64 inverse(int64 a,int64 n) {
  gcd(a,n);
  return (n+alfa%n)%n;
}

int64 A,B,C,d;
int main() {
  cin>>A>>B>>C;
  d=gcd(abs(A),abs(B));
  C*=-1;
  if(C%d){cout<<-1<<endl;return 0;}
  C/=d;
  A/=d;
  B/=d;
  gcd(abs(A),abs(B));
  if(A<0)alfa*=-1;
  if(B<0)beta*=-1;
  alfa*=C;
  beta*=C;
  cout<<alfa<<" "<<beta<<endl;
  
  return 0;
}