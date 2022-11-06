#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 100010
#define M 20000000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,k,tot,a[M],Ls[M],Rs[M];ll ans;
map<int,int>s;
struct pr{int x,y,z;}c[N];

bool cmp(pr x,pr y){return x.y>y.y;}
void f2(int x,int y,int L,int R){
	a[x]++;if((y==L)&&(y==R))return;int rr=(L+R)/2;
	if(y<=rr){
		if(!Ls[x])Ls[x]=++tot;
		f2(Ls[x],y,L,rr);
	}else{
		if(!Rs[x])Rs[x]=++tot;
		f2(Rs[x],y,rr+1,R);
	}
}
void f1(int y,int z){
	if(!s.count(y))s[y]=++tot;
	f2(s[y],z,0,inf);
}
int q2(int x,int l,int r,int L,int R){
	if((l==L)&&(r==R))return a[x];int rr=(L+R)/2;
	if(r<=rr){
		if(Ls[x])return q2(Ls[x],l,r,L,rr);else return 0;
	}else if(l>rr){
		if(Rs[x])return q2(Rs[x],l,r,rr+1,R);else return 0;
	}else{
		int x1=0,x2=0;
		if(Ls[x])x1=q2(Ls[x],l,rr,L,rr);
		if(Rs[x])x2=q2(Rs[x],rr+1,r,rr+1,R);return x1+x2;
	}
}
int q1(int l,int r,int l1,int r1){int x=0;
	rep(i,l,r)if(s.count(i))x+=q2(s[i],l1,r1,0,inf);return x;
}
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d%d%d",&c[i].x,&c[i].y,&c[i].z);
	sort(c+1,c+n+1,cmp);
	rep(i,1,n){
		ans+=q1(max(c[i].z-k,0),min(c[i].z+k,inf),
		max(c[i].x-c[i].y,0),min(c[i].x+c[i].y,inf));
		f1(c[i].z,c[i].x);
	}
	printf("%I64d",ans);
}