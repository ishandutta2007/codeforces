#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
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
int i,j,m,n,p,k,trie[N][26],End[N],root,tot=1,f[N],L[N],last[N],Q[N];
char c[N],s[N];
string w[N];
int W(char c)
{
  if (c<='Z') return c-'A'+'a';
  return c;
}
int main()
{
	  scanf("%d",&n);
	  scanf("%s",c);
	  scanf("%d",&m); root=1;
	  for (i=1;i<=m;++i)
	  {
	       scanf("%s",s);
	       int len=strlen(s);
	       for (j=0,p=1;j<len;++j)
	       {
	       	  if (!trie[p][W(s[j])-'a']) trie[p][W(s[j])-'a']=++tot;
	       	  p=trie[p][W(s[j])-'a'];
	       }
	       End[p]=i;
	       w[i]=(string)s;
	  }
	  f[0]=1;
	  for (i=1;i<=n;++i)
	  {
		  	    for (p=1,j=0;p&&i-j>=0;++j)
	  	    {
	  	    	   if (End[p]&&f[i-j]) break;
	  	    	   if (i-j-1>=0)
	  	    	   p=trie[p][c[i-j-1]-'a'];
	  	    }
	  	    if (End[p]) f[i]=1,L[i]=End[p],last[i]=i-j;
	  }
	  int x=n;
	  for (;x;x=last[x]) Q[++Q[0]]=L[x];
	  for (i=Q[0];i;--i) 
	  {
	  	   cout<<w[Q[i]];
	  	   printf(" ");
	  }
}