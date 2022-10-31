#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
int a[1000005],val[1005];
int gcd(int a,int b){return (!b)?a:gcd(b,a%b);}
inline int abs(int a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
unsigned int Rand(){return 1U*rand()*rand()%19260817;}
int query(int opt,int x)
{
	if(opt==1) printf("? %d\n",x);
	else printf("> %d\n",x);
	fflush(stdout);
	int tmp;
	scanf("%d",&tmp);
	return tmp;
}
int main()
{
	memset(a,255,sizeof(a));
	srand(time(0));
	int n;
	scanf("%d",&n);
	int l=0,r=1000000000,cnt=0;
	while(l<r)
	{
		++cnt;
		int mid=(l+r)>>1;
		if(query(2,mid)) l=mid+1;
		else r=mid;
	}
	int p,pos=0,cur;
	for(int i=cnt+1;i<60;++i)
	{
		cur=0;
		do{p=Rand()%n+1,++cur;}while((~a[p])&&(cur<5));
		a[p]=query(1,p);
		val[++pos]=a[p];
	}
	std::sort(val+1,val+pos+1);
	int ans=abs(val[2]-val[1]);
	for(int i=3;i<=pos;++i)
	{
		ans=gcd(ans,abs(val[i]-val[i-1]));
	}
	printf("! %d %d\n",l-(n-1)*ans,ans);
	fflush(stdout);
	return 0;
}