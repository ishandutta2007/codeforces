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
int N,n;
LL addtree[200000*8],seg[200000*8]; 
void build(int now){
	if(now>=N) return;
	build(now<<1);
	build((now<<1)+1);
	seg[now]=min(seg[(now<<1)+1],seg[now<<1]);
}
LL add(int a,int b,int val,int l=1,int r=N+1,int now=1){
	if(r<=a||l>=b){
		return addtree[now]+seg[now];
	}
	if(r<=b&&l>=a){
		addtree[now]+=val;
		return addtree[now]+seg[now];
	}
	int mid=(l+r)>>1;
	return (seg[now]=min(add(a,b,val,l,mid,now<<1),add(a,b,val,mid,r,(now<<1)+1)))+addtree[now];
}
LL query(int a,int b,int l=1,int r=N+1,int now=1){
	if(r<=a||l>=b){
		return (LL)(2e17);
	}
	if(r<=b&&l>=a){
		return addtree[now]+seg[now];
	}
	int mid=(l+r)>>1;
	return min(query(a,b,l,mid,now<<1),query(a,b,mid,r,(now<<1)+1))+addtree[now];
}
int main(){
	fastio;
	cin>>n;
	memset(seg,127,sizeof(seg));
	N=1<<int(ceil(log2(double(n))));
	rb(i,1,n){
		cin>>seg[N+i-1];
	}
	build(1);
	int m;
	cin>>m;
	char c[1000];
	rb(i,1,m){
		int cnt=0;
		int num[3]={0};
		cnt=1;
		cin>>num[0]>>num[1];
        if(cin.get()!=' '){
        }
        else{
        	cnt++;
        	cin>>num[2];
        }
		int L,R,V;
		L=num[0];
		R=num[1];
		V=num[2]; 
		L++;
		R++;
		if(cnt==1){
			if(R<L){
				cout<<min(query(1,R+1),query(L,n+1))<<endl;
			}
			else{
				cout<<query(L,R+1)<<endl;
			}
		}
		else{
			if(R<L){
				add(1,R+1,V);
				add(L,n+1,V);
			}
			else{
				add(L,R+1,V);
			}
		}
	}
	return 0;
}