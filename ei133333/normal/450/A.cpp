#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  typedef pair< int , int > Pi;
  queue< Pi > que;

  //Input
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
    que.push( Pi( i + 1, a));
  }

  //Run
  while(que.size() != 1){
    Pi p = que.front(); que.pop();
    p.second -= m;
    if(p.second > 0){
      que.push(p);
    }
  }

  //Output
  cout << que.front().first << endl;

  return(0);
}