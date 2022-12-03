#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=300000;

int n,cq,a[N+9];
struct question{
  int l,r,id;
  question(int L=0,int R=0,int Id=0){l=L;r=R;id=Id;}
}q[N+9];

void into(){
  scanf("%d%d",&n,&cq);
  for (int i=1;i<=n;++i)
	scanf("%d",&a[i]);
  for (int i=1;i<=cq;++i){
	scanf("%d%d",&q[i].l,&q[i].r);
	++q[i].l;
	q[i].r=n-q[i].r;
	q[i].id=i;
  }
}

int c[N+9];

void Add(int p,int v){for (;p<=n;p+=p&-p) c[p]+=v;}
int Query(int p){int res=0;for (;p;p-=p&-p) res+=c[p];return res;}

int ans[N+9];

void Get_ans(){
  sort(q+1,q+cq+1,[&](const question &a,const question &b){return a.r<b.r;});
  for (int i=1,j=1;i<=n;++i){
	if (a[i]<=i){
	  int l=1,r=i,p=0;
	  for (int mid;l<=r;Query(mid=l+r>>1)>=i-a[i]?(p=mid,l=mid+1):r=mid-1);
	  Add(1,1);
	  Add(p+1,-1);
	  //printf("%d %d\n",i,p);
	}
	for (;j<=cq&&q[j].r==i;++j) ans[q[j].id]=Query(q[j].l);
  }
}

void work(){
  Get_ans();
}

void outo(){
  for (int i=1;i<=cq;++i)
	printf("%d\n",ans[i]);
}

int main(){
  int T=1;
  //scanf("%d",&T);
  for (;T--;){
    into();
    work();
    outo();
  }
  return 0;
}