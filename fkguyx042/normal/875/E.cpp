#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,f[N],a[N],A[N],B[N],s1,s2,Max[N],F[N];

int getA(int x)
{
		if (!A[0]||a[i]-a[A[1]]<=x) return n+1;
		int l=1,r=A[0]+1,mid=0;
		while ((l+r)>>1!=mid)
		{
				mid=(l+r)>>1;
				if (a[i]-a[A[mid]]>x) l=mid;
				else r=mid;
		}
		return A[mid];
}

int getB(int x)
{
		if (!B[0]||a[B[1]]-a[i]<=x) return n+1;
		int l=1,r=B[0]+1,mid=0;
		while ((l+r)>>1!=mid)
		{
				mid=(l+r)>>1;
				if (a[B[mid]]-a[i]>x) l=mid;
				else r=mid;
		}
		return B[mid];
}

void insA(int x)
{
		while (A[0]&&a[A[A[0]]]>=a[x]) --A[0];
		A[++A[0]]=x;
}

void insB(int x)
{
		while (B[0]&&a[B[B[0]]]<=a[x]) --B[0];
		B[++B[0]]=x;
}


int check(int x)
{
		memset(f,0,sizeof(f)); 
		for (i=1;i<=n;++i)
		{
			 	if (abs(s1-a[i])>x) break;
			 	f[i]=1;
		}
		for (i=1;i<=n;++i)
		{
				if (abs(s2-a[i])>x) break;
				f[i]=1;
		}
		A[0]=B[0]=0;
		for (i=n;i;--i)
		{
			   Max[i]=min(getA(x),getB(x));
			   insA(i); insB(i); 
		}
		memset(F,0,sizeof(F)); 
		for (i=1;i<=n;++i)
		{
			F[i]+=F[i-1];
			f[i]|=(F[i]>0);
			F[i+1]++;
			F[Max[i]]--;
			if (!f[i]) return 0;
		}
		return 1;
}

int main()
{
		scanf("%d%d%d",&n,&s1,&s2);
		for (i=1;i<=n;++i) scanf("%d",&a[i]); 
		int l=abs(s2-s1),r=(int)1e9+1,mid=0;
		while ((l+r)>>1!=mid)
		{
				mid=(l+r)>>1;
				if (check(mid)) r=mid;
				else l=mid;
		}
		printf("%d\n",r);
}