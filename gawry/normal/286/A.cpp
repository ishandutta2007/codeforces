#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n,p[100001];
main(){
  scanf("%d",&n);
  if(n%2){
    if(n%4==3){
      puts("-1");
    }else{
      p[n/2]=n/2;
      for(int i=0;i<n/4;i++){
        int first=2*i,second=2*i+1,third=n-1-2*i,fourth=n-1-2*i-1;
        p[first]=second;
        p[second]=third;
        p[third]=fourth;
        p[fourth]=first;
      }
      for(int i=0;i<n;i++)printf("%d ",p[i]+1);puts("");
    }
  }else{
    if(n%4==2){
      puts("-1");
    }else{
      for(int i=0;i<n/4;i++){
        int first=2*i,second=2*i+1,third=n-1-2*i,fourth=n-1-2*i-1;
        p[first]=second;
        p[second]=third;
        p[third]=fourth;
        p[fourth]=first;
      }
      for(int i=0;i<n;i++)printf("%d ",p[i]+1);puts("");
    }
  }
}