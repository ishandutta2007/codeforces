#include <bits/stdc++.h>

using namespace std;


int main(){
  int n, m;
  scanf("%d%d",&n,&m);
  int on_left = m-1, on_right = n-m;
  int my_choice;
  if (on_left >= on_right) {
    my_choice = max(m-1, 1);
  } else {
    my_choice = min(m+1, n);
  }
  printf("%d\n",my_choice);
}