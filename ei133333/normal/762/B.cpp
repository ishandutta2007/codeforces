#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int A, B, C, M;
  priority_queue< int, vector< int >, greater< int > > usb, ps2;

  cin >> A >> B >> C;
  cin >> M;
  for(int i = 0; i < M; i++) {
    int val;
    string type;
    cin >> val >> type;
    if(type == "USB") usb.push(val);
    else ps2.push(val);
  }

  int64 ret = 0, cnt = 0;
  while(A > 0 && !usb.empty()) {
    ret += usb.top();
    --A;
    ++cnt;
    usb.pop();
  }
  while(B > 0 && !ps2.empty()) {
    ret += ps2.top();
    --B;
    ++cnt;
    ps2.pop();
  }

  while(!ps2.empty()) {
    usb.push(ps2.top());
    ps2.pop();
  }
  while(C > 0 && !usb.empty()) {
    ret += usb.top();
    --C;
    ++cnt;
    usb.pop();
  }

  cout << cnt << " " << ret << endl;

}