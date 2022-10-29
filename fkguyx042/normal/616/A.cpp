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
int i,j,m,n,p,k,A[N],B[N],l;
char c[N];
int main()
{
	  scanf("%s",c);
	  int len=strlen(c);
	  for (l=0;l<len-1&&c[l]=='0';++l);
	  for (;l<len;++l) A[++A[0]]=c[l]-'0';
	  scanf("%s",c);
	  len=strlen(c);
	  for (l=0;l<len-1&&c[l]=='0';++l);
	  for (;l<len;++l) B[++B[0]]=c[l]-'0';
	  if (A[0]<B[0]) printf("<");
	  else if (A[0]>B[0]) printf(">");
	  else 
	  {
	      for (i=1;i<=A[0];++i) if (A[i]!=B[i]) break;
		  if (A[i]<B[i]) printf("<");
		  else if (A[i]>B[i]) printf(">");
		  else printf("=");
	  }
}