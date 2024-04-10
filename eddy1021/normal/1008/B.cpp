#include <bits/stdc++.h>
using namespace std;
int n,p=2e9;
int main(){
  cin>>n;while(n--){
    int x, y;
    cin>>x>>y;
    if(max(x,y)<=p) p=max(x,y);
    else if(min(x,y)<=p) p=min(x,y);
    else return puts("NO")*0;
  }
  puts("YES");
}