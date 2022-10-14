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
const int MAGIC=1500;
int n,m;
int rest[MAXN];
int have[MAXN];
vector<pair<mp,int> > v;
bool cmp(pair<mp,int> A,pair<mp,int> B){
	if((A.FIR.SEC-1)/MAGIC!=(B.FIR.SEC-1)/MAGIC) return A.FIR.SEC<B.FIR.SEC;
	return A.FIR.FIR>B.FIR.FIR;
}
int cnt;
int ch[MAXN*19+23][2];
int tag[MAXN*19+23];
int val=0;
void clr(){
	cnt=0;
	val=0;
	memset(tag,0,sizeof(tag));
	memset(ch,0,sizeof(ch));
}
void add(int now=0,int deep=0){
	tag[now]^=1;
	if(deep==18) return;
	if(!ch[now][0]) ch[now][0]=++cnt; 
	add(ch[now][0],deep+1);
}
void rot(int now=0,int deep=0){
	if(ch[now][1]&&tag[ch[now][1]]) val^=1<<deep;
	swap(ch[now][0],ch[now][1]);
	if(ch[now][0]) rot(ch[now][0],deep+1);
	if(ch[now][1]&&tag[ch[now][1]]) val^=1<<deep;
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		int c;
		scanf("%d",&c);
		have[c]^=1;
	}
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		v.PB(II(II(l,r),i));
	}
	sort(ALL(v),cmp);
	int pr=-1,l=0;
	for(auto it:v){
		mp seg=it.FIR;
		if(seg.SEC-seg.FIR+1<=MAGIC){
			rb(i,seg.FIR,seg.SEC){
				if(have[i]){
					rest[it.SEC]^=(i-seg.FIR);
				}
			}
			continue; 
		}
		if((seg.SEC-1)/MAGIC!=pr){
			pr=(seg.SEC-1)/MAGIC;
			l=(seg.SEC-1)/MAGIC*MAGIC+1;
			clr();
		}
		while(l>seg.FIR){
			--l;
			rot();
			if(have[l]) add();
		}
		rest[it.SEC]=val;
		int r=(seg.SEC-1)/MAGIC*MAGIC+1;
		rb(i,r,seg.SEC){
			if(have[i]){
				rest[it.SEC]^=(i-seg.FIR);
			}
		}
	}
	rb(i,1,q){
		printf("%c","BA"[min(1,rest[i])]);
	}	
	return 0;
}