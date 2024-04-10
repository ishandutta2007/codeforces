#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL l, r, x, y;
vector<LL> vx, vy;
set<pair<LL,LL>> sa;
void go(size_t cur, LL xx, LL yy){
  if(cur == vx.size()){
    if(l <= xx and xx <= r and
       l <= yy and yy <= r)
      sa.insert({xx, yy});
    return;
  }
  go(cur+1, xx*vx[cur], yy*vy[cur]);
  go(cur+1, xx*vy[cur], yy*vx[cur]);
}
int main(){
  cin>>l>>r>>x>>y;
  if(y%x){
    puts("0");
    exit(0);
  }
  if(y==1){
    LL ans=(l<=1 and 1<=r);
    cout<<ans<<endl;
    exit(0);
  }
  for(LL i=2; i*i<=y; i++){
    if(y % i) continue;
    LL nx=1, ny=1;
    while(y % i == 0){
      ny*=i;
      y/=i;
    }
    while(x % i == 0){
      nx*=i;
      x/=i;
    }
    vx.push_back(nx);
    vy.push_back(ny);
  }
  if(y>1){
    vx.push_back(x);
    vy.push_back(y);
  }
  go(0, 1, 1);
  cout<<sa.size()<<endl;
}