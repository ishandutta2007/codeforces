#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,k;
const int MAX=1100000;
char s[MAX],r[MAX];
int pi[MAX];
int main(){
  scanf("%d %d %s",&n,&k,s);
  pi[0]=pi[1]=0;
  for(int i=2;i<=n;i++){
    pi[i]=pi[i-1];
    while(pi[i]>0&&s[i-1]!=s[pi[i]]){
      pi[i]=pi[pi[i]];
    }
    pi[i]+=s[i-1]==s[pi[i]];
  }
  //for(int i=1;i<=n;i++)printf("%d\n",pi[i]);
  for(int i=1;i<=n;i++)r[i-1]=k==1?'1':'0';
  r[n]=0;
  for(int i=1;i<=n;i++){
    int period=i-pi[i];
    if(i%period)continue;
    int cnt=i/period;
    if(cnt%k==0||cnt%(k+1)==0){
      //printf("%d\n",i);
      r[i-1]='1';
    }
  }
  if(k>1)for(int i=1;i<=n;i++){
    int period=i-pi[i];
    if((long long)k*period>i)continue;
    int a=i/(k*period);
    int len=period*a;
    if(i%((long long)k*len)<=len)r[i-1]='1';
  }
  printf("%s\n",r);
  return 0;
}