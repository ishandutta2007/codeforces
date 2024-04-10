/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,k;
int cnt=1;
vector<int> g[200000+20];
int fa[200000+20];
int sz[200000+20];
int is[200000+20];
int son[200000+20][2];
void go(int now,int sum){
	sz[now]=sum;
	if(sum==1) return;
	fa[cnt+1]=now;
	g[now].PB(cnt+1);
	is[cnt+1]=0;
	son[now][0]=cnt+1;
	go(++cnt,sum/2);
	fa[cnt+1]=now;
	g[now].PB(cnt+1);
	is[cnt+1]=1;
	son[now][1]=cnt+1;
	go(++cnt,(sum+1)/2);
}
set<int> s;
void era(int idx){
	s.insert(idx);
	if(k==0) return;
	if(s.find(son[fa[idx]][is[idx]^1])!=s.end()){
		s.erase(son[fa[idx]][is[idx]^1]);
		s.erase(idx);
		++k;
		era(fa[idx]);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	go(1,n);
	int z=cnt;
	rb(i,1,cnt) if(g[i].empty()){
		z--;
	}
	if(k>cnt) puts("-1"),exit(0);
	k-=cnt;
	if(abs(k)&1) puts("-1"),exit(0);
	k/=2;
//	cout<<k<<endl;
	rb(i,1,cnt){
		if(g[i].empty()){
			era(i);
		}
	}
	int is=n;
	for(auto ite=s.begin();ite!=s.end();ite++){
		rb(i,1,sz[*ite]){
			printf("%d ",is-sz[*ite]+i);
		}
		is-=sz[*ite];
	}
	return 0;
}