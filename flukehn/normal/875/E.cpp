#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;//*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=100011;
int n,a[N],s1,s2,mi[22][N],mx[22][N],Log[N];
inline int Qi(int l,int r){int k=Log[r-l+1];return min(mi[k][l],mi[k][r-(1<<k)+1]);}
inline int Qj(int l,int r){int k=Log[r-l+1];return max(mx[k][l],mx[k][r-(1<<k)+1]);}
bool judge(int M){
//	debug(M);
	static int R[N];
	rep(i,1,n){
		int l=i,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(Qj(i,mid)-a[i]<=M && a[i]-Qi(i,mid)<=M)l=mid;
			else r=mid-1;
		}
		R[i]=l;
		/*debug(i),debug(l);
		if(i==1)ls=l;
		else if(i==2)k=max(ls,l);
		else k=max(k,l);*/
	}
//	rep(i,1,n)printf("%d%c",R[i]," \n"[i==n]);
	int i,k=max(R[1],R[2]);
	for(i=3;i<=k;i++)k=max(k,R[i]);//cout<<i<<endl;
//	debug(i);
	return i>n;
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
	n=rd()+2;//s1=rd(),s2=rd();
	rep(i,1,n)mi[0][i]=mx[0][i]=a[i]=rd();
	Log[0]=-1;rep(i,1,n)Log[i]=Log[i>>1]+1;
	for(int i=1;(1<<i)<=n;i++)
		for(int j=1;j+(1<<i)-1<=n;j++){
			mi[i][j]=min(mi[i-1][j],mi[i-1][j+(1<<i-1)]);
			mx[i][j]=max(mx[i-1][j],mx[i-1][j+(1<<i-1)]);
		}
	int l=abs(a[1]-a[2]),r=1000000001;
//	judge(2);/*
	while(l<r){
//		debug(l),debug(r);
		int mid=l+r>>1;
		if(judge(mid))r=mid;
		else l=mid+1;
	}//*/
	printf("%d\n",l);
}