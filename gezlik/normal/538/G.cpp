#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=200000,M=2000000;

int n,m;//,flag;
struct thing{
  LL t,x,y;
}tmp[N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i){
    LL x,y;
    scanf("%lld%lld%lld",&tmp[i].t,&x,&y);
    if (tmp[i].t&1^x+y&1) {puts("NO");exit(0);}
    tmp[i].x=x-y;tmp[i].y=x+y;
  }
  //if (n==N&&m==M&&tmp[1].t==1&&tmp[2].t==2) flag=1;
}

LL tim[N+9],a[N+9],b[N+9],cnt[N+9];

bool cmp(const thing &a,const thing &b){return a.t%m<b.t%m;}

void Get_tim(){
  sort(tmp+1,tmp+n+1,cmp);
  for (int i=1;i<=n;++i){
    tim[i]=tmp[i].t;
    a[i]=tmp[i].x;b[i]=tmp[i].y;
    cnt[i]=tim[i]/m;tim[i]%=m;
  }
}

LL down_div(LL a,LL b){return a<0?(a-b+1)/b:a/b;}
LL up_div(LL a,LL b){return a<0?a/b:(a+b-1)/b;}

void Get_lr(LL k,LL a,LL d,LL &L,LL &R){
  if (!k){
    if (a>d) {puts("NO");exit(0);}
    return;
  }
  if (k<0){
    k=-k;
    d=d-a;
    R=min(R,down_div(d,k));
  }else{
    d=a-d;
    L=max(L,up_div(d,k));
  }
}

void Get_lr(LL *a,LL &L,LL &R){
  L=-m;R=m;
  a[n+1]=tim[n+1]=0;
  for (int i=1;i<=n+1;++i){
    LL d=abs(tim[i]-tim[i-1]);
    Get_lr(cnt[i]-cnt[i-1],a[i]-a[i-1],d,L,R);
    Get_lr(cnt[i-1]-cnt[i],a[i-1]-a[i],d,L,R);
  }
  Get_lr(-1-cnt[n],-a[n],m-tim[n],L,R);
  Get_lr(1+cnt[n],a[n],m-tim[n],L,R);
  if (L>R) {puts("NO");exit(0);}
}

LL ans[2][M+9];

bool Get_ans(int l,int r,LL d,LL *ans){
  LL now=0;
  for (int i=l;i<=r;++i) ans[i]=now<=d?(++now,1):(--now,-1);
  return now==d;
}

bool Get_ans(LL *a,LL p,LL *ans){
  a[n+1]=p;tim[n+1]=m;
  for (int i=1;i<=n+1;++i){
    LL x=a[i-1]-cnt[i-1]*p,y=a[i]-cnt[i]*p;
    if (!Get_ans(tim[i-1]+1,tim[i],y-x,ans)) return 0;
  }
  return 1;
}

void Get_ans(LL *a,LL *ans){
  LL l,r;
  Get_lr(a,l,r);
  for (int i=0;i<5&&l+i<=r;++i)
    if (Get_ans(a,l+i,ans)) return;
  for (int i=0;i<5&&r-i>=l;++i)
    if (Get_ans(a,r-i,ans)) return;
  puts("NO");
  exit(0);
}

void work(){
  Get_tim();
  Get_ans(a,ans[0]);
  Get_ans(b,ans[1]);
}

void outo(){
  for (int i=1;i<=m;++i)
    putchar(ans[0][i]==1?ans[1][i]==1?'R':'D':ans[1][i]==1?'U':'L');
  puts("");
}

int main(){
  //freopen("sea.in","r",stdin);
  //freopen("sea.out","w",stdout);
  into();
  work();
  outo();
  return 0;
}