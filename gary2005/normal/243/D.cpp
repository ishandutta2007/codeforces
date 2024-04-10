/*
{By GWj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
/*}
*/
int n;
double x,y;
int a[1001][1001];
mp seg[1001][1001];
double k;
int ty;
LL work_point(int fu,int ck){
	double b=(double)ck-k*(double)(fu);
	b*=1000000.0;
	return llround(b);
}
mp work(int fu,int ck){
	if(ty==1){
		return II(work_point(fu,ck-1),work_point(fu-1,ck));
	}
	else
	if(ty==2){
		return II(work_point(fu-1,ck-1),work_point(fu,ck));
	}
	else
	if(ty==3){
		return II(work_point(fu-1,ck-1),work_point(fu,ck));
	}
	else{
		return II(work_point(fu,ck-1),work_point(fu-1,ck));
	}
}
const int N=1<<21;
int tree[N+N],tag[N+N];
void push_down(int index){
	check_max(tree[index],tag[index]);
	if(index<N){
		check_max(tag[index<<1],tag[index]);
		check_max(tag[index<<1|1],tag[index]);
	}
}
void push_up(int index){
	tree[index]=min(tree[index<<1],tree[index<<1|1]);
}
void modify(int ll,int rr,int val,int now=1,int l=1,int r=N+1){
	push_down(now);
	if(r<=ll||l>=rr){
		return ;
	}
	if(r<=rr&&l>=ll){
		check_max(tag[now],val);
		push_down(now);
		return;
	}
	int mid=(l+r)>>1;
	modify(ll,rr,val,now<<1,l,mid);
	modify(ll,rr,val,now<<1|1,mid,r);
	push_up(now);
}
int query(int ll,int rr,int now=1,int l=1,int r=N+1){
	push_down(now);
	if(r<=ll||l>=rr){
		return INF;
	}
	if(r<=rr&&l>=ll){
		return tree[now];
	}
	int mid=(l+r)>>1;
	return min(query(ll,rr,now<<1,l,mid),query(ll,rr,now<<1|1,mid,r));
}
int main(){
  fastio;
	cin>>n>>x>>y;
	if(x==0){
		rb(i,1,n)
			rb(j,1,n)
				R(a[i][j]);
		LL rest=0;
		rb(i,1,n){
			int maxi=0;
			rb(j,1,n){
				check_max(maxi,a[i][j]);
			}
			rest+=maxi;
		}
		cout<<rest<<endl;
		return 0;
	}
	if(y==0){
		rb(i,1,n)
			rb(j,1,n)
				R(a[i][j]);
		LL rest=0;
		rb(j,1,n){
			int maxi=0;
			rb(i,1,n){
				check_max(maxi,a[i][j]);
			}
			rest+=maxi;
		}
		cout<<rest<<endl;
		return 0;
	}
	k=y/x;
	if(y>0){
		if(x>0){
			ty=1;
		}
		else{
			ty=2;
		}
	}
	else{
		if(x>0){
			ty=3;
		}
		else{
			ty=4;
		}
	}
	rb(i,1,n)
		rb(j,1,n)
			R(a[i][j]);
	map<LL,int> dul; 
	rb(i,1,n)
		rb(j,1,n){
			seg[i][j]=work(i,j);
			dul[seg[i][j].FIR]=dul[seg[i][j].SEC]=1;
		}	
	int cnt=0;
	for(map<LL,int> :: IT ite=dul.begin();ite!=dul.end();ite++){ite->SEC=++cnt;}
	rb(i,1,n)
		rb(j,1,n)
			seg[i][j].FIR=dul[seg[i][j].FIR],seg[i][j].SEC=dul[seg[i][j].SEC];
	LL rest=0;
	if(ty==1){
		rb(j,1,n){
			rb(i,1,n){
				rest+=max(0,a[i][j]-query(seg[i][j].FIR,seg[i][j].SEC));
				modify(seg[i][j].FIR,seg[i][j].SEC,a[i][j]);
			}
		}
	}
	if(ty==2){
		rb(j,1,n){
			rl(i,n,1){
				rest+=max(0,a[i][j]-query(seg[i][j].FIR,seg[i][j].SEC));
				modify(seg[i][j].FIR,seg[i][j].SEC,a[i][j]);
			}
		}
	}
	if(ty==3){
		rl(j,n,1){
			rb(i,1,n){
				rest+=max(0,a[i][j]-query(seg[i][j].FIR,seg[i][j].SEC));
				modify(seg[i][j].FIR,seg[i][j].SEC,a[i][j]);
			}
		}
	}
	if(ty==4){
		rl(j,n,1){
			rl(i,n,1){
				rest+=max(0,a[i][j]-query(seg[i][j].FIR,seg[i][j].SEC));
				modify(seg[i][j].FIR,seg[i][j].SEC,a[i][j]);
			}
		}
	} 
	cout<<rest<<endl;
	return 0;
}
/*
2 1 1
10 20
20 30

*/