#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=200005;typedef long long ll;
ll a[N],b[N],c[N],d[N];bool ans[N];int t[N];
inline ll f(int x){return 1LL*x*(x+1)/2;}
void MAIN(){
	std::map<ll,std::vector<int>> mp;
	int n;read(n);for(int i=0;i<n;++i)read(a[i]);
	int m;read(m);for(int i=0;i<m;++i)read(b[i]);
	for(int i=0;i<n;++i)c[i]=a[i]+(i-1>=0?2*a[i-1]:0)+(i-2>=0?a[i-2]:0),mp[c[i]].pb(i);
	for(int i=0;i<m;++i)d[i]=b[i]+(i-1>=0?2*b[i-1]:0)+(i-2>=0?b[i-2]:0);
	std::iota(t+2,t+m,2),std::sort(t+2,t+m,[&](int x,int y){return d[x]<d[y];});
	std::bitset<N> all;for(int i=0;i+m-1<n;++i)all.set(i);
	for(int i=2;i<m;++i){
		int j=i;while(j+1<m&&d[t[j+1]]==d[t[i]])++j;
		std::bitset<N> A;
		for(auto it:mp[d[t[i]]])A.set(it);
		for(auto it:mp[d[t[i]]-1])A.set(it);
		for(int k=i;k<=j;++k)all&=A>>t[k];
		i=j;
	}
	for(int i=0;i+m-1<n;++i)if(all.test(i)){
		for(int s=0;s<2;++s){
			ll x=d[0]-a[i],y=d[1]-(a[i+1]+a[i]*2)-s,k=x-y,sum=y;int c0=i/2+1,c1=i+1-c0;
			if(k<-c1||k>c0)continue;
			ll cur=2*f(i/2);int tmp=c0-k;
			ll L=f(tmp-1),R=f(i)-f(i-tmp);
			if(cur-R<=sum&&sum<=cur-L){
				memset(ans,0,n+3);
				ans[i+1]=s;for(int j=2;j<m;++j)ans[i+j]=c[i+j]+1==d[j];
				for(int j=0;j<=i;++j)if((i-j)%2==0)ans[j]=1;
				ll need=cur-sum;
				for(int j=i;j>=0&&tmp;--j){
					ll o=need-j,LL=f(tmp-2),RR=f(j-1)-f(j-tmp);
					if(LL<=o&&o<=RR)ans[i-j]^=1,--tmp,need-=j;
				}
				int cnt=0;for(int i=0;i<n;++i)if(ans[i])++cnt;
				printf("%d\n",cnt);
				for(int i=0;i<n;++i)if(ans[i])printf("%d ",i+1);
				printf("\n");return;
			}
		}
	}
	puts("-1");
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}