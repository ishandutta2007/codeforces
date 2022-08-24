#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
#define pi pair<int,int>
#define pii pair<pi,int>
#define aa first
#define bb second
#define xx aa.aa
#define yy aa.bb
#define zz bb
#define mp make_pair
#define mpp(a,b,c) mp(mp(a,b),c)
using namespace std;
int n,a[100010],b[100010],x[100010];
char s[100010];
L p;
inline bool cmp(int i,int j)
{
	return (L)a[i]*b[j]>(L)a[j]*b[i];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k,l;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  {
	   scanf("%s",&s);
	   k=strlen(s);
	   for(j=0,l=0;j<k;j++)
	     if(s[j]=='s')
	       l++,a[i]++;
	     else
	       p+=l,b[i]++;
	   x[i]=i;
	  }
	sort(x+1,x+n+1,cmp);
	for(i=1,k=0;i<=n;i++)
	  {
	   p+=(L)k*b[x[i]];
	   k+=a[x[i]];
	  }
	cout<<p;
	return 0;
}