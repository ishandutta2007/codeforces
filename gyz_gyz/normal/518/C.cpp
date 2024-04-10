#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 100001
using namespace std;
int a[mx],b[mx],n,m,k,x;long long ans;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n){scanf("%d",&a[i]);b[a[i]]=i;}
	rep(i,1,m){
		scanf("%d",&x);
		ans+=(b[x]-1)/k+1;
		if(b[x]>1){
			b[x]--;b[a[b[x]]]++;
			a[b[x]+1]=a[b[x]];a[b[x]]=x;
		}
	}
	printf("%I64d",ans);
}