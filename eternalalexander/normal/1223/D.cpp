#include <bits/stdc++.h>
#define maxn 300005
int n,a[maxn],last[maxn],first[maxn],h[maxn];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){first[i]=last[i]=h[i]=0;}
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		last[a[i]]=i;
		if(!first[a[i]])first[a[i]]=i;
		h[i]=a[i];
	}std::sort(h+1,h+n+1);
	int tl=std::unique(h+1,h+n+1)-(h+1);
	int p=1,ans=0;
	for(int i=1;i<=tl;++i){
		if(p<i)p=i;
		while(p<tl&&first[h[p+1]]>last[h[p]])p++;
		ans=std::max(ans,p-i);
	}printf("%d\n",tl-ans-1);
}
		

int main(){
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}