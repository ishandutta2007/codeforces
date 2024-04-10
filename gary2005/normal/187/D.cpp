/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,g,r,t,l[100000+10],nxt[100000+20];LL dp[100000+10],sum[100000+10];
int N,tree[800000+20];
void change(int now,int val){
	now+=N-1;
	tree[now]=val;
	now>>=1;
	while(now){
		tree[now]=min(tree[now<<1],tree[(now<<1)+1]);
		now>>=1;
	}
}
int query(int a,int b,int now=1,int l=1,int r=N+1){
//	cout<<l<<" "<<r<<endl;
	if(a>=b) return INF;
	if(r<=a||l>=b){
		return INF;
	}
	if(r<=b&&l>=a) return tree[now];
	int mid=(l+r)>>1;
	return min(query(a,b,now<<1,l,mid),query(a,b,(now<<1)+1,mid,r));
}
vector<int> v;
int lowerbound(int index){
	return lower_bound(ALL(v),index)-v.begin()+1;
}
int Query(int val){
	int res;
	/*(sum[j]%t-val+t)%t>=g
	*/
	int from,to;
	from=(g+val)%t;
	to=(t-1+val)%t;
	from+=t;
	to+=t;
	from%=t;
	to%=t;
//	cout<<from<<" "<<to<<endl;
	int l,r;
	if(from<=to)
	{
		l=lowerbound(from);
		r=lowerbound(to+1);
		res=query(l,r);
	}
	else{
		l=lowerbound(from),r=N;
		res=query(l,r);
		l=1,r=lowerbound(to+1);
		res=min(res,query(l,r));
	}
	if(res==INF) res=0;
	return res;
}
int main(){
	fastio;
	memset(tree,0x3f,sizeof(tree));
	cin>>n>>g>>r;
	N=1;
	while(N<n) N<<=1;
	t=g+r;
	rb(i,1,n+1) cin>>l[i],sum[i]=sum[i-1]+l[i];
//	rb(i,1,n){
//		cout<<"s"<<sum[i]%t<<endl;
//	}
	map<int,int> m;
	rb(i,1,n) m[sum[i]%t]=1;
	int it=0;
	for(map<int,int>:: IT ite=m.begin();ite!=m.end();ite++) ite->SEC=++it;
	for(map<int,int>:: IT ite=m.begin();ite!=m.end();ite++) v.PB(ite->FIR);
	rl(i,n,1){
		nxt[i]=Query(sum[i]%t);
		change(m[sum[i]%t],i);
	}  
	rl(i,n,1){
		if(nxt[i]==0){
			dp[i]=sum[n+1]-sum[i];
		} 
		else{
			dp[i]=dp[nxt[i]]+sum[nxt[i]]-sum[i]+t-((sum[nxt[i]]-sum[i])%t);
		}
	}
	int query_num;
	cin>>query_num;
	rb(______,1,query_num){
		int ti;
		cin>>ti;
		int nxt_tmp;
		nxt_tmp=Query(-ti%t);
		if(!nxt_tmp){
			cout<<sum[n+1]+ti<<endl;
		}
		else{
			cout<<sum[nxt_tmp]+ti+dp[nxt_tmp]+t-((sum[nxt_tmp]+ti)%t)<<endl;
		}
	}
	return 0;
}