#include<iostream> 
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int T,n,m,A,B,a[105][105],tot,h[30];
bool check(int x,int y){
	if(x<1||x>n||y<1||y>m)return 0;
	return 1;
}
int get(int x,int y,int X,int Y){
	for(int i=1;i<=26;++i)h[i]=0;
	for(int i=0;i<4;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(check(nx,ny))h[a[nx][ny]]=1;
		nx=X+dx[i],ny=Y+dy[i];
		if(check(nx,ny))h[a[nx][ny]]=1;		
	}
	for(int i=1;i<=26;++i){
		if(!h[i])return i;
	}
}
int main(){
	T=read()+1;
	while(--T){
		n=read();m=read();A=read();B=n*m/2-A;tot=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				a[i][j]=0;
			}
		}
		if(n&1){
			A-=m/2;
			for(int i=1;i<=m;i+=2){
				a[1][i]=a[1][i+1]=get(1,i,1,i+1);
			}
			if(!(A&1)&&!(B&1)&&A>=0&&B>=0){
				puts("YES");
				for(int i=2;i<=n;i+=2){
					for(int j=1;j<=m;j+=2){
						if(A>0){
							A-=2;
							a[i][j]=a[i][j+1]=get(i,j,i,j+1);
							a[i+1][j]=a[i+1][j+1]=get(i+1,j,i+1,j+1);
						}
						else{
							B-=2;
							a[i][j]=a[i+1][j]=get(i,j,i+1,j);
							a[i][j+1]=a[i+1][j+1]=get(i,j+1,i+1,j+1);
						}
					}
				}
				for(int i=1;i<=n;++i){
					for(int j=1;j<=m;++j){
						cout<<char(a[i][j]+'a'-1);
					}
					puts("");
				}
			}
			else puts("NO");
		}
		if(m&1){
			B-=n/2;
			for(int i=1;i<=n;i+=2){
				a[i][1]=a[i+1][1]=get(i,1,i+1,1);
			}
			if(!(A&1)&&!(B&1)&&A>=0&&B>=0){
				puts("YES");
				for(int i=1;i<=n;i+=2){
					for(int j=2;j<=m;j+=2){
						if(A>0){
							A-=2;
							a[i][j]=a[i][j+1]=get(i,j,i,j+1);
							a[i+1][j]=a[i+1][j+1]=get(i+1,j,i+1,j+1);
						}
						else{
							B-=2;
							a[i][j]=a[i+1][j]=get(i,j,i+1,j);
							a[i][j+1]=a[i+1][j+1]=get(i,j+1,i+1,j+1);
						}
					}
				}
				for(int i=1;i<=n;++i){
					for(int j=1;j<=m;++j){
						cout<<char(a[i][j]+'a'-1);
					}
					puts("");
				}
			}
			else puts("NO");
		}
		if(!(n&1)&&!(m&1)){
			if(!(A&1)&&!(B&1)&&A>=0&&B>=0){
				puts("YES");
				for(int i=1;i<=n;i+=2){
					for(int j=1;j<=m;j+=2){
						if(A>0){
							A-=2;
							a[i][j]=a[i][j+1]=get(i,j,i,j+1);
							a[i+1][j]=a[i+1][j+1]=get(i+1,j,i+1,j+1);
						}
						else{
							B-=2;
							a[i][j]=a[i+1][j]=get(i,j,i+1,j);
							a[i][j+1]=a[i+1][j+1]=get(i,j+1,i+1,j+1);
						}
					}
				}
				for(int i=1;i<=n;++i){
					for(int j=1;j<=m;++j){
						cout<<char(a[i][j]+'a'-1);
					}
					puts("");
				}
			}
			else puts("NO");
		}
	}
	return 0;
}