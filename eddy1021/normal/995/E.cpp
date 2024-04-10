#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int U, V, p;
inline int add(int a, int b){
  a+=b;
  return a>=p?a-p:a;
}
inline int add1(int a){
  return a+1==p?0:a+1;
}
inline int sub1(int a){
  return a?a-1:p-1;
}
inline int mul(LL a, int b){
  a*=b;
  return a>=p?a%p:a;
}
inline int mpow(int a, int b){
  int r=1;
  while(b){
    if(b&1) r=mul(r, a);
    a=mul(a, a);
    b>>=1;
  }
  return r;
}
inline int inv(int a){
  return mpow(a, p-2);
}
void output(const deque<int>& v){
  printf("%d\n", (int)v.size());
  for(size_t i=0; i<v.size(); i++)
    printf("%d%c", v[i], " \n"[i+1==v.size()]);
  exit(0);
}
const int LIM=(1<<18);
const int LEN=100;
unordered_map<int, deque<int>> memo;
int main(){
  cin>>U>>V>>p;
  if(U == V){
    puts("0");
    exit(0);
  }
  for(int i=0; i<LIM; i++){
    deque<int> tmp;
    int c=U;
    for(int j=0; j<LEN; j++){
      int op=rand()%3+1;
      if(op==1) c=add1(c);
      if(op==2) c=sub1(c);
      if(op==3) c=inv(c);
      tmp.push_back(op);
      if(c==V) output(tmp);
      //auto it=memo.find(c);
      //if(it==memo.end() or j+1<(int)it->second.size())
        //memo[c]=tmp;
    }
    memo[c]=tmp;
  }
  for(int i=0; i<LIM; i++){
    deque<int> tmp;
    int c=V;
    for(int j=0; j<LEN; j++){
      int op=rand()%3+1;
      if(op==1) c=sub1(c);
      if(op==2) c=add1(c);
      if(op==3) c=inv(c);
      tmp.push_front(op);
      if(c==U) output(tmp);
      auto it=memo.find(c);
      if(it != memo.end()){
        for(auto x: tmp) it->second.push_back(x);
        output(it->second);
      }
    }
  }
  assert(false);
}