#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,q;
#define Maxn 300010
#define cout cerr
#define FR first
#define SE second
int a[Maxn];
bool vis[N+10];
int num[N+10];
int p[N+10];
void init(){
	num[1]=1;
	for(int i=2;i<=N;++i){
		if(!vis[i])p[++p[0]]=i,num[i]=i;
		for(int j=1;j<=p[0]&&1ll*i*p[j]<=N;++j){
			vis[i*p[j]]=true;
			if(i%p[j]==0){
				if(num[i]%p[j]==0)num[i*p[j]]=num[i]/p[j];
				else num[i*p[j]]=num[i]*p[j];
				break;
			}
			num[i*p[j]]=num[i]*p[j];
		}
	}
}

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

int main(){
	init();int T;
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),a[i]=num[a[i]];
		sort(a+1,a+n+1);int ans1=0,ans2=0;
		for(int i=1,at;i<=n;i=at+1){
			at=i;
			while(at+1<=n&&a[at+1]==a[i])at++;
			ans1=max(ans1,at-i+1);
			if((at-i+1)%2==0||a[i]==1)ans2+=at-i+1;
		}
		ans2=max(ans2,ans1);
		rd(q);
		ll w;
		while(q--){
			scanf("%lld",&w);
			if(w>0)printf("%d\n",ans2);
			else printf("%d\n",ans1);
		}
	}
	return 0;
}