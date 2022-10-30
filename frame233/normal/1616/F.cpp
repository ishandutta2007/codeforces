#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=67,M=259;typedef std::pair<int,int> pi;
int mp[N][N],id[N][N],t[M],d[M],a[8193][M],e[8193];
void MAIN(){
	memset(mp,0,sizeof(mp)),memset(id,0,sizeof(id)),memset(d,0,sizeof(d)),memset(a,0,sizeof(a));
	int n,m;read(n,m);int c=0;
	for(int i=1,x,y,z;i<=m;++i){
		read(x,y,z),mp[x][y]=z,mp[y][x]=z;
		if(z==-1)id[x][y]=id[y][x]=++c,t[c]=i;
		else d[i]=z-1;
	}
	int p=0,C=c;
	for(int a=1;a<=n;++a)for(int b=a+1;b<=n;++b)for(int c=b+1;c<=n;++c)if(mp[a][b]&&mp[b][c]&&mp[a][c]){
		int s=0;
		if(mp[a][b]>0)s-=mp[a][b]-1;
		if(mp[a][c]>0)s-=mp[a][c]-1;
		if(mp[b][c]>0)s-=mp[b][c]-1;
		s=(s%3+3)%3,++p;
		if(mp[a][b]==-1)::a[p][id[a][b]]=1;
		if(mp[b][c]==-1)::a[p][id[b][c]]=1;
		if(mp[a][c]==-1)::a[p][id[a][c]]=1;
		::a[p][C+1]=s;
	}
	int cur=0;
	for(int i=1;i<=c;++i){
		for(int j=cur+1;j<=p;++j)if(a[j][i]){std::swap(a[j],a[cur+1]);break;}
		if(!a[cur+1][i])continue;
		++cur,e[cur]=i;for(int j=c+1;j>=i;--j)a[cur][j]=a[cur][j]*a[cur][i]%3;
		for(int j=cur+1;j<=p;++j)if(a[j][i]){
			for(int k=c+1;k>=i;--k){
				a[j][k]=(a[j][k]+(3-a[j][i])*a[cur][k])%3;
			}
		}
	}
	for(int i=cur+1;i<=p;++i)if(a[i][c+1])return puts("-1"),void();
	for(int i=cur;i>=1;--i)for(int j=1;j<i;++j)if(a[j][e[i]])a[j][c+1]=(a[j][c+1]+(3-a[j][e[i]])*a[i][c+1])%3;
	for(int i=1;i<=cur;++i)d[t[e[i]]]=a[i][c+1];
	for(int i=1;i<=m;++i)printf("%d%c",d[i]+1," \n"[i==m]);
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}