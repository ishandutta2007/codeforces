#include<bits/stdc++.h>
using namespace std;
int n,m,st[100005],top,ans=2e9+100,MOD;
struct Thing{
	int a[6],w;
	int &operator [](int k){return a[k];}
}a[100005];
int T[15],b[500005];
namespace Hash{
	__int128 val[7000005];
	int tot,nxt[7000005],h[7000005],s[7000005];
	void Add(__int128 x,int w){
		int p=x%MOD;
		for(int i=h[p];i;i=nxt[i])if(val[i]==x)return s[i]+=w,void();
		nxt[++tot]=h[p],h[p]=tot,s[tot]=w,val[tot]=x;
	}
	int Getv(__int128 x){
		int p=x%MOD;
		for(int i=h[p];i;i=nxt[i])if(val[i]==x)return s[i];
		return 0;
	}
}
using namespace Hash;
bool Unique(int x,int y){
	T[0]=0;
	for(int i=0;i<m;i++)T[++T[0]]=a[x][i],T[++T[0]]=a[y][i];
	sort(T+1,T+T[0]+1);
	for(int i=2;i<=T[0];i++)if(T[i]==T[i-1])return 0;
	return 1;
}
void Ins(int x,int dlt){
	for(int i=0;i<(1<<m);i++){
		__int128 o=0;
		for(int j=0;j<m;j++)if(i&(1<<j))o=(o*1000000+a[x][j]);
		Add(o,dlt);
	}
}
int Get(int x){
	int ans=0;
	for(int i=0;i<(1<<m);i++){
		__int128 o=0;
		for(int j=0;j<m;j++)if(i&(1<<j))o=(o*1000000+a[x][j]);
		if(__builtin_popcount(i)&1)ans-=Getv(o);
		else ans+=Getv(o);
	}
	return ans;
}
int main(){
	cin>>n>>m;
	//n=100000,m=5;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}//a[i].w=1;
		scanf("%d",&a[i].w);
		sort(a[i].a,a[i].a+m);
	}
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)b[++b[0]]=a[i][j];
	sort(b+1,b+b[0]+1),b[0]=unique(b+1,b+b[0]+1)-b-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=lower_bound(b+1,b+b[0]+1,a[i][j])-b;
		}
	}
	sort(a+1,a+n+1,[](Thing x,Thing y){return x.w<y.w;});
	
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()+time(0)+clock());
	while(1){
		MOD=rng()%1000000+6000000;
		bool fl=0;
		for(int i=2;i*i<=MOD;i++){
			if(MOD%i==0)fl=1;
		}
		if(!fl)break;
	}
	for(int i=1;i<=n;i++){
		while(Get(i)){
			int x=st[top];
			if(Unique(x,i)){
				ans=min(ans,a[i].w+a[x].w);
			}
			Ins(x,-1);
			top--;
		}
		st[++top]=i;
		Ins(i,1);
	}
	if(ans>2e9)puts("-1");
	else cout<<ans;
}