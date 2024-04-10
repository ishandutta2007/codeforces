#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
const int N=2e5+100,mod=998244353,maxn=2e5;
int mi(int x,int t){
	int d=1;
	while(t){
		if(t%2) d=(ll)d*x%mod;
		x=(ll)x*x%mod;t/=2;
	}
	return d;
}
int ni(int x) {return mi(x,mod-2);}

#define lowbit(x) ((x)&(-(x)))
int tree[N];
void add(int x,int c){
	for(int i=x;i<=maxn;i+=lowbit(i))
		tree[i]=(tree[i]+c)%mod;
	return ;
}
int find(int x){
	int Sum=0;
	for(int i=x;i;i-=lowbit(i))
		Sum=(Sum+tree[i])%mod;
	return Sum;
}

int fl[N],nf[N];

int a[N],b[N],Cnt[N];

int main()
{
	
	fl[0]=1;for(int i=1;i<=maxn;i++) fl[i]=(ll)fl[i-1]*i%mod;
	nf[maxn]=ni(fl[maxn]);for(int i=maxn-1;i>=0;i--) nf[i]=(ll)nf[i+1]*(i+1)%mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);
	
	memset(Cnt,0,sizeof(Cnt));
	for(int i=1;i<=n;i++) Cnt[a[i]]++;
	
	int d=1;
	for(int i=1;i<=maxn;i++){
		d=(ll)d*nf[Cnt[i]]%mod;
		add(i,Cnt[i]);
	}
	
	int Ans=0;
	for(int i=1;i<=m;i++){
		if(find(maxn)==0){
			Ans=(Ans+1)%mod;
			break;
		}
		
		int t=find(b[i]-1);
		Ans=(Ans+(ll)fl[n-i]*t%mod*d)%mod;
		
		if(Cnt[b[i]]==0) break;
		d=(ll)d*fl[Cnt[b[i]]]%mod;
		
		Cnt[b[i]]--;
		d=(ll)d*nf[Cnt[b[i]]]%mod;
		add(b[i],mod-1);
	}
	
	printf("%d\n",Ans);
	return 0;
}