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
const LL INF=233333333333333333;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,a[500000+20],b[500000+20],p[500000+20];
LL segtree[(500000+20)*8],addtree[(500000+20)*8];
int treen;
LL add(int a,int b,LL val,int l=1,int r=treen+1,int now=1){
	if(r<=b&&l>=a){
		addtree[now]+=val;
		return segtree[now]+addtree[now];
	}
	if(r<=a||l>=b){
		return segtree[now]+addtree[now];
	}
	int mid=(l+r)>>1;
	return (segtree[now]=max(add(a,b,val,l,mid,now<<1),add(a,b,val,mid,r,(now<<1)+1)))+addtree[now];
}
LL query(int a,int b,int l=1,int r=treen+1,int now=1){
	if(a==0) return 0;
	if(r<=b&&l>=a){
		return segtree[now]+addtree[now];
	}
	if(r<=a||l>=b){
		return -INF;
	}
	int mid=(l+r)>>1;
	return (max(query(a,b,l,mid,now<<1),query(a,b,mid,r,(now<<1)+1)))+addtree[now];
}
int id[500000+20],suf[500000+20];
//
//void change(int X,int VAL){
//	X+=treen-1;
//	addtree[X]=0;
//	segtree[X]=VAL;
//	X>>=1;
//	while(X){
//		segtree[X]=max(segtree[X<<1]+addtree[X<<1],segtree[(X<<1)+1]+addtree[(X<<1)+1]);
//		X>>=1;
//	}
//}
int main(){
	fastio;
	memset(suf,0x3f,sizeof(suf));
	cin>>n;rb(i,1,n) cin>>a[i];
	rb(i,1,n) cin>>p[i];
	cin>>m;
	rb(i,1,m) cin>>b[i],id[b[i]]=i;
	rl(i,n,1){
		suf[i]=suf[i+1];
		if(id[i]) suf[i]=id[i];
	}
	treen=1<<(int)(ceil(log2(double(n))));
//	cout<<treen<<endl;
	rb(i,1,treen<<1) segtree[i]=-INF;
	int Ok=0;
	rb(i,1,n){
		if(Ok==m) break;
		if(a[i]==b[Ok+1]) Ok++;
	}	
	if(Ok!=m) cout<<"NO"<<endl;
	else{
		rb(i,1,n){
			if(p[i]>0){
				if(suf[a[i]]<0x3f3f3f3f)
				add(suf[a[i]],m+1,p[i]);
			}
			if(id[a[i]]){
				LL prev=query(id[a[i]],id[a[i]]+1);
				LL nxt=query(id[a[i]]-1,id[a[i]]);
//				cout<<i<<" "<<nxt<<"_"<<id[a[i]]<<" "<<a[i]<<" "<<prev<<endl;
				nxt+=p[i];
				if(nxt>prev&&nxt>-(INF>>1)){
					add(id[a[i]],id[a[i]]+1,-prev);
//					cout<<"^"<<query(id[a[i]],id[a[i]]+1)<<" "<<-prev<<" "<<addtree[1+treen-1]<<endl;
					add(id[a[i]],id[a[i]]+1,nxt);
				}
//					cout<<"#"<<query(id[a[i]],id[a[i]]+1)<<endl;
			}	
		}
		LL res=0;
		rb(i,1,n)
			res+=p[i];
//		cout<<res<<" "<<query(m,m+1)<<endl;
		cout<<"YES\n"<<res-query(m,m+1)<<endl;
	}
	return 0;
}