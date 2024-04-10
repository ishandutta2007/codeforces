#include<bits/stdc++.h>
using namespace std;
#define N 300010
typedef pair<int,int> pii;
const int mod=1e9+7;
const int inv2=(mod+1)/2;
typedef long long ll;
int n,a[N],b[N<<1],rk[N<<1],len,Q,pw2[N],ipw2[N];
pii c[N];
int calc(){
	for(int i=1;i<=n;++i){
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			ans=(ans+1LL*ipw2[j-i]*b[i]%mod*b[j])%mod;	
		}
	}
	ans=1LL*ans*inv2%mod;
	return ans;
}
class Segment_Tree{
	struct node{
		int sum,A,B,cnt;
	}t[N<<3];
	#define ls u<<1
	#define rs u<<1|1
	inline void update(int u){
		t[u].cnt=t[ls].cnt+t[rs].cnt;
		t[u].A=(t[ls].A+1LL*t[rs].A*pw2[t[ls].cnt])%mod;
		t[u].B=(t[ls].B+1LL*t[rs].B*ipw2[t[ls].cnt])%mod;
		t[u].sum=(t[ls].sum+t[rs].sum+1LL*t[ls].A*t[rs].B%mod*ipw2[t[ls].cnt])%mod;
	}
public:
	void Insert(int u,int L,int R,int p,int d){
		if(L==R){
			t[u].A+=2LL*b[p]%mod*d;
			t[u].B+=1LL*inv2*b[p]%mod*d;
			t[u].cnt+=d;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?Insert(ls,L,mid,p,d):Insert(rs,mid+1,R,p,d);
		update(u);
	}
	int get_ans(){
		return 1LL*t[1].sum*inv2%mod;	
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		b[++len]=a[i];
		rk[len]=i;
	}
	pw2[0]=ipw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
		ipw2[i]=1LL*inv2*ipw2[i-1]%mod;
	}
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>c[i].first>>c[i].second;
		b[++len]=c[i].second;
		rk[len]=n+i;	
	}
	sort(rk+1,rk+len+1,[&](int i,int j){return b[i]<b[j];});
	sort(b+1,b+len+1);
	for(int i=1;i<=len;++i){
		(rk[i]<=n?a[rk[i]]:c[rk[i]-n].second)=i;
	}
	for(int i=1;i<=n;++i){
		T.Insert(1,1,len,a[i],1);	
	}
	cout<<T.get_ans()<<'\n';
	for(int i=1;i<=Q;++i){
		int u=c[i].first;
		T.Insert(1,1,len,a[u],-1);
		a[u]=c[i].second;
		T.Insert(1,1,len,a[u],1);
		cout<<T.get_ans()<<'\n';
	}
	return 0;
}