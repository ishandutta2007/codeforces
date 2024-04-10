#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
typedef long long ll;
ll f[105][2],g[105][2];
ll calc(int n,int m,ll t){
	if((2LL<<n)-1+(2LL<<m)-1<t)return 0;
	ll ans=0;
	for(int c=0;c<=n+m;++c)if((t+c)%2==0){
		memset(f,0,sizeof(f)),f[0][0]=1;ll s=(t+c)/2;
		for(int i=0;i<51;++i){
			memset(g,0,sizeof(g));int l1=i<n?2:1,l2=i<m?2:1;
			for(int j=0;j<=c;++j)for(int k=0;k<2;++k){
				for(int a=0;a<l1;++a)for(int b=0;b<l2;++b)if((a+b+k)%2==(s>>i&1)){
					g[j+a+b][a+b+k>=2]+=f[j][k];
				}
			}
			memcpy(f,g,sizeof(f));
		}
		ans+=f[c][0];
	}
	return ans;
}
int main(){
	ll s;read(s);ll ans=0;
	for(int dx=0;dx<=50;++dx){
		for(int dy=0;dy<=50;++dy){
			ll coef=(1LL<<(dx+1))+(1LL<<(dy+1))-3;
			int nn=std::max(0,dx-1),mm;ll tar=s;
			if(dy)tar-=1LL<<dy,++tar,mm=dy-1;else mm=0;
			ll r=tar/coef,l=std::max(1LL,r-5);
			for(ll z=l;z<=r;++z){
				ll t=tar-coef*z;if(t<0)continue;
				ans+=calc(nn,mm,t);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}