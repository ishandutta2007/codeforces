#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define INF 0x3f3f3f3f
#define M 200005

struct Mat{
	int Nxt[5][5];
	Mat() {memset(Nxt,INF,sizeof(Nxt));}
};
Mat Merge(const Mat &l,const Mat &r) {
	Mat tmp;
	FOR(i,0,4) FOR(j,i,4) FOR(k,j,4) tmp.Nxt[i][k]=min(tmp.Nxt[i][k],l.Nxt[i][j]+r.Nxt[j][k]);
//	cerr<<l.Nxt[0][1]<<endl;
	return tmp;
}
Mat sum[M<<2];
char str[M];
void build(int L,int R,int p) {
	if(L==R) {
		FOR(i,0,4) sum[p].Nxt[i][i]=0;
		if(str[L]=='2') {
			sum[p].Nxt[0][1]=0;
			sum[p].Nxt[0][0]=1;
		}
		if(str[L]=='0') {
			sum[p].Nxt[1][2]=0;
			sum[p].Nxt[1][1]=1;
		}
		if(str[L]=='1') {
			sum[p].Nxt[2][3]=0;
			sum[p].Nxt[2][2]=1;
		}
		if(str[L]=='7') {
			sum[p].Nxt[3][4]=0;
			sum[p].Nxt[3][3]=1;
		}
		if(str[L]=='6') {
			sum[p].Nxt[3][3]=1;
			sum[p].Nxt[4][4]=1;
		}
		return ;
	}
	int mid=L+R>>1;
	build(L,mid,p<<1);
	build(mid+1,R,p<<1|1);
	sum[p]=Merge(sum[p<<1],sum[p<<1|1]);
//	if(p==6) cerr<<sum[p<<1|1].Nxt[4][4]<<endl;
}
Mat Query(int L,int R,int p,int l,int r) {
	if(L==l&&R==r) return sum[p];
	int mid=L+R>>1;
	if(r<=mid) return Query(L,mid,p<<1,l,r);
	else if(l>mid) return Query(mid+1,R,p<<1|1,l,r);
	else return Merge(Query(L,mid,p<<1,l,mid),Query(mid+1,R,p<<1|1,mid+1,r));
}
int main() {
	int n,m;
	scanf("%d%d%s",&n,&m,str+1);
	build(1,n,1);
//	cerr<<sum[6].Nxt[3][3]<<endl;
//	cerr<<sum[1].Nxt[0][4]<<endl;
	FOR(i,1,m) {
		int l,r;
		scanf("%d%d",&l,&r);
		Mat res=Query(1,n,1,l,r);
		printf("%d\n",res.Nxt[0][4]==INF?-1:res.Nxt[0][4]);
	}
	return 0;
}