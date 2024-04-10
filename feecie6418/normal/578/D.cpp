#include<cstdio>
using namespace std;
typedef long long ll;
char *a;
int n,m,*rt;
ll ans=0;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	int trt[100005];
	char aa[100005];
	rt=trt,a=aa;
	scanf("%d%d%s",&n,&m,a+1);
	for(int i=1,cnt=1;i<=n;i++){
		if(i>1&&a[i]!=a[i-1])cnt++;
		ans+=(m-1)*cnt;
	}
	for(int i=n,cnt=1;i>0;i--){
		if(i<n&&a[i]!=a[i+1])cnt++;
		ans+=(m-1)*cnt;
	}
	ans-=(m-1)*n;
	for(int i=1;i<=n;i++)rt[i]=i;
	for(int i=n-2;i>=1;i--)if(a[i]==a[i+2])rt[i]=rt[i+2];
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1])continue;
		ans-=min(rt[i],rt[i+1])+1-i;
	}
	printf("%lld\n",ans);
}