//SB,
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 100005
#define M 3000005
#define K 19
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,S,a[N],l,r,tot;
long long Ans,ans[N];
struct Tri{
  int sum[M];
  void ins(int x,int y)
  {
  	 sum[a[x]]+=y;
  }
  int get(int x)
  {
  	 return sum[a[x]^k];
  }
}trie[2];
struct Node{int x,y,id;}A[N];
inline bool cmp(Node a,Node b)
{
	  if (a.x/S!=b.x/S) return a.x/S<b.x/S;
	  return a.y<b.y;
}
void ins1(int x)
{
	 trie[1].ins(x,1);
	 trie[0].ins(x-1,1);
	 Ans+=trie[0].get(x);
}
void ins2(int x)
{
	 trie[1].ins(x,1);
	 trie[0].ins(x-1,1);
	 Ans+=trie[1].get(x-1);
}
void del1(int x)
{
	 Ans-=trie[0].get(x);
	 trie[0].ins(x-1,-1);
	 trie[1].ins(x,-1);
}
void del2(int x)
{
	 Ans-=trie[1].get(x-1);
	 trie[0].ins(x-1,-1);
	 trie[1].ins(x,-1);
}
int main()
{
	 scanf("%d%d%d",&n,&m,&k);
	 for (i=1;i<=n;++i) scanf("%d",&a[i]),a[i]^=a[i-1];
	 S=(int)sqrt(n);
	 for (i=1;i<=m;++i) scanf("%d%d",&A[i].x,&A[i].y),A[i].id=i;
	 sort(A+1,A+m+1,cmp);
		 for(i=A[1].x;i<=A[1].y;++i) 
		 ins1(i);
	 l=A[1].x; r=A[1].y;
	 for (i=1;i<=m;++i)
	 {
	 	  while (l<A[i].x) del2(l++);
	 	  while (l>A[i].x) ins2(--l);
	 	  while (r<A[i].y) ins1(++r);
	 	  while (r>A[i].y) del1(r--);
	 	  ans[A[i].id]=Ans;
	 }
	 for (i=1;i<=m;++i) printf("%I64d\n",ans[i]);
}