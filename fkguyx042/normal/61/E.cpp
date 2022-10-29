#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 1000005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,a[N],fr[N],be[N],tree[N];
struct Node{int id,x;}A[N];
inline bool cmp(Node a,Node b)
{
	  if (a.x!=b.x) return a.x>b.x;
	  return a.id>b.id;
}
int lowbit(int x) { return x&-x; }
int ask(int x)
{
	  int sum=0;
	  for (;x;x-=lowbit(x)) sum+=tree[x];
	  return sum;
}
void insert(int x)
{
	  for (;x<=n;x+=lowbit(x)) tree[x]++;
}
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),A[i].x=a[i],A[i].id=i;
	  sort(A+1,A+n+1,cmp);
	  for (i=1;i<=n;++i)
	  {
	  	 fr[A[i].id]=ask(A[i].id-1);
	  	insert(A[i].id);
	  }
	  memset(tree,0,sizeof(tree));
	  for (i=n;i;--i)
	  {
	  	 be[A[i].id]=ask(n)-ask(A[i].id);
	  	 insert(A[i].id);
	  }
	  long long ans=0;
	  for (i=1;i<=n;++i) ans+=1ll*fr[i]*be[i];
	  cout<<ans<<endl;
}