#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(int)(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
typedef vector<int> vi;
typedef long long int64;

int t,m,id,a[1001],n;
int main() {
  scanf("%d %d",&t,&m);
  id=1;
  while(t--){
    char buf[100];
    scanf(" %s",buf); 
    if(!strcmp(buf,"alloc")){
      scanf("%d",&n); 
      FOR(i,m-n+1)if(!accumulate(a+i,a+i+n,0)){
        FOR(j,n)a[i+j]=id;
        printf("%d\n",id);
        id++;
        goto ok; 
      }
      puts("NULL");  
ok:;
    }else if(!strcmp(buf,"erase")){
      scanf("%d",&n);
      bool found=0;
      FOR(i,m)if(a[i]&&a[i]==n){
        a[i]=0;
        found=1; 
      }
      if(!found)puts("ILLEGAL_ERASE_ARGUMENT");
    }else{
      int pos=0;
      FOR(i,m)if(a[i]){
        int tmp=a[i];
        a[i]=0;
        a[pos++]=tmp; 
      }
    }
  }
  return 0;
}