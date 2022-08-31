#include<bits/stdc++.h>
using namespace std;
typedef pair< int , int > Pi;

int main(){
  int n, k;
  Pi a[100];
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    cin >> a[i].first;
    a[i].second = i;
  }
  //gready (
  queue< Pi > que;

  int cnt = 0;

  for(int i = 0; i < k; i++){
    sort( a, a + n);
    if(a[n - 1].first - a[0].first < 2) break;
    a[n - 1].first--;
    a[0].first++;
    que.push( Pi( a[n - 1].second + 1, a[0].second + 1));
    cnt++;
  }

  sort( a, a + n);
  cout << a[n - 1].first - a[0].first << " " << cnt << endl;
  while(!que.empty()){
    cout << que.front().first << " " << que.front().second << endl;
    que.pop();
  }
}