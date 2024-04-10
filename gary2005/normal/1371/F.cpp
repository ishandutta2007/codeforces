/*
AuThOr Gwj
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
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
	bool c1,c2;// 
	int mini,maxi,res;//<> <>,mini=INF,maxi=-INF  
};
const int MAXN=1<<19;
node segtree[MAXN*2+2][2];
char init[MAXN];
struct BIT{
	int bit[MAXN+10]={0},n=MAXN;
	int sum(int i){
		int s=0;
		while(i>0){
			s+=bit[i];
			i-=i &(-i);
		}
		return s;
	}
	int query(int l,int r){
		return sum(r)-sum(l-1);
	}
	void add(int i,int x=1){
		while(i<=n){
			bit[i]+=x;
			i+= i&(-i);	
		}
	}
}bit;
char RRverse(char c){
	if(c=='<'){
		return '>';
	}
	return '<';
}
char Reverse(int pos){
	if(bit.query(1,pos)&1){
		return init[pos];
	}
	else{
		if(init[pos]=='<') return '>';
	}
	return '<';
} 
bool nei(char c1,char c2){
	return (c1=='<')&&(c2=='>');
}
void merge(node& rest,node A,node B,bool flag,int r1){
	rest.mini=min(A.mini,B.mini);
	rest.maxi=max(A.maxi,B.maxi);
	rest.res=max(A.res,B.res);
	if(flag){
		biggest(rest.maxi,r1);
		smallest(rest.mini,r1);
		biggest(rest.res,max(B.mini!=INF? B.mini-r1:0,A.mini!=INF? r1-A.maxi:0));
	}
	else{
		if(A.mini!=INF&&B.mini!=INF)
		biggest(rest.res,B.mini-A.maxi);
	}
}
void build(int l=1,int r=MAXN+1,int now=1){
	if(l==r-1){
		node tmp;
		tmp.res=0;
		tmp.maxi=-INF;
		tmp.mini=INF;
		segtree[now][1]=segtree[now][0]=tmp;
	}
	else{
		int mid=(l+r)>>1;
		build(l,mid,now<<1);
		build(mid,r,(now<<1)+1);
		merge(segtree[now][0],segtree[now<<1][0],segtree[(now<<1)+1][0],nei(init[mid-1],init[mid]),mid-1);
		segtree[now][0].c1=segtree[now][0].c2=0;
		segtree[now][1].c1=segtree[now][1].c2=1;
		merge(segtree[now][1],segtree[now<<1][1],segtree[(now<<1)+1][1],nei(Reverse(mid-1),Reverse(mid)),mid-1);
		}//
//	if(segtree[now][0].res)
//	cout<<now<<" "<<" "<<l<<" "<<r<<"---"<<segtree[now][0].res<<endl;
}
void go(int a,int b,bool col,int now=1,int l=1,int r=MAXN+1){
	if(r<=a||l>=b){
		return ;
	}//cout<<l<<" "<<r<<endl;
	if(r<=b&&l>=a){
//	cout<<l<<" "<<r<<"!!"<<segtree[now][col^1].mini<<endl;
		swap(segtree[now][0],segtree[now][1]);
		return ;
	}
	int mid=(l+r)>>1;
	go(a,b,segtree[now][col].c1,now<<1,l,mid);
	go(a,b,segtree[now][col].c2,(now<<1)+1,mid,r);
	
	merge(segtree[now][col],
	segtree[now<<1][segtree[now][col].c1],
	segtree[(now<<1)+1][segtree[now][col].c2],
	nei(RRverse(Reverse(mid-1)),RRverse(Reverse(mid))),
	mid-1
	);
	
	merge(segtree[now][col^1],
	segtree[now<<1][segtree[now][col^1].c1],
	segtree[(now<<1)+1][segtree[now][col^1].c2],
	nei(Reverse(mid-1),Reverse(mid)),
	mid-1
	);
//	cout<<l<<" "<<r<<"-"<<segtree[now][col].mini<<endl;
}
void change(int l,int r){
	bit.add(l);
	bit.add(r+1,-1);
	go(l,r+1,0);
}
node ask(int a,int b,bool col,int now=1,int l=1,int r=MAXN+1){
	if(r<=b&&l>=a){
//	cout<<a<<","<<b<<";;"<<col<<" "<<now<<":"<<l<<"_"<<r<<"^^"<<segtree[now][col].mini<<endl;		
	return segtree[now][col];
	}
	node rest;
//	cout<<a<<","<<b<<";;"<<col<<" "<<now<<":"<<l<<"_"<<r<<"^^"<<rest.mini<<" "<<"ONLL"<<" "<<segtree[now][col].c1<<endl;
	int mid=(l+r)>>1;
	if(mid<=a){// 
		return ask(a,b,segtree[now][col].c2,(now<<1)+1,mid,r);
	}
	if(mid-1>=b-1){
		//
		return ask(a,b,segtree[now][col].c1,now<<1,l,mid); 
	}
	merge(rest,
	ask(a,b,segtree[now][col].c1,now<<1,l,mid),
	ask(a,b,segtree[now][col].c2,(now<<1)+1,mid,r),
	nei(RRverse(Reverse(mid-1)),RRverse(Reverse(mid))), 
	mid-1
	);
//	cout<<a<<","<<b<<";"<<col<<" "<<now<<":"<<l<<"_"<<r<<"^^"<<rest.mini<<endl;	
	return rest;
}
int query(int l,int r){
	node tmp=ask(l,r+1,0);
	biggest(tmp.res,max(tmp.mini!=INF? tmp.mini-l+1:0,tmp.mini!=INF? r-tmp.maxi:0));
	if(tmp.res==0)
		tmp.res=r-l+1;
//	cerr<<tmp.mini<<":;:;:"<<tmp.maxi<<endl;
	return tmp.res;
}
int main(){
	fastio;
	memset(init,'>',sizeof(init));
	int n,q;
	cin>>n>>q;
	rb(i,1,n) cin>>init[i];
	build();
//	cout<<segtree[1][0].c1<<endl;
	while(q--){
		int l,r;
		cin>>l>>r;
		change(l,r);//cerr<<"Done"<<segtree[1][0].c1<<endl;
		cout<<query(l,r)<<endl;
	}
	return 0;
}