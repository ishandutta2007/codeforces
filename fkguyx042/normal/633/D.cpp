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

#define N 1005
#define M 200005
#define seed 23333
#define Mo 100007

using namespace std;
int i,j,m,n,p,k,a[N],ans,Q[N],l;
vector<int>v[Mo];
vector<int>sum[Mo];
void del(int x)
{
	  int p=abs(x)%Mo,j;
	  for (j=0;j<(int)v[p].size();++j) if (v[p][j]==x) break;
	  sum[p][j]--;
}
void ins(int x)
{
	  int p=abs(x)%Mo,j;
	  for (j=0;j<(int)v[p].size();++j) if (v[p][j]==x) break;
	  sum[p][j]++;
}     
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),ans+=(a[i]==0);
	  for (i=1;i<=n;++i)
	  {
	  	   int p=abs(a[i])%Mo,S=v[p].size();
	  	   for (j=0;j<S;++j) if (v[p][j]==a[i]) break;
	  	   if (j==S) v[p].push_back(a[i]),sum[p].push_back(1);
	  	   else sum[p][j]++;
	  }
	  //printf("%d\n",sum[35][0]);
	  for (i=1;i<=n;++i) 
	    for (j=1;j<=n;++j)
	      if (i!=j)
	      {
	      	   if (a[i]==0&&a[j]==0) continue;
	      	   int A=a[i],B=a[j]; del(A); del(B); Q[Q[0]=1]=A,Q[++Q[0]]=B;
	      	   for (l=2;;++l)
	      	   {
	      	   	    int C=A+B,p=abs(C)%Mo;
	      	   	    for (k=0;k<(int)v[p].size();++k) if (v[p][k]==C) break;
	      	   	    if (k==v[p].size()||sum[p][k]==0) break;
	      	   	    Q[++Q[0]]=C;
	      	   	    del(C);
	      	   	    A=B; B=C;
	      	   }
	      	   ans=max(ans,l);
	      	   for(k=1;k<=Q[0];++k) ins(Q[k]);
	      }
	  printf("%d\n",ans);
}