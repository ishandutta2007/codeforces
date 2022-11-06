#include<bits/stdc++.h>
#define ll long long
#define INF 1e9
#define M 222
#define N 73
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Onfo{int di,x,y;};
struct Info{int nu,ne,qu;}a[M*2];
int fa[N],m,n,X,Y,x,y,z,num,b[N],si[N],bi[N],di[N][400010],an[N];
int que(int x){if (fa[x]!=x)fa[x]=que(fa[x]);return fa[x];}
void jb(int x,int y,int z){a[++num].nu=y;a[num].ne=b[x];b[x]=num;a[num].qu=z;}
priority_queue<Onfo> s;
bool operator <(Onfo x,Onfo y){return x.di>y.di;}
int qi(int x){if (bi[x]==0)return 0;return (1<<(bi[x]-1));}
int main(){
	read(n);read(m);read(X);read(Y);
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=m;i++){
		read(x);read(y);read(z);
		if (z==X){
			int nx=que(x),ny=que(y);
			if(nx!=ny)fa[nx]=ny;
		}
		jb(x,y,z);jb(y,x,z);
	}
	num=0;
	for (int i=1;i<=n;i++){que(i);si[fa[i]]++;}
	for (int i=1;i<=n;i++){
		if (si[i]>=4){
			num++;
			for (int j=1;j<=n;j++)if(fa[j]==i)bi[j]=num;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<(1<<num);j++)di[i][j]=INF;
	di[1][qi(1)]=0;
	s.push((Onfo){0,1,qi(1)});
	while (!s.empty()){
		Onfo nx=s.top();s.pop();
		int x=nx.x,be=nx.y;
		if (di[x][be]==nx.di){
			for (int y=b[x];y;y=a[y].ne){
				if (a[y].qu==X){
					if (di[a[y].nu][be]>di[x][be]+a[y].qu){
						di[a[y].nu][be]=di[x][be]+a[y].qu;
						s.push((Onfo){di[a[y].nu][be],a[y].nu,be});
					}
				}else{
					if ((be&qi(a[y].nu))==0&&fa[a[y].nu]!=fa[x]){
						if (di[a[y].nu][be+qi(a[y].nu)]>di[x][be]+a[y].qu){
							di[a[y].nu][be+qi(a[y].nu)]=di[x][be]+a[y].qu;
							s.push((Onfo){di[a[y].nu][be+qi(a[y].nu)],a[y].nu,be+qi(a[y].nu)});
						}	
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		an[i]=INF;
		for (int j=0;j<(1<<num);j++)an[i]=min(an[i],di[i][j]);
		cout<<an[i]<<' ';
	}
	return 0;
}