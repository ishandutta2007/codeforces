#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,m,tot,ans[N],a[N],b[N],pa[N],pb[N];
struct Data{
	int x,y,w,id;
	friend bool operator < (const Data &a,const Data &b){
		return a.x==b.x?a.id<b.id:a.x<b.x;
	}
}q[N<<3];
class BIT{
	int b[N];
	inline int lowbit(int x){return x&(-x);}
public:
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
}B;
void Solve(int L,int R){
	if(L==R)return;
	int mid=(L+R)>>1;
	Solve(L,mid),Solve(mid+1,R);
	sort(q+L,q+mid+1),sort(q+mid+1,q+R+1);
	int j=L;
	for(int i=mid+1;i<=R;++i){
		while(j<=mid&&q[j].x<=q[i].x){
			if(!q[j].id)B.Add(q[j].y,q[j].w);
			++j;
		}
		if(q[i].id)ans[q[i].id]+=B.Ask(q[i].y)*q[i].w;
	}
	for(int i=L;i<j;++i){
		if(!q[i].id)B.Add(q[i].y,-q[i].w);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];pa[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		cin>>b[i];pb[b[i]]=i;
	}
	for(int i=1;i<=n;++i){
		q[++tot]={pa[i],pb[i],1,0};	
	}
	for(int i=1,opt;i<=m;++i){
		cin>>opt;
		if(opt==1){
			int l1,r1,l2,r2;
			cin>>l1>>r1>>l2>>r2;
			q[++tot]={r1,r2,1,i};
			q[++tot]={l1-1,r2,-1,i};
			q[++tot]={r1,l2-1,-1,i};
			q[++tot]={l1-1,l2-1,1,i};
		}
		else{
			ans[i]=-1;
			int x,y;
			cin>>x>>y;
			if(x==y)continue;
			q[++tot]={pa[b[x]],pb[b[x]],-1,0};
			q[++tot]={pa[b[y]],pb[b[y]],-1,0};
			swap(pb[b[x]],pb[b[y]]);
			swap(b[x],b[y]);
			q[++tot]={pa[b[x]],pb[b[x]],1,0};
			q[++tot]={pa[b[y]],pb[b[y]],1,0};
		}
	}
	Solve(1,tot);
	for(int i=1;i<=m;++i){
		if(~ans[i]){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}