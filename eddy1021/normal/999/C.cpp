#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=404040;
int n, k;
char c[N];
bool died[N];
int main(){
  scanf("%d%d", &n, &k);
  scanf("%s", c);
  for(int i=0; i<26 and k>0; i++)
    for(int j=0; j<n and k>0; j++)
      if(not died[j] and c[j] == 'a'+i){
        died[j]=true;
        k--;
      }
  for(int i=0; i<n; i++)
    if(not died[i])
      putchar(c[i]);
  puts("");
}