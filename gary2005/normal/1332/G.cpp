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
int n,q,a[MAXN];
mp mx[MAXN][18],mn[MAXN][18];
int lg[MAXN],tormx[MAXN],tormn[MAXN],tolmx[MAXN],tolmn[MAXN];
int bs3mx[MAXN],bs3mn[MAXN],bs4[MAXN];
vector<int> badmn[MAXN],badmx[MAXN],bad4[MAXN];
mp qrymx(int l,int r){
	int len=lg[r-l+1];
	return max(mx[l][len],mx[r-(1<<len)+1][len]);
}
mp qrymn(int l,int r){
	int len=lg[r-l+1];
	return min(mn[l][len],mn[r-(1<<len)+1][len]);
}
struct ST_T{
	mp a[MAXN][18];
	void build(){
		rb(j,1,17)
			rb(i,1,n){
				if(i+(1<<j)-1<=n){
					a[i][j]=min(a[i][j-1],a[i+(1<<(j-1))][j-1]);
				}
			}
	}
	mp query(int l,int r){
		int len=lg[r-l+1];
		return min(a[l][len],a[r-(1<<len)+1][len]);
	}
}stmx,stmn,st4;
int main(){
	scanf("%d%d",&n,&q);
	lg[1]=0;
	rb(i,2,n) lg[i]=lg[i>>1]+1;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n) mx[i][0]=II(a[i],i),mn[i][0]=II(a[i],i);
	rb(j,1,17) rb(i,1,n){
		if(i+(1<<j)-1<=n){
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
		}
	}
	rb(i,1,n) tormx[i]=tormn[i]=n+1,tolmx[i]=tolmn[i]=0;
	rb(i,1,n-1){//tormx
		if(qrymx(i+1,n).FIR>a[i]){
			int l=i+1,r=n;
			while(l<r){
				int mid=(l+r)>>1;
				if(qrymx(i+1,mid).FIR<=a[i]) l=mid+1;
				else r=mid;
			}
			tormx[i]=l+1;
		}
		if(qrymn(i+1,n).FIR<a[i]){
			int l=i+1,r=n;
			while(l<r){
				int mid=(l+r)>>1;
				if(qrymn(i+1,mid).FIR>=a[i]) l=mid+1;
				else r=mid;
			}
			tormn[i]=l+1;
		}
	}
	rb(i,2,n){
		if(qrymx(1,i-1).FIR>a[i]){
			int l=1,r=i;
			while(l<r-1){
				int mid=(l+r)>>1;
				if(qrymx(mid,i-1).FIR<=a[i]) r=mid;
				else l=mid;
			}
			tolmx[i]=l-1;
		}
		if(qrymn(1,i-1).FIR<a[i]){
			int l=1,r=i;
			while(l<r-1){
				int mid=(l+r)>>1;
				if(qrymn(mid,i-1).FIR>=a[i]) r=mid;
				else l=mid;
			}
			tolmn[i]=l-1;
		}
	}
	set<int> okmx,okmn,ok4;
	rb(i,1,n){
		if(tolmx[i]!=0) okmx.insert(i);
		if(tolmn[i]!=0) okmn.insert(i);
		if(min(tolmx[i],tolmn[i])!=0) ok4.insert(i);
		badmn[tolmn[i]].PB(i);
		badmx[tolmx[i]].PB(i);
		bad4[min(tolmn[i],tolmx[i])].PB(i);
	}
	okmx.insert(n+1);
	okmn.insert(n+1);
	ok4.insert(n+1);
	rb(i,1,n){
		bs3mx[i]=*okmx.lower_bound(tormx[i]);
		bs3mn[i]=*okmn.lower_bound(tormn[i]);
		bs4[i]=*ok4.lower_bound(max(tormx[i],tormn[i]));
		for(auto it:badmn[i]) okmn.erase(it);
		for(auto it:badmx[i]) okmx.erase(it);
		for(auto it:bad4[i]) ok4.erase(it);
		stmx.a[i][0]=II(bs3mx[i],i);
		stmn.a[i][0]=II(bs3mn[i],i);
		st4.a[i][0]=II(bs4[i],i);
	}
	stmx.build();
	stmn.build();
	st4.build();
//	cout<<tormx[26]<<' '<<tormn[26]<<" "<<tolmx[29]<<' '<<tolmn[29]<<" "<<a[29]-qrymn(27,28).FIR<<endl;
	rb(i,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		if(st4.query(l,r).FIR<=r){
			int z=st4.query(l,r).SEC;
			printf("4\n");
			int x,y;
			x=qrymx(z,bs4[z]).SEC;
			y=qrymn(z,bs4[z]).SEC;
			printf("%d %d %d %d\n",z,min(x,y),max(x,y),bs4[z]);
			continue;
		}
		else if(stmx.query(l,r).FIR<=r){
			int z=stmx.query(l,r).SEC;
			printf("3\n%d %d %d\n",z,qrymx(z,bs3mx[z]).SEC,bs3mx[z]);
			continue;
		}
		else if(stmn.query(l,r).FIR<=r){
			int z=stmn.query(l,r).SEC;
			printf("3\n%d %d %d\n",z,qrymn(z,bs3mn[z]).SEC,bs3mn[z]);
			continue;
		}
		puts("0");
	}
	return 0;
}