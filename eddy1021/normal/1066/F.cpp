#include <bits/stdc++.h>
using namespace std;
const int N=202020;
typedef long long LL;
#define X first
#define Y second
LL ans;
int n;
pair<int,int> a[N];
LL dp[2];
int posX[2], posY[2];
inline int lvl(const pair<int,int>& pp){
  return max(pp.X, pp.Y);
}
LL dist(const pair<int,int>& p1,
        const pair<int,int>& p2){
  return abs(p1.X-p2.X)+abs(p1.Y-p2.Y);
}
int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    scanf("%d%d", &a[i].X, &a[i].Y);
  sort(a, a+n, [&](pair<int,int> p1, pair<int,int> p2){
       return lvl(p1) < lvl(p2); 
       });
  for(int l=0, r=0; l<n; l=r){
    while(r<n and lvl(a[l])==lvl(a[r])) r++;
    sort(a+l, a+r, [&](pair<int,int> p1, pair<int,int> p2){
         if(p1.X != p2.X) return p1.X<p2.X;
         return p1.Y>p2.Y;
         });
    LL pdp[2];
    int pposX[2], pposY[2];
    for(int i=0; i<2; i++){
      pdp[i]=dp[i];
      pposX[i]=posX[i];
      pposY[i]=posY[i];
    }
    LL dst=0;
    for(int i=l+1; i<r; i++)
      dst+=dist(a[i-1], a[i]);
    for(int c=0; c<2; c++){
      tie(posX[c], posY[c])=(c==0?a[l]:a[r-1]);
      dp[c]=1e18;
      for(int p=0; p<2; p++)
        dp[c]=min(dp[c], 
                  pdp[p]+dst+dist({pposX[p], pposY[p]}, c==0?a[r-1]:a[l]));
    }
  }
  cout<<min(dp[0], dp[1])<<endl;
}