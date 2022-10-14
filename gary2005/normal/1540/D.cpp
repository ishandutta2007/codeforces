/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+1;
const int MAGIC=300;
int n;
struct FWTTT{
	int tree[MAXN];
	FWTTT(){
		memset(tree,0,sizeof(tree));
	}
	void add(int pos,int val){
		while(pos<=n){
			tree[pos]+=val;
			pos+=pos&-pos;
		}
	}
	int lower_bound(int val){
		int now=0;
		int sum=0;
		rl(i,16,0){
			if(now+(1<<i)>n) continue;
			if(sum+tree[now|(1<<i)]<val){
				now|=1<<i;
				sum+=tree[now];
			}
		}
		return now+1;
	}
	int query(int pos){
		int sum=0;
		while(pos){
			sum+=tree[pos];
			pos^=pos&-pos;
		}
		return sum;
	}
}fwt[MAXN/MAGIC+3];
vector<int> ope[MAXN/MAGIC+3];
int b[MAXN];
bool z[MAXN];
void build(int id){
	z[id]=0;
	for(auto it:ope[id]) fwt[id].add(it,-1);
	ope[id].clear();
	int l,r;
	l=(id-1)*MAGIC+1;
	r=min(n,id*MAGIC);
	rb(i,l,r){
		int x=fwt[id].lower_bound(b[i]);
		ope[id].PB(x);
		fwt[id].add(x,1);
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) b[i]=read(),b[i]=i-b[i];
	rb(i,1,(n+MAGIC-1)/MAGIC){
		z[i]=1;
		rb(j,1,n) fwt[i].tree[j]=j&-j;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int ty;
		ty=read();
		if(ty==1){
			int p,x;
			p=read();
			x=read();
			b[p]=p-x;
			p=(p+MAGIC-1)/MAGIC;
			z[p]=1;
		}
		else{
			int x;
			x=read();
			int ans=b[x];
			for(int i=x+1;i<=n;){
				if(i%MAGIC==1){
					if(z[i/MAGIC+1]) build(i/MAGIC+1);
					ans=fwt[i/MAGIC+1].query(ans);
					i+=MAGIC;
				}
				else{
					ans+=ans>=b[i];
					i++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}