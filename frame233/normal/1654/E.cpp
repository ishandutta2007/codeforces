#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=100005,B=350,BB=N/B+3;
int a[N],b[N],cnt[N+N],all[BB+5],pos;
int main(){
	int n;read(n);for(int i=1;i<=n;++i)read(a[i]);
	int ans=1;
	for(int d=-B;d<=B;++d){
		for(int i=1;i<=n;++i)b[i]=a[i]-d*i;
		std::sort(b+1,b+n+1);
		for(int i=1;i<=n;++i){
			int j=i;while(j<n&&b[j+1]==b[i])++j;
			ans=std::max(ans,j-i+1),i=j;
		}
	}
	for(int i=0;i<N+N;++i)cnt[i]=1;
	for(int i=1;i<=n;++i){
		pos=0;
		for(int j=i+1;j<=i+BB&&j<=n;++j){
			int tmp=(a[j]-a[i])/(j-i);
			if(tmp*(j-i)==(a[j]-a[i]))chmax(ans,++cnt[tmp+N]),all[++pos]=tmp;
		}
		for(int i=1;i<=pos;++i)cnt[all[i]+N]=1;
	}
	printf("%d\n",n-ans);
	return 0;
}