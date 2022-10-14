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
//#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rand()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
//const LL INF=23333333333333333;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct node{
int maxi,add,val,block;
int size,l,r,fix;
bool flag;
}v[200000+20];
void update(int index)
{
//	v[index].mini=v[index].block;
	v[index].maxi=v[index].val;
	v[index].size=1;
	if(v[index].l){
//		v[index].mini=mini(v[index].mini,v[v[index].l].mini);
		v[index].size+=v[v[index].l].size;
		v[index].maxi=max(v[index].maxi,v[v[index].l].maxi+v[index].add);
	}
	if(v[index].r){
//		v[index].mini=mini(v[index].mini,v[v[index].r].mini);
		v[index].size+=v[v[index].r].size;
		v[index].maxi=max(v[index].maxi,v[v[index].r].maxi+v[index].add);
	}
}
void push_down(int index){
	if(v[index].flag){
		//this must be reversed
		if(v[index].l){
			v[v[index].l].flag^=1;
			swap(v[v[index].l].l,v[v[index].l].r);	
		}
		if(v[index].r){
			v[v[index].r].flag^=1;
			swap(v[v[index].r].l,v[v[index].r].r);	
		}
		v[index].flag=0;
	}
	
	if(v[index].l){
		v[v[index].l].add+=v[index].add;
		v[v[index].l].maxi+=v[index].add;
		v[v[index].l].val+=v[index].add;
//		update(v[index].l);
	}
	if(v[index].r){
		v[v[index].r].add+=v[index].add;
		v[v[index].r].maxi+=v[index].add;
		v[v[index].r].val+=v[index].add;
	}
	v[index].add=0;
//	update(index);
}
int cnt=0;
int getnewnode(int val,int block){
	node tmp;
	tmp.maxi=val;
	tmp.val=val;
	tmp.add=tmp.flag=0;
	tmp.size=1;
	tmp.l=tmp.r=0;
	tmp.block=block;
//	tmp.mini=b,lock;
	tmp.fix=random(1234567890);
	cnt++;
	v[cnt]=tmp;
	return cnt;
}

void split(int base,int& x,int& y,int boundary){
	if(!base){
		x=y=0;
		return;
	}
	if(v[base].size==boundary){
		x=base;
		y=0;
		update(x);
	}
	if(!boundary){
		x=0;
		y=base;
		update(y);
	}
	push_down(base); 
	if(v[v[base].l].size>=boundary){
		y=base;
		v[y]=v[base];
		split(v[base].l,x,v[y].l,boundary);
		update(y);
	}
	else{
		x=base;
		v[x]=v[base];
		split(v[base].r,v[x].r,y,boundary-v[v[base].l].size-1);
		update(x);
	}
} 
void split2(int base,int& x,int& y,int boundary){//<boundary >=boundary
	if(!base){
		x=y=0;
		return;
	}
	push_down(base); 
	if(v[base].block>=boundary){
		y=base;
//		v[y]=v[base];
		split2(v[base].l,x,v[y].l,boundary);
		update(y);
	}
	else{
		x=base;
//		v[x]=v[base];
		split2(v[base].r,v[x].r,y,boundary);
		update(x);
	}
} 
int merge(int x,int y){
	if((!x)||(!y)){
		if(x+y){
			update(x+y);
		}
		return x+y;
	} 
	if(v[x].fix>v[y].fix){
		push_down(x);	
		v[x].r=merge(v[x].r,y);
		update(x);
		return x;
	}
	else{
		push_down(y);
		v[y].l=merge(x,v[y].l);
		update(y);
		return y;
	}
}
int root=1;
map <mp,bool> M;
int main(){
	srand(19260817);
	fastio;
	int n,k,m;
	cin>>n>>k>>m;
	int cnt=0;
	rb(i,1,m){
		int x,y;
		cin>>x>>y;
		int val=y+abs(x-k);
//		cerr<<"#"<<val<<endl;
		if(M[II(x,y)]){
			cnt--;	
			if(cnt==0){
				cnt=0;
				M[II(x,y)]=0;
				cout<<0<<endl;
				continue;
			}
			else{
				int L,R;
				split2(root,L,R,val);
				int MID;
				split(R,MID,R,1);
				v[L].add--;
				v[L].val--;
				v[L].maxi--;
				root=merge(L,R);
			}
		}
		else{
			cnt++;
			if(cnt==1){
				root=getnewnode(val,val);
			}
			else{
				int L,R;
				split2(root,L,R,val);
				if(L){
				v[L].add++;
				v[L].val++;
				v[L].maxi++;
				}
//				cerr<<"@"<<v[L].block<<" "<<val<<endl;
				int Add=0;
				if(R)
					Add+=v[R].size;
				int MID=getnewnode(Add+val,val);
				L=merge(L,MID);
				root=merge(L,R); 
			}
		}
		cout<<max(0,v[root].maxi-n)<<endl;
		M[II(x,y)]^=1;
		
	}
	return 0;
}