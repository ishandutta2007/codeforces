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
const int MAXN=2e5+233;
int p,m;
int n;
string s[MAXN];
LL num[MAXN];
int cnt[1<<15];
LL fuckc[1<<15];
const int MOD=199223;
struct hs{
	LL is[(1<<15)+3];
	int nex[(1<<15)+3],val[(1<<15)+3];
	int tp[199223];
	int cnt=0;
	void clear(){
		fill(tp,tp+MOD,-1);
		cnt=0;
	}
	void set(LL tmp,int v){
		unsigned LL z=tmp;
		z=z^(z<<3);
		z=z^(z>>7);
		z=z^(z<<17);
		z%=MOD;
		++cnt;
		nex[cnt]=tp[z];
		tp[z]=cnt;
		is[cnt]=tmp;
		val[cnt]=v;
	}
	int query(LL tmp){
		unsigned LL z=tmp;
		z=z^(z<<3);
		z=z^(z>>7);
		z=z^(z<<17);
		z%=MOD;
		for(int i=tp[z];i!=-1;i=nex[i]){
			if(is[i]==tmp) return val[i];
		}
		assert(0);
		return 0;
	}
}fuck;
int main(){
	cin>>n>>m>>p;
	rb(i,1,n) cin>>s[i];
	rb(i,1,n){
		rep(j,m){
			if(s[i][j]=='1'){
				num[i]+=1ll<<j;
			}
		}
	}
	LL ans=0;
	SRAND;
	rb(T,1,40){
		int x=random(n)+1;
//		cout<<x<<endl;
		if(num[x]==0) continue;
		int to[66]={0};
		fuck.clear();
		memset(cnt,0,sizeof(cnt));
		memset(fuckc,0,sizeof(fuckc));
		int C=0;
		rep(j,m){
			if(s[x][j]=='1'){
				to[j]=C;
				C++;
			}
		}
		for(LL smask=num[x];;smask=(smask-1)&num[x]){
			int Tmp=0;
			rep(j,m){
				if((smask>>j)&1){
					Tmp+=1<<to[j];
				}
			}
			fuck.set(smask,Tmp);
			fuckc[Tmp]=smask;
			if(!smask) break;
		}
		rb(i,1,n){
			cnt[fuck.query(num[i]&num[x])]++;
		}
		rep(j,C){
			rep(mask,1<<C){
				if((mask>>j)&1){
					cnt[mask^(1<<j)]+=cnt[mask];
				}
			}
		}
		rep(mask,1<<C){
			if(cnt[mask]>=(n+1)/2&&__builtin_popcount(mask)>__builtin_popcountll(ans)){
				ans=fuckc[mask];
			}
		}
	}
	rep(j,m){
		if((ans>>j)&1){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	return 0;
}