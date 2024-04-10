#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 100005
#define M 505

using namespace std;
struct Node{int l,r,k;}A[M];
char c[N],s[N];
int i,j,m,n,p,k,L[M],R[M],l,r,sum,Rel[26][N],Ans[N];
long long ans;
void del(int x)
{
	  if (x<=i) return;
	  if (Ans[x]==l) --sum;
	  if (Ans[x]==r+1) ++sum;
	  --Ans[x];
}
void ins(int x)
{
	  if (x<=i) return;
	  if (Ans[x]==l-1) ++sum;
	  if (Ans[x]==r) --sum;
	  ++Ans[x];
}
int main()
{
	scanf("%s",c);
	n=strlen(c);
	for (i=n;i;--i) c[i]=c[i-1];
	scanf("%d%d%d",&m,&l,&r);
	for (i=1;i<=m;++i)
	{
		 L[i]=R[i]=1;
		 scanf("%s%d%d",s,&A[i].l,&A[i].r);
		 A[i].k=s[0]-'a';
	}
	for (i=1;i<=n;++i)
	  for (j=0;j<26;++j)
	   Rel[j][i]=Rel[j][i-1]+(c[i]==j+'a');
	for (i=1;i<=m;++i)
	{
		for (;L[i]<=n&&Rel[A[i].k][L[i]]<A[i].l;++L[i]);
		for (;R[i]<=n&&Rel[A[i].k][R[i]]<=A[i].r;++R[i]);
		for (j=L[i];j<R[i];++j) Ans[j]++;
   }
    for (i=1;i<=n;++i) if (Ans[i]>=l&&Ans[i]<=r) ++sum;
    ans+=sum;
	for (i=1;i<n;++i)
	{
		if (l<=Ans[i]&&Ans[i]<=r) --sum;
	  for (j=1;j<=m;++j)
	  {
	  	   
	  	  for (;L[j]<=i||
		  L[j]<=n&&Rel[A[j].k][L[j]]-Rel[A[j].k][i]<A[j].l;++L[j]) del(L[j]);
		  for (;R[j]<=i||
		  R[j]<=n&&Rel[A[j].k][R[j]]-Rel[A[j].k][i]<=A[j].r;++R[j]) ins(R[j]);
	  }
	  ans+=sum;
   }
   printf("%I64d\n",ans);
}