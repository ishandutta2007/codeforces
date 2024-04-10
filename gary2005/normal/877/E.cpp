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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
int N;
vector<int> each[200000+20];
bool Change[400000*8];
int seg[400000*8];
int sq[400000][2];
int cnt=0;
int sum[400000+20];
void dfs(int now){
	sum[cnt+1]++;
	sq[now][0]=++cnt;
	for(auto it:each[now]){
		dfs(it);
	}
	sq[now][1]=++cnt;
}
void build(int now){
	if(now>=N) return ;
	build(now<<1);
	build((now<<1)+1);
	seg[now]=seg[now<<1]+seg[(now<<1)+1];
}
int Rev(int l,int r,int val){
	return  sum[r-1]-sum[l-1]-val;
}
int change(int a,int b,int l,int r,int now){
	if(b<=l||a>=r){
		if(Change[now]){
			return Rev(l,r,seg[now]);
		} 
		else{
			return seg[now];
		}
	}
	if(r<=b&&l>=a){
		Change[now]^=1;
		if(Change[now]){
			return Rev(l,r,seg[now]);
		} 
		else{
			return seg[now];
		}
	}
	seg[now]=change(a,b,l,(l+r)>>1,now<<1)+change(a,b,(l+r)>>1,r,(now<<1)+1);
	if(Change[now]){
		return  Rev(l,r,seg[now]);
	}
	return seg[now];
}
int query(int a,int b,int l,int r,int now){
	if(b<=l||a>=r){
		return 0;
	}
	if(r<=b&&l>=a){
		if(Change[now]){
			return Rev(l,r,seg[now]);
		} 
		else{
			return seg[now];
		}
	}
	int res=query(a,b,l,(l+r)>>1,now<<1)+query(a,b,(l+r)>>1,r,(now<<1)+1);
	if(Change[now]){
		return  Rev(max(l,a),min(r,b),res);
	}
	return res;
}
int main(){
	fastio;
	cin>>n;
	N=1<<(int)(ceil(log2(double(n*2))));
	rb(i,2,n){
		int ai;
		cin>>ai;
		each[ai].PB(i);
	}
	dfs(1);
	rb(i,1,400000) sum[i]+=sum[i-1];
	rb(i,1,n){
		cin>>seg[sq[i][0]-1+N];
	}
	build(1);
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		int ve;
		cin>>ve;
		if(s[0]=='p'){
			change(sq[ve][0],sq[ve][1]+1,1,N+1,1);
		} 
		else{
			cout<<query(sq[ve][0],sq[ve][1]+1,1,N+1,1)<<endl;
		}
	}
	return 0;
}