#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define md 1000000007
#define C(x,y) (tr[x]*rr[y]%md*rr[(x)-(y)]%md)
using namespace std;
int n,k;char c[100001],tmp;long long t,ans,r[100001],tr[100001],rr[100001];
long long rv(int x){
	if(x==1)return 1;
	long long w=md/x+1;
	return rv(w*x-md)*w%md;
}
int main(){
	scanf("%d%d",&n,&k);scanf("%s",c);
	rep(i,0,(n-1)/2)tmp=c[i],c[i]=c[n-i-1],c[n-i-1]=tmp;
	tr[0]=1;rep(i,1,n)tr[i]=tr[i-1]*i%md;rr[n]=rv(tr[n]);
	rep(i,1,n)rr[n-i]=rr[n-i+1]*(n-i+1)%md;
	t=1;rep(i,1,n-k)r[i]=(r[i-1]+C(n-i-1,k-1)*t)%md,t=t*10%md;
	rep(i,n-k+1,n)r[i]=r[i-1];t=1;
	rep(i,0,n-1){
		ans=(ans+(c[i]-'0')*r[i])%md;
		if(i<n-k)ans=(ans+(c[i]-'0')*C(n-i-1,k)*t)%md;
		t=t*10%md;
	}
	printf("%I64d\n",ans);
}