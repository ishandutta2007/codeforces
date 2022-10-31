#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int q, x, y, mx, my;
char cmd[8];
int main(){
  scanf("%d", &q); while(q--){
    scanf("%s%d%d", cmd, &x, &y);
    if(x>y) swap(x, y);
    if(cmd[0] == '+')
      mx=max(mx, x), my=max(my, y);
    else
      puts((x>=mx and y>=my)?"YES":"NO");
  }
}