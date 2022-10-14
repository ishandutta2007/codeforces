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
const int MAXN=2e5+2;
int n,m,x;
int a[MAXN],b[MAXN];
int l[MAXN],r[MAXN];
int bit[MAXN];
int rnk[MAXN];
int ord[MAXN];
bool vis[MAXN];
void add(int pos,int val){
	while(pos<MAXN){
		bit[pos]+=val;
		pos+=pos&-pos;
	}
}
int query(int pos){
	int s=0;
	while(pos){
		s+=bit[pos];
		pos-=pos&-pos;
	}
	return s;
}
bool cmp(int A,int B){
	if(a[A]==a[B]) return A>B;
	return a[A]>a[B];
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,m) scanf("%d",&b[i]);
	set<mp> s;
	rb(i,1,n) ord[i]=i;
	sort(ord+1,ord+1+n,cmp);
	rb(i,1,n) rnk[ord[i]]=i;
	vector<mp> col;
	rb(i,1,m) col.PB(II(b[i],i));
	sort(ALL(col));
	int pt=0;
	rb(i,1,m) l[i]=r[i]=n+1;
	rb(i_,1,n){
		int I=ord[i_];
		while(pt<col.size()&&col[pt].FIR+a[I]<=x){
			int i=col[pt++].SEC;
			if(!vis[i-1]&&!vis[i+1]){
				s.insert(II(i,b[i]));
				l[i]=i_;
			}
			else if(vis[i-1]&&!vis[i+1]);
			else if(!vis[i-1]&&vis[i+1]);
			else if(vis[i-1]&&vis[i+1]){
				auto ite=s.upper_bound(II(i,0));
				auto pr=prev(ite);
				mp nd;
				if(pr->SEC>ite->SEC) nd=*ite,r[pr->FIR]=i_;
				else nd=*pr,r[ite->FIR]=i_;
				s.erase(ite);
				s.erase(pr);
				s.insert(nd);
			}
			vis[i]=1;
		}
	}
	LL ans=0;
	reverse(ALL(col));
	reverse(ord+1,ord+1+n);
	pt=1;
	s.clear();
	memset(vis,0,sizeof(vis));
	for(auto it:col){
		int j=it.SEC;
		while(pt<=n&&a[ord[pt]]+it.FIR<=x){
			int i=ord[pt++];
			if(!vis[i-1]&&!vis[i+1]){
				s.insert(II(i,a[i]));
				add(rnk[i],1);
			}
			if(vis[i-1]&&vis[i+1]){
				auto ite=s.upper_bound(II(i,0));
				auto pr=prev(ite);
				if(pr->SEC>ite->SEC){
					add(rnk[pr->FIR],-1);
					s.erase(pr);
				}
				else{
					add(rnk[ite->FIR],-1);
					s.erase(ite);
				}
			}
			vis[i]=1;
		}
		if(r[j]>l[j]){
			ans+=query(r[j]-1)-query(l[j]-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}