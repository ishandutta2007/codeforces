#include <cstdio>
#include <cstring>
#include <map>
#define LL long long
#define MAXN 1000010
using namespace std;

const LL P=1000000007;
map<pair<int,int>,int> S;

LL getPow(LL x,LL y){
	LL res=1;
	while(y){
		if(y&1) res=res*x%P;
		x=x*x%P;
		y>>=1;
	}
	return res;
}

int n,m;
int f[MAXN];
bool tag[MAXN];
int size[MAXN];

int getf(int x){
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}

int main(){
#ifdef DEBUG
	freopen("C.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<MAXN;i++) f[i]=i;
	for(int i=1;i<=n;i++){
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		if(!S.count(make_pair(1,t1))) S[make_pair(1,t1)]=++m;
		if(!S.count(make_pair(2,t2))) S[make_pair(2,t2)]=++m;
		int x1=S[make_pair(1,t1)],x2=S[make_pair(2,t2)];
		if(getf(x1)!=getf(x2)) f[f[x1]]=f[x2];
		else tag[x1]=1;
	}
	for(int i=1;i<=m;i++){
		size[getf(i)]++;
		tag[getf(i)]|=tag[i];
	}
	LL ans=1;
	for(int i=1;i<=m;i++)
		if(getf(i)==i){
			if(!tag[i]) ans=ans*(getPow(2,size[i])-1)%P;
			else ans=ans*getPow(2,size[i])%P;
		}
	printf("%lld\n",ans);
}