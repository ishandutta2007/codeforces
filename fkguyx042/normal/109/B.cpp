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

#define N 100005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,pl,pr,vl,vr;
long long a[N],ans;
void Work(long long x)
{
	 if (x>1e10) return;
	 a[++a[0]]=x;
	 Work(x*10+4); Work(x*10+7);
}
long long work(long long sl,long long sr,long long el,long long er)
{
	  return max(0ll,min(sr,er)-max(sl,el)+1);
}
int main()
{
	Work(4); Work(7);
	sort(a+1,a+a[0]+1);
	scanf("%d%d%d%d%d",&pl,&pr,&vl,&vr,&k);
	for (i=1;i<=a[0];++i) if (k==1&&pl<=a[i]&&a[i]<=pr&&vl<=a[i]&&a[i]<=vr) --ans;
	int A=a[0]; a[0]=0;
	for (i=1;i+k<=A;++i)  ans+=1ll*work(pl,pr,a[i-1]+1,a[i])*work(vl,vr,a[i+k-1],a[i+k]-1),
	ans+=1ll*work(pl,pr,a[i+k-1],a[i+k]-1)*work(vl,vr,a[i-1]+1,a[i]);
	printf("%.10lf\n",1.*ans/(1.*(pr-pl+1)*(vr-vl+1)));
}