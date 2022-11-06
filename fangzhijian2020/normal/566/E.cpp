#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int n,m,opt=1,vis[1005],bl[1005],mp[1005][1005];bitset<1005>a[1005],p[1005];
void solve(int x){
	for(int y=1;y<=n;++y){
		if(vis[y]&&mp[x][y])p[x][y]=1;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		m=read();opt&=(m==n);
		for(int j=1;j<=m;++j){
			a[i][read()]=1;
		}
	}
	if(n==2){puts("1 2");return 0;}
	if(opt==1){
		for(int i=2;i<=n;++i){
			cout<<1<<" "<<i<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			bitset<1005>tmp=a[i]&a[j];
			if(tmp.count()==2){
				int x=tmp._Find_first(),y=tmp._Find_next(x);vis[x]=vis[y]=1;
				if(!mp[x][y]){cout<<x<<" "<<y<<"\n";mp[x][y]=mp[y][x]=1;}
			}
		}
	}
	int x=0,y=0;int tot=0;bitset<1005>T;
	for(int i=1;i<=n;++i){
		if(vis[i]){
			++tot;T[i]=1;
			if(!x)x=i;
			else if(!y)y=i;
		}
	}
	if(tot==2){
		for(int i=1;i<=n;++i){
			if(a[i].count()!=n){
				for(int j=1;j<=n;++j){
					if(!vis[j]){
						if(a[i][j])cout<<x<<" "<<j<<"\n";
						else cout<<y<<" "<<j<<"\n";
					}
				}
				break;
			}
		}
	}
	else{
		for(int i=1;i<=n;++i){
			if(vis[i])solve(i),p[i][i]=1;
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]){
				for(int j=1;j<=n;++j){
					if(a[j][i]){
						if(!bl[i]||a[j].count()<a[bl[i]].count())bl[i]=j;
					}
				}
				for(int j=1;j<=n;++j){
					if(vis[j]&&(a[bl[i]]&T)==p[j]){
						cout<<j<<" "<<i<<"\n";break;
					}
				}		
			}
		}
	}
	return 0;
}