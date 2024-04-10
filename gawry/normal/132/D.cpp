#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 1100000
char s[MAX];
int t[MAX][2];
void go(int pos,int add,int power){
//printf("%d %d %d : %d\n",pos,add,power,t[pos][add]);
  if(!pos){
    if(add)printf("+2^%d\n",power);
  }else{
    int val=s[pos-1]-'0';
    for(int a=0;a<2;a++)for(int b=0;b<2;b++)if(a+b<2){
      if(!add&&(val+a)%2==b&&t[pos][0]==a+b+t[pos-1][(val+a)/2]){
        go(pos-1,(val+a)/2,power+1);
        if(a)printf("-2^%d\n",power);
        if(b)printf("+2^%d\n",power);
        return;
      }
      if(add&&(val+a+1)%2==b&&t[pos][1]==a+b+t[pos-1][(val+a+1)/2]){
        go(pos-1,(val+a+1)/2,power+1);
        if(a)printf("-2^%d\n",power);
        if(b)printf("+2^%d\n",power);
        return;
      }
    }
  }
}
main(){
  scanf(" %s",s);
  t[0][0]=0;
  t[0][1]=1;
  int n=strlen(s);
  for(int i=0;i<n;i++){
    int val=s[i]-'0';
    t[i+1][0]=t[i+1][1]=MAX;
    for(int a=0;a<2;a++)for(int b=0;b<2;b++)if(a+b<2){
      if((val+a)%2==b)t[i+1][0]=min(t[i+1][0],a+b+t[i][(val+a)/2]);
      if((val+a+1)%2==b)t[i+1][1]=min(t[i+1][1],a+b+t[i][(val+a+1)/2]);
    }
  }
  printf("%d\n",t[n][0]);
  go(n,0,0);
}