#include<bits/stdc++.h>
#define x first
#define y second
//#define bug(x) cerr<<#x<<'='<<x<<' '
//#define debug(x) cerr<<#x<<'='<<x<<'\n'
#define FOR(a,b,c) for(int a=(b),a##_end=(c);a<=a##_end;++a)
#define ROF(a,b,c) for(int a=(b),a##_end=(c);a>=a##_end;--a)
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f,N=3e5+10;
template<class T>inline bool chkmin(T &A,T B){return B<A?A=B,1:0;}
template<class T>inline bool chkmax(T &A,T B){return A<B?A=B,1:0;}
int n,K,x[N],l[N],r[N],q[N];
int rt[N],B[N],T[N],h,tot;
vector<int>beg[N],ed[N],now[N];
struct Segment_Tree{
	#define lson pl,mid,ch[p][0]
	#define rson mid+1,pr,ch[p][1]
	int tot,sum[N*20],ch[N*20][2];
	void Up(int p){sum[p]=sum[ch[p][0]]+sum[ch[p][1]];}
	void Update(int pl,int pr,int &p,int k,int t){
		if(!p)p=++tot;
		if(pl==pr){sum[p]+=t;return;}
		int mid=(pl+pr)>>1;
		if(k<=mid)Update(lson,k,t);
		else Update(rson,k,t);
		Up(p);
	}
	int Query(int pl,int pr,int p,int l,int r){
		if(!p)return 0;
		if(pl==l&&pr==r)return sum[p];
		int mid=(pl+pr)>>1;
		if(r<=mid)return Query(lson,l,r);
		else if(mid<l)return Query(rson,l,r);
		return Query(lson,l,mid)+Query(rson,mid+1,r);
	}
}Tr;
int main(){
//	freopen("input.txt","r",stdin);
//	freopen("out1.txt","w",stdout);
	ll ans=0;
	scanf("%d%d",&n,&K);
	FOR(i,1,n){
		scanf("%d%d%d",&x[i],&r[i],&q[i]);
		T[++h]=q[i];
		B[++tot]=x[i];
		B[++tot]=x[i]-r[i];
		B[++tot]=x[i]+r[i];
	}
	sort(B+1,B+1+tot);
	tot=unique(B+1,B+1+tot)-B-1;
	sort(T+1,T+1+h);
	h=unique(T+1,T+1+h)-T-1;
	FOR(i,1,n){
		l[i]=lower_bound(B+1,B+1+tot,x[i]-r[i])-B;
		r[i]=lower_bound(B+1,B+1+tot,x[i]+r[i])-B;
		x[i]=lower_bound(B+1,B+1+tot,x[i])-B;
		beg[l[i]].push_back(i);
		ed[r[i]].push_back(i);
		now[x[i]].push_back(i);
		q[i]=lower_bound(T+1,T+1+h,q[i])-T;
	}
	FOR(i,1,tot){
		for(auto y:beg[i])
			Tr.Update(1,tot,rt[q[y]],x[y],1);
		for(auto y:now[i]){
			FOR(j,q[y],h){
				if(T[j]-T[q[y]]>K)break;
				ans+=Tr.Query(1,tot,rt[j],l[y],r[y]);
			}
			ROF(j,q[y]-1,1){
				if(T[q[y]]-T[j]>K)break;
				ans+=Tr.Query(1,tot,rt[j],l[y],r[y]);
			}
//			bug(y),debug(ans);
		}
		for(auto y:ed[i])
			Tr.Update(1,tot,rt[q[y]],x[y],-1);
	}
	printf("%lld\n",(ans-n)/2);
	return 0;
}