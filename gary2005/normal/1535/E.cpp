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
const int MAXN=3e5+233;
int q,a[MAXN],c[MAXN],depth[MAXN],fa[MAXN][19];
int getk(int u,int k){
	rep(i,19){
		if((k>>i)&1) u=fa[u][i];
	}
	return u;
}
int main(){
//	freopen("test.in","r",stdin);
	scanf("%d",&q);
	scanf("%d%d",&a[0],&c[0]);
	depth[0]=0;
	rb(i,1,q){
		int ty;
		scanf("%d",&ty);
		if(ty==1){
			scanf("%d%d%d",&fa[i][0],&a[i],&c[i]);
			depth[i]=depth[fa[i][0]]+1;
			rb(j,1,18) fa[i][j]=fa[fa[i][j-1]][j-1];
		}
		else{
			int v,w;
			scanf("%d%d",&v,&w);
			int now=v;
			if(a[now]==0){
				puts("0 0");ff;
				continue;
			}
			rl(j,18,0){
				if(a[fa[now][j]]){
					now=fa[now][j];
				}
			}
//			cout<<a[0]<<'_'<<now<<endl;
			LL tot,money;
			tot=money=0;
			rb(i,depth[now],depth[v]){
				if(a[now]<=w){
					tot+=a[now];
					money+=1ll*a[now]*c[now];
					w-=a[now];
					a[now]=0;
				}
				else{
					a[now]-=w;
					tot+=w;
					money+=1ll*c[now]*w;
					w=0;
				}
				if(!w) break;
				if(i==v) break;
				now=getk(v,depth[v]-i-1);
			}
			printf("%lld %lld\n",tot,money);ff;
		}
	}
	return 0;
}