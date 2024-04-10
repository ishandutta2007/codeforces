#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int n;
char s[110];
int main(){
  scanf("%d %s",&n,s);
  bool found=false;
  for(int i=0;i<n;i++)if(s[i]=='*')for(int d=1;i+d<n;d++){
    int cnt=1;
    while(cnt<=4&&i+cnt*d<n&&s[i+cnt*d]=='*'){
      ++cnt;
    }
    found|=cnt>4;
  }
  printf(found?"yes\n":"no\n");
  return 0;
}