#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=3e2+1;
int T,n,k;
char a[N][N],b[N][N],st[]="XO";
V input(){
	scanf("%d",&n),k=0;
	FOR(i,1,n)scanf("%s",a[i]+1);
	FOR(i,1,n)FOR(j,1,n)k+=a[i][j]!='.';
}
I add(char&x,char y){return(x!=y)&&(x=y);}
V init(){FOR(i,1,n)FOR(j,1,n)b[i][j]=a[i][j];}
V output(){FOR(i,1,n)cout<<b[i]+1<<'\n',memset(b[i]+1,0,n);}
V work(int now=0){
	FOR(d,0,2){
		init(),now=0;
		FOR(i,1,n)FOR(j,1,n)if(a[i][j]!='.'){
			if((i+j+d)%3==0)now+=add(b[i][j],st[0]);
			if((i+j+d)%3==1)now+=add(b[i][j],st[1]);
		}
		if(now<=k/3)return output();
	}
	swap(st[0],st[1]);
	FOR(d,0,2){
		init(),now=0;
		FOR(i,1,n)FOR(j,1,n)if(a[i][j]!='.'){
			if((i+j+d)%3==0)now+=add(b[i][j],st[0]);
			if((i+j+d)%3==1)now+=add(b[i][j],st[1]);
		}
		if(now<=k/3)return output();
	}
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	for(scanf("%d",&T);T--;){
		input();
		work();
	}
	return 0;
}