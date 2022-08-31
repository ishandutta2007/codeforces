#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, M;
  cin >> N >> M;

 
  queue< int > que;
  que.push(N);
  vector< int > min_costs(20001, 1000000);
  min_costs[N] = 0;
  while(!que.empty()){
    int p = que.front(); que.pop();
    if(p - 1 > 0) {
      if(min_costs[p - 1] > min_costs[p] + 1){
        que.push(p - 1);
        min_costs[p - 1] = min_costs[p] + 1;
      }
    }
    if(p * 2 < 20001) {
      if(min_costs[p * 2] > min_costs[p] + 1) {
        que.push(p * 2);
        min_costs[p * 2] = min_costs[p] + 1;
      }
    }               
  }
  cout << min_costs[M] << endl;
}