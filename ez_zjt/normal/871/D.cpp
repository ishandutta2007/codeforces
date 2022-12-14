#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 10000010
#define LL long long
using namespace std;

LL n;
LL phi[MAXN],miu[MAXN],mind[MAXN],mind2[MAXN];
LL cnt[MAXN],scnt[MAXN];
int prime[MAXN],nump;
bool flag[MAXN];

void init(){
	prime[0]=1;
	miu[1]=1;
	mind[1]=mind2[1]=1;
	for(int i=2;i<=n;i++){
		if(!flag[i]){
			prime[++nump]=i;
			phi[i]=i-1;
			miu[i]=-1;
			mind[i]=mind2[i]=i;
		}
		for(int j=1;j<=nump && i*prime[j]<=n;j++){
			flag[i*prime[j]]=1;
			mind[i*prime[j]]=prime[j];
			if(i%prime[j]){
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
				miu[i*prime[j]]=-miu[i];
				mind2[i*prime[j]]=prime[j];
			}else{
				phi[i*prime[j]]=phi[i]*prime[j];
				miu[i*prime[j]]=0;
				mind2[i*prime[j]]=mind2[i]*prime[j];
				break;
			}
		}
	}
}

pair<LL,LL> calc0(int x){
	LL m=n/x;
	LL y=mind[x];
	if(y==1) y=n;
	for(int i=1;i<=m;i++) cnt[i]=0;
	for(int i=2;i<=m;i++) cnt[min(y,mind[i])]++;
	for(int i=1;i<=m;i++) scnt[i]=scnt[i-1]+cnt[i];
	LL res=0,temp=0,now=0,res2=0;
	int lim=min(m,n/2);
	for(int i=m;i>=1;i--){
		while(now<m && (now+1)*i<=n) now++;
		res+=scnt[now]*cnt[i];
		if(i*2<=n && now<lim) res2+=(scnt[lim]-scnt[now])*cnt[i];
	}
	res+=scnt[min(m,n/mind[x])]*2;
	if(mind[x]*mind[x]<=n) res++;
	if(mind[x]*2<=n){
		if(min(m,n/mind[x])<lim)
			res2+=(scnt[lim]-scnt[min(m,n/mind[x])])*2;
		if(mind[x]*mind[x]>n) res2++;
	}
	return make_pair(res,res2);
}

LL calc(){
	LL res=0,res2=0;
	for(int i=1;i<=n;i++){
		pair<LL,LL> temp=calc0(i);
		res+=miu[i]*temp.first;
		res2+=miu[i]*temp.second;
	}
	res=(res-1)/2;
	res-=n-1;
	res2/=2;
	res=res*2+res2*3;
	for(int i=2;i<=n;i++)
		res+=i-phi[i]-1;
	return res;
}

int main(){
#ifdef DEBUG
	freopen("D.in","r",stdin);
#endif
	scanf("%d",&n);
	init();
	LL ans=calc();
	printf("%lld\n",ans);
	return 0;
}