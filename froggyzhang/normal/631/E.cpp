#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const ll inf=1e12;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N];
ll ans,sum,s[N];
struct Line{
	ll k,b;
	Line(ll _k=-inf,ll _b=-inf){k=_k,b=_b;}	
	inline ll val(int x){return k*x+b;}
};
class LiChao_Tree{
private:
	int cnt;
public:
	int rt;
	struct node{
		Line p;
		int ch[2];
	}t[N<<1];
	#define ls t[u].ch[0]
	#define rs t[u].ch[1]
	void Insert(int &u,int L,int R,Line z){
		if(!u){
			u=++cnt;
			t[u].p=z;
			return;
		}
		if(L==R){
			if(z.val(L)>t[u].p.val(L))t[u].p=z;
			return;
		}
		int mid=(L+R)>>1;
		if(t[u].p.k>z.k){
			if(t[u].p.val(mid)<z.val(mid)){
				Insert(rs,mid+1,R,t[u].p);
				t[u].p=z;
			}
			else{
				Insert(ls,L,mid,z);
			}	
		}
		else{
			if(t[u].p.val(mid)<z.val(mid)){
				Insert(ls,L,mid,t[u].p);
				t[u].p=z;
			}
			else{
				Insert(rs,mid+1,R,z);
			}	
		}
	}
	ll Query(int u,int L,int R,int x){
		if(!u||L==R)return t[u].p.val(x);
		int mid=(L+R)>>1;
		ll mx=t[u].p.val(x);
		mx=max(mx,x<=mid?Query(ls,L,mid,x):Query(rs,mid+1,R,x));
		return mx;	
	}
};
void Solve(){
	LiChao_Tree T;
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}	
	for(int i=1;i<=n;++i){
		ans=max(ans,T.Query(T.rt,1,n,i)-s[i]);
		T.Insert(T.rt,1,n,Line(a[i],-1LL*a[i]*i+s[i]));
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		sum+=1LL*i*a[i];
	}
	Solve();
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;++i)a[i]=-a[i];
	Solve();
	printf("%lld\n",ans+sum);
	return 0;
}