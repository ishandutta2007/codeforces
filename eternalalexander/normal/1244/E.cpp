#include <bits/stdc++.h>
#define ll long long
#define maxn 100005
const ll inf=(ll)1<<(ll)60;
ll answ=inf,n,k,a[maxn],pre[maxn]={0},suf[maxn]={0};
int main(){
	std::cin>>n>>k;
	for(int i=1;i<=n;++i)std::cin>>a[i];
	std::sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+a[i];
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
	for(int i=1;i<=n;++i){
		ll rem=k-(a[i]*i-pre[i]);
		if (rem<0)break;
		int l=i,r=n,ans;
		while (l<=r){
			int mid=(l+r)>>1;
			if (suf[mid]-a[mid]*(n-mid+1)<=rem){ans=mid;r=mid-1;}
			else l=mid+1;
		}ll opt=rem-(suf[ans]-a[ans]*(n-ans+1));
		answ=std::min(answ,std::max((ll)0,a[ans]-opt/(n-ans+1)-a[i]));
	}
	for(int i=n;i>=1;--i){
		ll rem=k-(suf[i]-a[i]*(n-i+1));
		if (rem<0)break;
		int l=1,r=i,ans;
		while (l<=r){
			int mid=(l+r)>>1;
		//	printf("checking:(%d-%d)%d -> %lld - %lld\n",l,r,mid,a[mid]*mid,pre[mid]);
			if (a[mid]*mid-pre[mid]<=rem){ans=mid;l=mid+1;}
			else r=mid-1;
		}//printf(">%d\n",ans);
		ll opt=rem-(a[ans]*ans-pre[ans]);
		answ=std::min(answ,std::max((ll)0,a[i]-(opt/(ans)+a[ans])));
	}
	std::cout<<answ;
	return 0;
}