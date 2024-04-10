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
const int MAXN=1e6+233;
#define win {printf("White\n");return;}
#define tie {printf("Draw\n");return;}
int n,deg[MAXN],wht[MAXN];
vector<int> g[MAXN];
bool solve2(){
	int cnt=0;
	rb(i,1,n){
		if(deg[i]==3){
			cnt++;
		}
	}
	return (cnt==2)&&(n&1);
}
void solve(){
	scanf("%d",&n);
	rb(i,1,2*n) deg[i]=0,wht[i]=0,g[i].clear();
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
		deg[u]++,deg[v]++;
	}
	rb(i,1,n){
		char c;
		cin>>c;
		wht[i]=(c=='W');
	}
	if(n<=2) tie
	rb(i,1,n) for(auto it:g[i]) if(wht[i]&&wht[it]) win
	rb(i,1,n) if(deg[i]>=3&&wht[i]) win
	rb(i,1,n){
		int cnt=0;
		for(auto it:g[i]) cnt+=wht[it];
		if(cnt>=2) win
		if(deg[i]>=3&&cnt) win
	}
	rb(i,1,n){
		if(wht[i]){
			deg[i]++;
			g[i].PB(++n);
			g[n].PB(i);
			g[n].PB(n+1);
			deg[n]=3;
			g[n+1].PB(n);
			g[n+2].PB(n);
			g[n].PB(n+2);
			deg[n+1]=deg[n+2]=1;
			n+=2;
		}
	}
	rb(i,1,n) if(deg[i]>3) win
	rb(i,1,n){
		int cnt=0;
		for(auto it:g[i]) cnt+=deg[it]>1;
		if(deg[i]==3){
			if(cnt>=2) win
		}
	}
	if(solve2()) win
	tie
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
/*

10

4
1 2
1 3
1 4
0

5
1 2
2 3
2 4
4 5
1
4



*/