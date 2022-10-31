#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
#define FAIL puts("NO"),exit(0)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
const int N=200005,MAXN=2000005,inf=0x3f3f3f3f;typedef long long ll;
const char opt[]={'L','D','U','R'};
ll t[N],x[N],y[N],k[N];int p[N],n,L,id[MAXN],s[MAXN];
inline ll down(ll x,ll y){if(y<0)x*=-1,y*=-1;return x>=0?x/y:(x-y+1)/y;}
inline ll up(ll x,ll y){if(y<0)x*=-1,y*=-1;return x<=0?x/y:(x+y-1)/y;}
std::vector<int> solve(){
	memset(id,0,sizeof(id));ll c=inf;
	for(int i=1;i<=n;++i){
		if(t[i]%2==x[i]%2)FAIL;
		if(id[p[i]]){
			int j=id[p[i]];if((x[j]-x[i])%(k[j]-k[i]))FAIL;
			ll tmp=(x[j]-x[i])/(k[j]-k[i]);if(c!=inf&&c!=tmp)FAIL;
			c=tmp;
		}
		id[p[i]]=i;
	}
	ll l=-L,r=L;if(c!=inf)l=c,r=c;
	for(int i=1;i<=n;++i){int D=L-1-p[i];l=std::max(l,up(x[i]-D,k[i]+1)),r=std::min(r,down(x[i]+D,k[i]+1));}
	for(int i=0,last=-1;i<L;++i){
		if(id[i]){
			int a=id[i],b=last==-1?0:id[last],D=i-last;
			if(k[a]==k[b]){if(abs(x[a]-x[b])>D)FAIL;}
			else{
				if(k[a]>k[b])l=std::max(l,up(x[a]-x[b]-D,k[a]-k[b])),r=std::min(r,down(x[a]-x[b]+D,k[a]-k[b]));
				else l=std::max(l,up(x[a]-x[b]+D,k[a]-k[b])),r=std::min(r,down(x[a]-x[b]-D,k[a]-k[b]));
			}
			last=i;
		}
	}
	c=(l%2+2)%2==L%2?l:l+1;if(c>r)FAIL;
	memset(s,63,sizeof(s)),s[L-1]=c;
	for(int i=1;i<=n;++i){ll tmp=x[i]-c*k[i];s[p[i]]=tmp;}
	std::vector<int> ans;
	for(int i=0,last=-1;i<L;++i)if(s[i]!=inf){
		ll a=last==-1?0:s[last],b=s[i];
		if(a>=b){
			for(int j=last+1;j<=last+a-b;++j)s[j]=a-(j-last),ans.pb(0);
			for(int j=last+a-b+1;j<=i;++j){
				int v=(j==0?0:s[j-1]);
				if(v==b)s[j]=v+1,ans.pb(1);
				else s[j]=v-1,ans.pb(0);
			}
		}
		else{
			for(int j=last+1;j<=last+b-a;++j)s[j]=a+(j-last),ans.pb(1);
			for(int j=last+b-a+1;j<=i;++j){
				int v=(j==0?0:s[j-1]);
				if(v==b)s[j]=v+1,ans.pb(1);
				else s[j]=v-1,ans.pb(0);
			}
		}
		last=i;
	}
	assert(SZ(ans)==L);
	return ans;
}
int main(){
	read(n,L);ll X,Y;
	for(int i=1;i<=n;++i)read(t[i],X,Y),--t[i],k[i]=t[i]/L,p[i]=t[i]%L,x[i]=X+Y,y[i]=X-Y;
	std::vector<int> A=solve();for(int i=1;i<=n;++i)std::swap(x[i],y[i]);
	std::vector<int> B=solve();
	for(int i=0;i<L;++i)putchar(opt[A[i]<<1|B[i]]);
	putchar('\n');
	return 0;
}