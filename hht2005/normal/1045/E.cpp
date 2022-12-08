#include<bits/stdc++.h>
using namespace std;
const int N=3010;
using ll=long long;
using VI=vector<int>;
struct Point{
	ll x,y;
	int id,c;
	Point(){}
	Point(ll X,ll Y) {
		x=X,y=Y;
	}
	int operator<(const Point &a)const {
		return x==a.x?y<a.y:x<a.x;
	}
	Point operator-(const Point &a)const {
		return Point(x-a.x,y-a.y);
	}
	ll operator*(const Point &a)const {
		return x*a.y-y*a.x;
	}
}a[N],p[N],sk[N];
int f[N];
int get(int n) {
	sort(p+1,p+n+1);
	int top=0;
	for(int i=1;i<=n;i++) {
		while(top>1&&(p[i]-sk[top])*(sk[top]-sk[top-1])<=0)top--;
		sk[++top]=p[i];
	}
	int cnt=top;
	for(int i=n-1;i>=1;i--) {
		while(top>cnt&&(p[i]-sk[top])*(sk[top]-sk[top-1])<=0)top--;
		sk[++top]=p[i];
	}
	return top-1;
}
ll area(int n) {
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans+=sk[i]*sk[i+1];
	return abs(ans);
}
int A[N],B[N],pos[2][N],tot;
void add(int x,int y,int c) {
	assert(a[x].c==a[y].c); 
	if(c==0)printf("%d %d\n",x-1,y-1);
	else A[++tot]=x,B[tot]=y;
}
int in(int x,int y,int z,int w) {
	sk[1]=p[1]=a[x];
	sk[2]=p[2]=a[y];
	sk[3]=p[3]=a[z];
	p[4]=a[w];
	sk[4]=sk[1];
	ll t=area(3);
	return t==area(get(4));
}
void solve(int x,int y,int z,const VI &pos);
void fen(int x,int y,int z,VI pos) {
	VI p;
	for(int i:pos)
		if(i!=z&&in(x,y,z,i))
			p.push_back(i);
	solve(x,y,z,p);
}
void solve(int x,int y,int z,const VI &pos) {
	int c=(a[x].c+a[y].c+a[z].c-1)^1,w=0;
	if(a[x].c==c)swap(x,z);
	if(a[y].c==c)swap(y,z);
	for(int i:pos)
		if(a[i].c==c) {
			w=i;
			break;
		}
	if(w==0) {
		for(int i:pos) {
			add(x,i,c^1);
		}
		return;
	}
	add(z,w,c);
	fen(x,y,w,pos);
	fen(x,z,w,pos);
	fen(z,y,w,pos);
}
int main() {
	int n,F=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld%d",&a[i].x,&a[i].y,&a[i].c);
		F|=a[i].c+1;
		a[i].id=i;
		p[i]=a[i];
	}
	int M=get(n),FL=0,cnt[2]={0,0};
	for(int i=1;i<=M;i++) {
		FL+=sk[i].c!=sk[i+1].c;
		f[sk[i].id]=1;
	}
	if(FL>2) {
		puts("Impossible");
		return 0;
	}
	printf("%d\n",n-(F&1)-(F>>1));
	FL=0;
	for(int i=2;i<=M;i++) {
		if(sk[i].c!=sk[i-1].c)FL=1;
		if(FL)pos[sk[i].c][++cnt[sk[i].c]]=sk[i].id;
	}
	for(int i=1;i<=M;i++) {
		if(i!=1&&sk[i].c!=sk[i-1].c)break;
		pos[sk[i].c][++cnt[sk[i].c]]=sk[i].id;
	}
	for(int i=1;i<cnt[0];i++)
		add(pos[0][i],pos[0][i+1],0);
	for(int i=1;i<cnt[1];i++)
		add(pos[1][i],pos[1][i+1],1);
	VI v;
	for(int i=1;i<=n;i++)
		if(!f[i])v.push_back(i);
	if(!cnt[0]||!cnt[1]) {
		int c=!cnt[1],w=0;
		for(int i:v)
			if(a[i].c==c) {
				w=i;
				break;
			}
		pos[c^1][cnt[c^1]+1]=pos[c^1][1];
		for(int i=1;i<=cnt[c^1];i++)
			fen(pos[c^1][i],pos[c^1][i+1],w,v);
	} else {
		for(int i=1;i<cnt[0];i++)
			fen(pos[1][1],pos[0][i],pos[0][i+1],v);
		for(int i=1;i<cnt[1];i++)
			fen(pos[0][1],pos[1][i],pos[1][i+1],v);
	}
	for(int i=1;i<=tot;i++)
		printf("%d %d\n",A[i]-1,B[i]-1);
	return 0;
}