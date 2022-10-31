// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
template <typename _Tp>inline void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s){
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar++=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *tar++=ch,ch=getchar();
	return *tar=0,tar-s;
}

const int N=25005;
int L[N],R[N],a[N],rev[N];
int p1[N],p2[N],s1[N],s2[N];
int main(){
	int n,q;read(n,q);
	for(int i=1;i<=n;++i)read(a[i]),rev[a[i]]=i;
	int l,r,ans=0;
	for(int i=1;i<=n;++i)L[i]=R[i]=i;
	a[0]=inf,s2[0]=p2[0]=inf;
	while(q--){
		read(l,r);
		for(int i=r;i>=l&&L[i]>l;--i){
			ans-=s2[p1[i]]<=a[i];
			while(L[i]>l){
				int o=--L[i];
				if(a[o]>a[i])p1[i]=a[o]<a[p1[i]]?o:p1[i];
				else{
					if(a[o]>p2[i]){
						for(int j=p2[i];j<a[o];++j)ans-=s1[rev[j]]==i;
						p2[i]=a[o];
					}
				}
			}
			ans+=s2[p1[i]]<=a[i];
		}
		for(int i=l;i<=r&&R[i]<r;++i){
			ans-=p2[s1[i]]<=a[i];
			while(R[i]<r){
				int o=++R[i];
				if(a[o]>a[i])s1[i]=a[o]<a[s1[i]]?o:s1[i];
				else{
					if(a[o]>s2[i]){
						for(int j=s2[i];j<a[o];++j)ans-=p1[rev[j]]==i;
						s2[i]=a[o];
					}
				}
			}
			ans+=p2[s1[i]]<=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}