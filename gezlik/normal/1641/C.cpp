#include<bits/stdc++.h>
using namespace std;

typedef long long int64;

const int N=200000,C=21;

int n,cq;
struct question{
  int opt,l,r,x;
  question():opt(),l(),r(),x(){}
  question(int _opt,int _l,int _r,int _x):opt(_opt),l(_l),r(_r),x(_x){}
}q[N+9];

void In(){
  scanf("%d%d",&n,&cq);
  for (int i=1;i<=cq;++i){
    int opt,l=0,r=0,x;
    scanf("%d",&opt);
    opt?
      scanf("%d",&x)
    :
      scanf("%d%d%d",&l,&r,&x);
    q[i]=question(opt,l,r,x);
  }
}

int f[N+9],uni[N+9];

int Query_uni(int k){return k==uni[k]?k:uni[k]=Query_uni(uni[k]);}

void Get_f(){
  for (int i=1;i<=n;++i) f[i]=cq+1,uni[i]=i;
  uni[n+1]=n+1;
  for (int i=1;i<cq;++i){
    if (q[i].opt||q[i].x) continue;
    for (int k=Query_uni(q[i].l);k<=q[i].r;k=Query_uni(k)){
      f[k]=i;
      uni[k]=k+1;
    }
  }
}

int lg[N+9];
pair<int,int>mx[C][N+9];

void Get_mx(){
  for (int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
  for (int i=1;i<=n;++i) mx[0][i]=make_pair(f[i],i);
  for (int i=1;i<C;++i)
    for (int j=1;j+(1<<i)-1<=n;++j)
      mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]);
}

pair<int,int>Query_max(int l,int r){
  if (l>r) return make_pair(0,0);
  int t=lg[r-l+1];
  return max(mx[t][l],mx[t][r-(1<<t)+1]);
}

int g[N+9];

void Get_g(){
  for (int i=1;i<=n;++i) g[i]=cq+1;
  for (int i=1;i<=cq;++i){
    if (q[i].opt||!q[i].x) continue;
    auto [rub,p]=Query_max(q[i].l,q[i].r);
    g[p]=min(g[p],max({
      i,
      Query_max(q[i].l,p-1).first,
      Query_max(p+1,q[i].r).first
    }));
  }
}

void Out(){
  for (int i=1;i<=cq;++i){
    if (!q[i].opt) continue;
    int p=q[i].x;
    puts(f[p]<=i?"NO":g[p]<=i?"YES":"N/A");
  }
}

void work(){
  In();
  Get_f();
  Get_mx();
  Get_g();
  Out();
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;) work();
  return 0;
}