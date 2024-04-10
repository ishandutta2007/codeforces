#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005;typedef long long ll;
int A[N],B[N];std::vector<int> v1[N],v2[N];bool mark[N],x[N],y[N];
void exgcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x),y-=a/b*x;
}
ll solve(int n,int m,std::vector<int> a,std::vector<int> b){
	if(a.empty()&&b.empty())puts("-1"),exit(0);
	std::sort(a.begin(),a.end()),a.erase(std::unique(a.begin(),a.end()),a.end());
	std::sort(b.begin(),b.end()),b.erase(std::unique(b.begin(),b.end()),b.end());
	if(SZ(a)==n&&SZ(b)==m)return -1;
	if(SZ(a)+SZ(b)>=n){
		memset(x,0,n),memset(y,0,m);
		for(int i=0;i<SZ(a);++i)x[a[i]]=1;
		for(int i=0;i<SZ(b);++i)y[b[i]]=1;
		int rx=0,ry=0;for(int i=0;i<n;++i)rx+=!x[i];
		for(int i=0;i<m;++i)ry+=!y[i];
		for(int i=0;i<m;++i){
			rx-=x[i]==0,ry-=y[i]==0;
			x[i]=y[i]=x[i]||y[i];
			rx+=x[i]==0,ry+=y[i]==0;
			if(!rx&&!ry)return i;
		}
	}
	for(auto it:b)a.pb(it);
	std::sort(a.begin(),a.end()),a.erase(std::unique(a.begin(),a.end()),a.end());
	int x,y;exgcd(m,n,x,y);x=(x%n+n)%n;
	for(auto &&it:a)it=1LL*it*x%n;
	std::sort(a.begin(),a.end());ll ans=0;a.pb(a[0]+n);
	for(int i=0;i+1<SZ(a);++i)ans=std::max(ans,1LL*(a[i+1]-a[i]-1)*m+1LL*a[i]*m%n);
	return ans;
}
int main(){
	int n,m;read(n,m);int g=std::__gcd(n,m),k1,k2;
	read(k1);for(int i=0;i<k1;++i)read(A[i]);
	read(k2);for(int i=0;i<k2;++i)read(B[i]);
	if(n<m)std::swap(n,m),std::swap(k1,k2),std::swap(A,B);
	if(g>k1+k2)return puts("-1"),0;
	for(int i=0;i<k1;++i)v1[A[i]%g].pb(A[i]/g);
	for(int i=0;i<k2;++i)v2[B[i]%g].pb(B[i]/g);
	ll ans=0;for(int i=0;i<g;++i)ans=std::max(ans,solve(n/g,m/g,v1[i],v2[i])*g+i);
	printf("%lld\n",ans);
	return 0;
}