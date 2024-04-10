#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>

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
int i,j,m,n,p,k;
map<string,int>mp;
string c[N];
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) cin>>c[i];
	  for (i=n;i;--i)
	  	  if (!mp[c[i]])
	  {
	  	  mp[c[i]]=1;
	  	  cout<<c[i]<<endl;
	  }
}