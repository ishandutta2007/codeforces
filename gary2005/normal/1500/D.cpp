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
inline void print(int x){
	if((x/10)) print(x/10);
	putchar(char('0'+x%10));
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1500+233;
int n,q;
int c[MAXN][MAXN],ans[MAXN][MAXN];
vector<mp> cnt[1500*1500+2];
int z[1500*1500+2]; 
vector<mp> fk[MAXN][MAXN];
vector<int> col;
int t[MAXN];
vector<int> add[MAXN];
bool vis[MAXN*MAXN];
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d%d",&n,&q);
	rb(i,1,n) rb(j,1,n) c[i][j]=read();
	rl(i,n,1){
		rb(j,1,n){
			fk[i][j].PB(II(c[i][j],i));
			for(auto it:fk[i+1][j]){
				if(it.FIR!=c[i][j])
					fk[i][j].PB(it);
			}
			if(fk[i][j].size()>q+1) fk[i][j].resize(q+1);
		}
	}
	rb(i,1,n){
		col.clear();
		rl(j,n,1){
			ans[i][j]=ans[i][j+1]+1;
			for(auto it:add[ans[i][j]]){
				while(cnt[it].size()>z[it]&&cnt[it][z[it]].FIR>j+ans[i][j]-1) z[it]++;
				if(cnt[it].size()>z[it]){
					if(cnt[it][z[it]].SEC<=i+ans[i][j]-1){
						if(!vis[it]) col.PB(it),vis[it]=1;
					}
					else{
						add[cnt[it][z[it]].SEC-i+1].PB(it);	
					}
				}
			}
			add[ans[i][j]].clear();
			for(auto it:fk[i][j]){
				while(cnt[it.FIR].size()>z[it.FIR]&&cnt[it.FIR].back().SEC>=it.SEC){
					cnt[it.FIR].POB();
				}
				cnt[it.FIR].PB(II(j,it.SEC));
				if(cnt[it.FIR][z[it.FIR]].SEC<=i+ans[i][j]-1){
					if(!vis[it.FIR]) col.PB(it.FIR),vis[it.FIR]=1;
				}
				else{
					add[cnt[it.FIR][z[it.FIR]].SEC-i+1].PB(it.FIR);	
				}
			}
			while(col.size()>q){
				ans[i][j]--;
				vector<int> nw;
				for(auto ite=col.begin();ite!=col.end();ite++){
					while(cnt[*ite].size()>z[*ite]&&cnt[*ite][z[*ite]].FIR>j+ans[i][j]-1){
						z[*ite]++; 
					}
					if(cnt[*ite].size()>z[*ite]){
						if(cnt[*ite][z[*ite]].SEC<=i+ans[i][j]-1) nw.PB(*ite);	
						else{
							add[cnt[*ite][z[*ite]].SEC-i+1].PB(*ite);
							vis[*ite]=0;
						}
					}
					else vis[*ite]=0;
				}
				col=nw;
			}
		}
		rb(j,1,n) add[j].clear();
		rb(j,1,n) for(auto it:fk[i][j]) cnt[it.FIR].clear(),z[it.FIR]=vis[it.FIR]=0;
	}
	rb(i,1,n) rb(j,1,n) t[min(n-i+1,ans[i][j])]++;
	rl(i,n,1) t[i]+=t[i+1];
	rb(i,1,n) print(t[i]),putchar('\n');
	return 0;
}