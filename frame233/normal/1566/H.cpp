#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
std::mt19937 Rnd(std::chrono::steady_clock::now().time_since_epoch().count());
inline unsigned rnd(){return Rnd()+Rnd();}
const int N=1000005,M=650005;
bool pr[N];int p[N],pos,mu[N],to[N];
void sieve(){
	mu[1]=1,to[1]=1;
	for(int i=2;i<N;++i){
		if(!pr[i])p[++pos]=i,mu[i]=-1,to[i]=i;
		for(int j=1;j<=pos&&i*p[j]<N;++j){
			pr[i*p[j]]=1;
			if(i%p[j]==0){to[i*p[j]]=to[i],mu[i*p[j]]=0;break;}
			mu[i*p[j]]=-mu[i],to[i*p[j]]=to[i]*p[j];
		}
	}
}
int f[N];
std::vector<int> v[M];
struct DS{
	int d[20],s[20];
	std::vector<int> b,z;
	bool ins(int x){
		int st=0,o=x;
		for(int i=19;i>=0;--i)if(x>>i&1){
			if(d[i])x^=d[i],st^=s[i];
			else return d[i]=x,s[i]=st|1<<SZ(b),b.pb(o),true;
		}
		return z.pb(o),false;
	}
	int get(int x){
		int st=0;for(int i=19;i>=0;--i)if(x>>i&1)x^=d[i],st^=s[i];
		return __builtin_popcount(st);
	}
}a[M];
int siz[M],ID[N];
bool is[N],tp[260];
int main(){
	sieve();
	int c,n;read(c,n);
	int cnt=0;for(int i=1;i<=c;++i)if(mu[i])++cnt;
	printf("%d ",cnt);for(int i=1;i<=c;++i)if(mu[i])printf("%d ",i);
	printf("\n"),fflush(stdout);
	for(int i=1;i<=c;++i)if(mu[i])read(f[i]);
	for(int i=c;i>1;--i)if(mu[i])f[i]^=f[1];
	for(int i=c;i>1;--i)if(mu[i])for(int j=i+i;j<=c;j+=i)if(mu[j])f[j]^=f[i];
	for(int i=c;i>=1;--i)if(mu[i])for(int j=i+i;j<=c;j+=i)if(mu[j])f[i]^=f[j];
	for(int i=1,id=0;i<=c;++i)if(mu[i])ID[i]=id++;
	for(int i=1;i<=c;++i)v[ID[to[i]]].pb(i);
	int s=0;std::vector<int> all;
	for(int i=1,id=0;i<=c;++i)if(mu[i]){
		all.pb(i);for(auto it:v[id])a[id].ins(it);
		s+=siz[id]=a[id].get(f[i]),++id;
	}
	while(s!=n){
		int p=rnd()%SZ(all),x=all[p],val=f[x],c=0;
		for(int i=0;i<SZ(a[p].z);++i)if((tp[i]=rnd()%2))val^=a[p].z[i],++c;
		int tmp=a[p].get(val)+c,to=s-siz[p]+tmp;
		if(abs(to-n)<abs(s-n)||(abs(to-n)==abs(s-n)&&rnd()%2)){
			siz[p]=tmp,s=to;for(int i=0;i<SZ(a[p].z);++i)is[a[p].z[i]]=tp[i];
		}
	}
	for(int i=1,id=0;i<=c;++i)if(mu[i]){
		int x=f[i];for(auto it:v[id])if(is[it])x^=it;
		int st=0;for(int j=19;j>=0;--j)if(x>>j&1)x^=a[id].d[j],st^=a[id].s[j];
		for(int j=0;j<SZ(a[id].b);++j)if(st>>j&1)is[a[id].b[j]]=true;
		++id;
	}
	for(int i=1;i<=c;++i)if(is[i])printf("%d ",i);
	printf("\n");
	return 0;
}