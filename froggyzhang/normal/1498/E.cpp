#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,p[N],a[N],ans;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	int sum=0;
	ans=-1;
	int oi=0,oj=0;
	for(int i=1,las=0;i<=n;++i){
		sum+=a[p[i]];
		if(sum==i*(i-1)/2){
			if(las+1<i){
				int w=a[p[i]]-a[p[las+1]];
				if(w>ans){
					ans=w;
					oi=p[i],oj=p[las+1];
				}
			}
			las=i;
		}
	}
	printf("! %d %d\n",oi,oj);
	fflush(stdout);
	return 0;
}