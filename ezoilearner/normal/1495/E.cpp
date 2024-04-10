#include<bits/stdc++.h>
using namespace std;
const int Mod=1000000007;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n,m;
#define Maxn 5000010
int a[Maxn],t[Maxn];
int to[Maxn],c[Maxn],cnt;
ll b[Maxn],sum[3];
int p[200010],g[200010],w[200010],k[200010];

int seed=0;
int base=0;
int rnd(){
	int ret=seed;
	seed=(1ll*seed*base+233)%1000000007;
	return ret;
}
int type;
void generate(){
	p[0]=0;
	rep(i,1,m){
		seed=g[i];
		base=w[i];
		rep(j,p[i-1]+1,p[i]){
			t[j]=rnd()%2+1;
			a[j]=rnd()%k[i]+1;
			c[j]=a[j];
			sum[t[j]]+=a[j];
		}
	}
	if(sum[t[1]]>sum[3-t[1]]){
		type=3-t[1];
		a[1]--;
	}else type=t[1];
}

void solve(){
	rep(i,1,n)
		if(t[i]==3-type){
			cnt++;to[cnt]=i;
		}
	int lst=1;
	per(i,n,1)
		if(t[i]==type){
			b[lst]+=a[i];
		}else{
			lst--;if(!lst)lst=cnt;
		}
	rep(i,1,cnt){
		b[i]+=b[i-1];
		int cur=min(b[i],(ll)a[to[i]]);
		a[to[i]]-=cur;b[i]-=cur;
		b[i-1]=0;
	}
	rep(i,1,cnt){
		if(i==1)b[i]+=b[cnt];else b[i]+=b[i-1];
		int cur=min(b[i],(ll)a[to[i]]);
		a[to[i]]-=cur;b[i]-=cur;
	}
}

int main(){
	rd(n);rd(m);
	rep(i,1,m){
		rd(p[i]);rd(k[i]);rd(g[i]);rd(w[i]);
	}
	generate();
	solve();
	int res=1;
	rep(i,1,n){
		int ans;
		if(t[i]==type)a[i]=0;
		ll p=(1ll*i*i)^(c[i]-a[i]);
		res=1ll*(p+1)%Mod*res%Mod;
	}
	printf("%d\n",res);
	return 0;
}