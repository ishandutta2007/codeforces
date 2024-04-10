#include <bits/stdc++.h>
using namespace std;
int a, b, x;
int main(){
  cin>>a>>b>>x;
  char A='0', B='1';
  if(a<b) swap(a,b), swap(A,B);
  vector<int> vv;
  for(int i=0; i<=x; i++){
    vv.push_back(i%2);
    if(i%2) b--;
    else a--;
  }
  for(int j: vv){
    if(j%2){
      for(int i=0; i<b; i++)
        putchar(B);
      b=0;
      putchar(B);
    }else{
      for(int i=0; i<a; i++)
        putchar(A);
      a=0;
      putchar(A);
    }
  }
  puts("");
}