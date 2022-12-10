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
int n;
const int MAX=100123;
char s[MAX];
int r[MAX][2][3];
int main(){
  scanf("%d %s",&n,s);
  for(int i=0;i<=n;i++)for(int prev=0;prev<=1;prev++)for(int cnt=0;cnt<=2;cnt++){
    r[i][prev][cnt]=-MAX;
  }
  for(int i=1;i<=n;i++){
    int next=s[i-1]-'0';
    for(int prev=0;prev<=1;prev++)for(int cnt=0;cnt<=2;cnt++){
      r[i][prev][cnt]=r[i-1][prev][cnt];
    }
    r[i][next][0]=1;
    for(int prev=0;prev<=1;prev++)for(int cnt=0;cnt<=2;cnt++){
      int cnt2=cnt+(prev==next);
      if(cnt2>2)continue;
      r[i][next][cnt2]=max(r[i][next][cnt2],r[i-1][prev][cnt]+1);
    }
  }
  int ans=-MAX;
  for(int prev=0;prev<=1;prev++)for(int cnt=0;cnt<=2;cnt++){
    ans=max(ans,r[n][prev][cnt]);
  }
  printf("%d\n",ans);
  return 0;
}