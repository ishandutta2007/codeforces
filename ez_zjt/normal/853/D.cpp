#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 300010
using namespace std;

int n;
int a[MAXN],s[MAXN];
int f1[MAXN];
int next1[MAXN],next2[MAXN];
int ans=0;

int getS(int l,int r){ return s[r]-s[l-1]; }

void pre_gao(){
	int last1=n+1,last2=n+1;
	for(int i=n;i>=1;i--){
		next1[i]=last1;
		next2[i]=last2;
		if(a[i]==1) last1=i;
		else last2=i;
	}
}

void update(int x){
	if(x>ans) ans=x;
}

void gao(int x){
	if(getS(x+1,n)*10>=getS(1,x)) update(s[x]);
	if(next1[x]<=n){
		int s1=s[x],s2=getS(x+1,next1[x]-1);
		int s3=max(s1-10*s2,0);
		int l=next1[x],r=next2[next1[x]]-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(getS(mid+1,n)*10>=s3+getS(next1[x],mid)) l=mid;
			else r=mid-1;
		}
		if(getS(l+1,n)*10>=s3+getS(next1[x],l))
			update(s1+getS(next1[x],l));
	}
	if(next2[x]<=n){
		int s1=s[x],s2=getS(x+1,next2[x]-1);
		int s3=max(s1-10*s2,0);
		int l=next2[x],r=next1[next2[x]]-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(getS(mid+1,n)*10>=s3+getS(next2[x],mid)) l=mid;
			else r=mid-1;
		}
		if(getS(l+1,n)*10>=s3+getS(next2[x],l))
			update(s1+getS(next2[x],l));
	}
}

int main(){
#ifdef DEBUG
	freopen("D.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]/=1000;
		s[i]=s[i-1]+a[i];
	}
	pre_gao();
	for(int i=1;i<=n;i++)
		gao(i);
	ans=s[n]*10-ans;
	printf("%d00\n",ans);
	return 0;
}