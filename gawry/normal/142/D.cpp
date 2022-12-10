#include<cstdio>
#include<vector>
using namespace std;
int n,m,k;
char t[110][110];
main(){
  scanf("%d %d %d",&n,&m,&k);
  for(int i=0;i<n;i++)scanf(" %s",t[i]);
  if(m==1){
    puts("Second");
    return 0;
  }
  bool green=false,red=false;
  vector<int> s;
  for(int i=0;i<n;i++){
    int x=0,y=m-1;
    while(t[i][x]=='-'&&x<=y)++x;
    while(t[i][y]=='-'&&x<=y)--y;
    if(x>y)continue;
    if(t[i][x]==t[i][y]){
      green|=t[i][x]=='G'&&(m>2||x==y);
      red|=t[i][x]=='R'&&(m>2||x==y);
    }else{
      s.push_back(y-x-1);
    }
  }
  if(green&&red){
    puts("Draw");
    return 0;
  }
  int v[110]={};
  for(int i=0;i<s.size();i++){
    int tmp=s[i],pos=0;
    while(tmp){
      v[pos]=(v[pos]+tmp%2)%(k+1);
      tmp/=2;
      ++pos;
    }
  }
  bool zero=true;
  for(int i=0;i<110;i++)zero&=!v[i];
  if(zero){
    if(green)if(red)puts("Draw");else puts("First");
    else puts("Second");
  }else{
    if(red)puts("Draw");else puts("First");
  }
}