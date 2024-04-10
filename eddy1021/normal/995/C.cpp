#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> Pt;
const int N=101010;
#define X first
#define Y second
Pt operator+(const Pt& a, const Pt& b){
  return {a.X+b.X, a.Y+b.Y};
}
Pt operator-(const Pt& a, const Pt& b){
  return {a.X-b.X, a.Y-b.Y};
}
LL sqr(LL x){ return x*x; }
LL norm(const Pt& a){
  return sqr(a.X)+sqr(a.Y);
}
void scan(Pt& tp){
  scanf("%lld%lld", &tp.X, &tp.Y);
}
int n, sgn[N], ord[N];
Pt p[N], cur;
const LL LIM=1500000LL*1500000LL;
void output(){
  for(int i=0; i<n; i++)
    printf("%d%c", sgn[i], " \n"[i+1==n]);
  exit(0);
}
void go(int ptr){
  if(ptr == n){
    if(norm(cur) <= LIM)
      output();
    return;
  }
  int i=ord[ptr];
  int si=1;
  if(norm(cur-p[i]) < norm(cur+p[i]))
    si=-1;
  for(int _=0; _<2; _++, si=-si){
    sgn[i]=si;
    if(si==1) cur=cur+p[i];
    else cur=cur-p[i];
    go(ptr+1);
    if(si==1) cur=cur-p[i];
    else cur=cur+p[i];
  }
}
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scan(p[i]);
  for(int i=0; i<n; i++)
    ord[i]=i;
  random_shuffle(ord, ord+n);
  go(0);
}