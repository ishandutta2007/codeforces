#include<cstdio>
#include<set>
#include<string>
using namespace std;
main(){
  set<string> t;
  int n;
  scanf("%d",&n);
  while(n--){
    char a[2][3];
    scanf(" %s %s %*s",a[0],a[1]);
    int x[4]={0,0,1,1},y[4]={0,1,1,0};
    string b;
    for(int i=0;i<4;i++){
      string tmp;
      for(int j=0;j<4;j++)tmp+=a[x[(i+j)%4]][y[(i+j)%4]];
      if(!b.size()||tmp<b)b=tmp; 
    }
    t.insert(b);
  }
  printf("%d\n",t.size());
}