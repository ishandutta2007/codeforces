//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,a,b;
LL sum[1001][1001];
LL cost[1001][1001];
const int MAXN=1000;
int tmp;
int deq[2001];
int Map[1001][1001];
LL mini[MAXN+10][MAXN+10];
int h,t;
LL allmini[MAXN+10][MAXN+10];
vector<pair<LL,int> > v;
//row i from j to j+b-1 's minimum
bool CMP(pair<LL,int> A,pair<LL,int> B){
	if(A.FIR!=B.FIR) return A.FIR<B.FIR;
	int ia,ib,ja,jb;
	ia=A.SEC/10000;
	ja=A.SEC%10000;
	ib=B.SEC/10000;
	jb=B.SEC%10000;
	if(ia!=ib) return ia<ib;
	return ja<jb;
}
int color[MAXN+10][MAXN+10];
vector<pair<mp,LL> > ans;
int main(){
	scanf("%d %d %d %d",&n,&m,&a,&b);
	rb(i,1,n)	
		rb(j,1,m){
			scanf("%d",&tmp);
			Map[i][j]=tmp;
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tmp;
		}
	rb(i,1,n){
		t=0;
		h=1;
		rb(j,1,b-1){
			while(t>=h&&Map[i][deq[t]]>=Map[i][j]) --t;
			deq[++t]=j;
		}
		rb(j,1,m-b+1)
		{
			while(t>=h&&Map[i][deq[t]]>=Map[i][j+b-1]) --t;
			deq[++t]=j+b-1;
			while(deq[h]<j) ++h;
			mini[i][j]=Map[i][deq[h]];
		}
	}
	rb(j,1,m-b+1){
		t=0;
		h=1;
		rb(i,1,a-1){
			while(t>=h&&mini[deq[t]][j]>=mini[i][j]) --t;
			deq[++t]=i;
		}
		rb(i,1,n-a+1){
			while(t>=h&&mini[deq[t]][j]>=mini[i+a-1][j]) -- t;
			deq[++t]=i+a-1;
			while(deq[h]<i) ++h;
			allmini[i][j]=mini[deq[h]][j];
		}	
	}
//	cout<<mini[1][3]<<endl;
	LL tot=a*b;
	rb(i,1,n-a+1)
		rb(j,1,m-b+1)
			v.PB(II((sum[i+a-1][j+b-1]-sum[i+a-1][j-1]-sum[i-1][j+b-1]+sum[i-1][j-1])-tot*(LL)(allmini[i][j]),i*10000+j));
	sort(v.begin(),v.end(),CMP);
	int SZ=v.size();
	rep(i,SZ)
	{
		int tmpi,tmpj;
		tmpi=v[i].SEC/10000;
		tmpj=v[i].SEC%10000;
		int OK=1;
		if(!OK) break;
			int xi,yi;
			int lasi,lasj;
			lasi=tmpi;
			lasj=tmpj;
			xi=lasi,yi=lasj;
			if(color[xi][yi]) OK=false;
			xi=lasi,yi=lasj+b-1;
			if(color[xi][yi]) OK=false;
			xi=lasi+a-1,yi=lasj;
			if(color[xi][yi]) OK=false;
			xi=lasi+a-1,yi=lasj+b-1;
			if(color[xi][yi]) OK=false;
		if(OK){
			rb(i,tmpi,tmpi+a-1)
			rb(j,tmpj,tmpj+b-1) color[i][j]=1;
			ans.PB(II(II(tmpi,tmpj),v[i].FIR));
		}
	}
	printf("%d\n",ans.size());
	rep(i,ans.size())
	printf("%d %d %I64d\n",ans[i].FIR.FIR,ans[i].FIR.SEC,ans[i].SEC);
	return 0;
}