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

#define N 200005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,len,L,Q[N],H[N],sum[N][26];
char s[N],c[N];
int main()
{
	  scanf("%s",s); len=strlen(s); for (i=len;i;--i) s[i]=s[i-1];
	  scanf("%s",c); L=strlen(c);   for (i=L;i;--i)   c[i]=c[i-1];
	  for (i=1;i<=L;++i)
	  {
	  	   for (j=0;j<26;++j) sum[i][j]+=sum[i-1][j];
		   sum[i][c[i]-'a']++;
	  }
	  for (i=1;i<=len;++i) 
	     if (Q[i-1]<L&&s[i]==c[Q[i-1]+1]) Q[i]=Q[i-1]+1;
	     else Q[i]=Q[i-1];
	  H[len+1]=L+1;
	  for (i=len;i;--i)
	     if (H[i+1]>1&&s[i]==c[H[i+1]-1]) H[i]=H[i+1]-1;
	     else H[i]=H[i+1];
	  for (i=1;i<=len;++i) 
	   if (H[i+1]-Q[i-1]>2) { printf("No\n"); return 0; }
	   else if (H[i+1]-Q[i-1]==2)
	   {
	   	    if (s[i]!=c[H[i+1]-1]) { printf("No\n"); return 0; }
	   }
	   else 
	   {
	   	   int Lx=max(1,H[i+1]-1),Rx=min(L,Q[i-1]+1);
	   	   if (sum[Rx][s[i]-'a']-sum[Lx-1][s[i]-'a']==0) { printf("No\n"); return 0; }
	   }
	   printf("Yes\n");
}