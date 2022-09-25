#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,Q,m;
char s[N];
struct Data{
	int cnt[10][10];
	int fir,las,len;
	Data(){memset(cnt,0,sizeof(cnt));fir=las=-1,len=0;}
	friend Data operator + (const Data &a,const Data &b){
		Data c;
		for(int i=0;i<m;++i){
			for(int j=0;j<m;++j){
				c.cnt[i][j]=a.cnt[i][j]+b.cnt[i][j];		
			}
		}
		++c.cnt[a.las][b.fir];
		c.fir=a.fir,c.las=b.las;
		c.len=a.len+b.len;
		return c;
	}
};
class Segment_Tree{
	struct node{
		Data p;
		int cov;
		node(){cov=-1;}
		void Cover(int d){
			cov=d;
			p.las=p.fir=d;
			memset(p.cnt,0,sizeof(p.cnt));
			p.cnt[d][d]=p.len-1;
		}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
public:
	inline void pushdown(int u){
		if(~t[u].cov){
			t[ls].Cover(t[u].cov);
			t[rs].Cover(t[u].cov);
			t[u].cov=-1;
		}
	}
	void build(int u,int L,int R){
		t[u].cov=-1;
		if(L==R){
			t[u].p.fir=t[u].p.las=s[L]-'a';
			t[u].p.len=1;
			return;
		}
		int mid=(L+R)>>1;
		build(ls,L,mid);
		build(rs,mid+1,R);
		t[u].p=t[ls].p+t[rs].p;
	}
	void Cover(int u,int L,int R,int l,int r,int d){
		if(L>=l&&R<=r){
			t[u].Cover(d);
			return;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid)Cover(ls,L,mid,l,r,d);
		if(r>mid)Cover(rs,mid+1,R,l,r,d);
		t[u].p=t[ls].p+t[rs].p;
	}
	Data Query(int u,int L,int R,int l,int r){
		if(L>=l&&R<=r){
			return t[u].p;
		}
		pushdown(u);
		int mid=(L+R)>>1;
		if(l<=mid&&r>mid)return Query(ls,L,mid,l,r)+Query(rs,mid+1,R,l,r);
		if(l<=mid)return Query(ls,L,mid,l,r);
		return Query(rs,mid+1,R,l,r);
	}
}T;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q>>m;
	cin>>(s+1);
	T.build(1,1,n);
	while(Q--){
		int opt,l,r;
		cin>>opt;
		if(opt==1){
			char c;
			cin>>l>>r>>c;
			T.Cover(1,1,n,l,r,c-'a');	
		}
		else{
			static char c[12];
			static int p[12];
			cin>>c;
			l=1,r=n;
			for(int i=0;i<m;++i){
				p[c[i]-'a']=i;
			}
			int ans=0;
			auto t=T.Query(1,1,n,l,r);
			for(int i=0;i<m;++i){
				for(int j=0;j<m;++j){
					if(p[i]>=p[j])ans+=t.cnt[i][j];
				}
			}
			cout<<ans+1<<'\n';
		}	
	}
	return 0;
}