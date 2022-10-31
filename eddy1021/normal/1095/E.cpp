#include <bits/stdc++.h>
using namespace std;
const int N=1<<20;
int n, ans;
char c[N];
int rmn[N], rsum[N];
int main(){
  scanf("%d", &n);
  scanf("%s", c+1);
  for(int i=n, tmn=0, tsum=0; i>=1; i--){
    if(c[i] == ')') tsum++;
    else tsum--;
    tmn=min(tmn, tsum);
    rmn[i]=tmn;
    rsum[i]=tsum;
  }
  for(int i=1, tmn=0, tsum=0; i<=n; i++){
    int aslsum=tsum+1;
    int aslmn=min(tmn, aslsum);
    int asrsum=tsum-1;
    int asrmn=min(tmn, asrsum);
    if(c[i] == '('){
      if(asrmn>=0 and rmn[i+1]>=0 and asrsum==rsum[i+1]) ans++;
      tmn=aslmn;
      tsum=aslsum;
    }else{
      if(aslmn>=0 and rmn[i+1]>=0 and aslsum==rsum[i+1]) ans++;
      tmn=asrmn;
      tsum=asrsum;
    }
  }
  printf("%d\n", ans);
}