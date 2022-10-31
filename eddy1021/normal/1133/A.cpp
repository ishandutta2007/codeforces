#include <bits/stdc++.h>
using namespace std;
int a[2];
int main(){
  for(int i=0; i<2; i++){
    int h, m;
    scanf("%d:%d", &h, &m);
    a[i]=h*60+m;
  }
  a[0]=(a[0]+a[1])/2;
  printf("%02d:%02d\n", a[0]/60, a[0]%60);
}