#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re// register
#define I inline int
#define V inline void
#define B inline bool
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	static const int flag[2]={1,-1};
	rnt _s=0,_f=1;re char _ch=gc;
	while(!isnum(_ch))_f=flag[_ch=='-'],_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
I max(const int&x,const int&y){return x>y?x:y;}
I min(const int&x,const int&y){return x<y?x:y;}
const int N=1e6+2,mod=998244353;
int n,m;
char*a[N],*b[N];
int*t[N],*d[N];
V input(){
	scanf("%d%d",&n,&m);
	FOR(i,0,n+1){
		a[i]=new char[m+3];
		d[i]=new int[m+3];
		t[i]=new int[m+3];
		b[i]=new char[m+3];
	}
	FOR(i,1,n)scanf("%s",a[i]+1);
	FOR(i,0,n+1)a[i][0]=a[i][m+1]='.';
	FOR(i,0,m+1)a[0][i]=a[n+1][i]='.';
}
V init(){
	FOR(i,1,n)FOR(j,1,m)t[i][j]=-1;
}
struct node{
	int x,y;
	B good(){return x>0&&y>0&&x<=n&&y<=m;}
};
queue<node>q;
node mk(rnt x,rnt y){
	return (node){x,y};
}
const int dx[8]={0,0,1,1,1,-1,-1,-1};
const int dy[8]={1,-1,-1,0,1,-1,0,1};
V bfs(){
	init();
	FOR(i,0,n+1)FOR(j,0,m+1)
		if(a[i][j]=='.')
			q.push(mk(i,j)),d[i][j]=0,t[i][j]=0;
	for(node u;!q.empty();){
		u=q.front(),q.pop();
		FOR(i,0,7){
			rnt x=u.x+dx[i],y=u.y+dy[i];
			if(x==1&&y==1){
				x++;
				x--;
			}
			if(!mk(x,y).good())
				continue;
			if(!~t[x][y])
				d[x][y]=d[u.x][u.y]+1,t[x][y]=0,q.push(mk(x,y));
		}
	}
}
V output(int**x){FOR(i,1,n)FOR(j,1,m)cout<<x[i][j]<<" \n"[j==m];}
B check(rnt lim){
	init();
	FOR(i,1,n)FOR(j,1,m)
		if(d[i][j]>lim)
			t[i][j]=0,q.push(mk(i,j));
	for(node u;!q.empty();){
		u=q.front(),q.pop();
		if(!u.good()||t[u.x][u.y]==lim)
			continue;
		FOR(i,0,7){
			rnt x=u.x+dx[i],y=u.y+dy[i];
			if(!~t[x][y]){
				if(a[x][y]=='.')return false;
				t[x][y]=t[u.x][u.y]+1,q.push(mk(x,y));
			}
		}
	}
	FOR(i,1,n)FOR(j,1,m)if(!~t[i][j]&&a[i][j]=='X')
		return false;
	return true;
}
V work(){
	bfs();
//	output(d);
	rnt l=0,r=min(n,m),mid;
	while(mid=l+r>>1,l^r)
		if(check(mid+1))l=mid+1;
		else r=mid;
	cout<<mid<<'\n';
	FOR(i,1,n){
		FOR(j,1,m)
			cout<<".X"[d[i][j]>mid];
		cout<<'\n';
	}
}
int main(){
//	freopen("test.in","r",stdin);
	input();
	work();
	return 0;
}