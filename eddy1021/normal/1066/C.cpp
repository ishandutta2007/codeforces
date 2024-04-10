#include <bits/stdc++.h>
using namespace std;
const int N=202020;
int q, l, r, at[N];;
char cmd[256];
int main(){
  scanf("%d", &q); while(q--){
    int id;
    scanf("%s%d", cmd, &id);
    if(cmd[0] == 'L') at[id]=--l;
    else if(cmd[0] == 'R') at[id]=r++;
    else printf("%d\n", min(r-at[id]-1, at[id]-l));
  }
}