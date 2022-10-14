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
int f[333];
int m[200000+233];
vector<int> g[200000+233];
bool ban[200000+233];
int siz[200000+233];
void gao(int now,int pre,vector<mp> & v,int k){
	siz[now]=1;
	for(auto it:g[now]){
		if(!ban[it]&&it!=pre){
			gao(it,now,v,k);
			if(siz[it]==f[k]){
				v.PB(II(it,now));
			}
			siz[now]+=siz[it];
		}
	}
}
int K;
void gao2(int now,int pre,vector<mp> & v,int k){
	if(siz[now]==f[k]) return;
	if(K-siz[now]==f[k]) v.PB(II(pre,now));
	for(auto it:g[now]){
		if(!ban[it]&&it!=pre){
			gao2(it,now,v,k);
		}
	}
}
bool solve(int now,int pre,int k){
	if(k<=4){
		return 1;
	}
	vector<mp> v;
	gao(now,pre,v,k-2);
	K=siz[now];
//	if(K!=f[k]){
//		cout<<now<<' '<<pre<<' '<<K<<' '<<f[k]<<endl;
//	}
	gao2(now,pre,v,k-2);
	if(v.size()==0||v.size()>2){
		return 0;
	}
	now=v[0].SEC;
	ban[v[0].SEC]=1;
	if(!solve(v[0].FIR,v[0].SEC,k-2)) return 0;
	ban[v[0].SEC]=0;
	ban[v[0].FIR]=1;
	if(!solve(now,0,k-1)) return 0;
	ban[v[0].FIR]=0;
	return 1;
}
int main(){
	f[1]=f[2]=1;
	int k=2;
	rb(i,1,333){
		++k;
		f[k]=f[k-1]+f[k-2];
		if(f[k]>2e5){
			--k;
			break;
		}
		
	}
	rb(i,1,k){
		m[f[i]]=i;
	}
	int n;
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	if(!m[n]){
		printf("NO\n");
		return 0;
	}
	if(solve(1,0,m[n])) printf("YES\n");
	else printf("NO\n");
	return 0;
}