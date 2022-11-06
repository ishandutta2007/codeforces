#include<bits/stdc++.h>
#define N 100200
#define M 20200
#define ul unsigned long long
#define ma 313
using namespace std;
struct Info{int nu,ne;}a[N*2];
struct tri{int x,y,z;};
struct bitse{ul a[322];}da[M],xi[210],v1,v2;
bitse operator |(bitse x,bitse y){for (int i=0;i<=ma;i++)x.a[i]|=y.a[i];return x;}
bitse operator &(bitse x,bitse y){for (int i=0;i<=ma;i++)x.a[i]&=y.a[i];return x;}
void fu(bitse &x,int y){x.a[(y-1)>>6]^=(1ull<<((y-1)&63));}
bool que(bitse &x,int y){return (x.a[(y-1)>>6]&(1ull<<((y-1)&63)));}
int b[N],num,n,x,y,m,d[N],f[N][21],dp[N],bi[N],so[N],en[M],nu,an[M];
vector<int> g[N],no;
set<int> s[210];
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;}
void dfs(int x,int fa,int dep){
	d[x]=dep;f[x][0]=fa;
	for (int y=b[x];y;y=a[y].ne)if (a[y].nu!=fa)dfs(a[y].nu,x,dep+1);
}
int lca(int x,int y){
	for (int i=19;i>=0;i--) if (d[f[x][i]]>=d[y]) x=f[x][i];
	for (int i=19;i>=0;i--) if (f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	if (x==y) return x;return f[x][0];
}
int fa(int x,int y){for (int i=19;i>=0;i--)if (y&(1<<i))x=f[x][i];return x;}
void gdp(int x){
	dp[x]=0;
	for (unsigned i=0;i<g[x].size();i++)if (g[x][i]>0)dp[x]++;
	for (int y=b[x];y;y=a[y].ne){
		if (a[y].nu!=f[x][0]){
			gdp(a[y].nu);dp[x]+=dp[a[y].nu];
			if (dp[a[y].nu]>dp[so[x]]) so[x]=a[y].nu;
		}
	}
}
void work(){
	for (int i=2;i<=200;i++) no.push_back(i);bi[1]=1;
	vector<tri> st;
	st.clear();st.push_back((tri){1,b[1],0});
	while (st.size()){
		tri ns=st[st.size()-1];
		int y=ns.y,x=ns.x;
		st.pop_back();
		if (ns.z==0){
			st.push_back((tri){x,y,1});
			if (so[x]!=0){bi[so[x]]=bi[x];st.push_back((tri){so[x],b[so[x]],0});}
		}else{
			while (y!=0&&(a[y].nu==so[x]||a[y].nu==f[x][0]))y=a[y].ne;
			if (y==0){
				for (unsigned i=0;i<g[x].size();i++)
					if (g[x][i]>0){da[g[x][i]]=da[g[x][i]]|xi[bi[x]];s[bi[x]].insert(g[x][i]);fu(xi[bi[x]],g[x][i]);}
				for (unsigned i=0;i<g[x].size();i++)
					if (g[x][i]<0){s[bi[x]].erase(-g[x][i]);fu(xi[bi[x]],-g[x][i]);}
			}else{
				if (ns.z==1){
					bi[a[y].nu]=no[no.size()-1];no.pop_back();
					st.push_back((tri){x,y,2});st.push_back((tri){a[y].nu,b[a[y].nu],0});
				}else{
					for (auto i=s[bi[a[y].nu]].begin();i!=s[bi[a[y].nu]].end();i++){da[*i]=da[*i]|xi[bi[x]];s[bi[x]].insert(*i);fu(xi[bi[a[y].nu]],*i);fu(xi[bi[x]],*i);}
					s[bi[a[y].nu]].clear();no.push_back(bi[a[y].nu]);
					y=a[y].ne;
					st.push_back((tri){x,y,1});
				}
			}
		}
	}
}
vector<ul> zh(vector<ul> a){
	for (int i=1;i<64;i<<=1){
		ul n1=0;n1--;
		n1=n1/((1ull<<i)+1);
		for (int j=0;j<64;j+=i*2){
			for (int k=0;k<i;k++){
				ul n2=a[j+k+i]&n1,n3=a[j+k]&(n1<<i);
				a[j+k+i]-=n2;a[j+k]-=n3;
				a[j+k+i]+=(n3>>i);a[j+k]+=(n2<<i);
			}
		}
	}
	return a;
}
int pa(int x){if (x%2==1) return x+1;return x-1;}
void dfs1(int x){
	fu(v1,pa(x));
	for (int i=0;i<=ma;i++){
		if ((v1.a[i]|da[x].a[i])!=v1.a[i])
			for (int j=0;j<64;j++)
				if (((v1.a[i]&(1ull<<j))==0)&&((da[x].a[i]&(1ull<<j))!=0))dfs1(pa(i*64+j+1));
	}
	en[++num]=x;
}
void dfs2(int x){
	an[x]=nu;
	fu(v2,x);x=pa(x);
	for (int i=0;i<=ma;i++){
		if ((v2.a[i]|da[x].a[i])!=v2.a[i])
			for (int j=0;j<64;j++)
				if ((v2.a[i]&(1ull<<j))==0&&(da[x].a[i]&(1ull<<j))!=0)dfs2(i*64+j+1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){scanf("%d %d",&x,&y);jb(x,y);jb(y,x);}
	dfs(1,0,1);
	for (int i=2,j=1;i<=n;i*=2,j++)
		for (int k=1;k<=n;k++)f[k][j]=f[f[k][j-1]][j-1];
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		if (d[x]<d[y])swap(x,y);
		int z=lca(x,y);
		g[x].push_back(i*2-1);
		g[fa(x,d[x]-d[z]-1)].push_back(-(i*2-1));
		if (y!=z){
			g[y].push_back(i*2-1);
			g[fa(y,d[y]-d[z]-1)].push_back(-(i*2-1));
		}
		scanf("%d %d",&x,&y);
		if (d[x]<d[y])swap(x,y);
		z=lca(x,y);
		g[x].push_back(i*2);
		g[fa(x,d[x]-d[z]-1)].push_back(-(i*2));
		if (y!=z){
			g[y].push_back(i*2);
			g[fa(y,d[y]-d[z]-1)].push_back(-(i*2));
		}
	}
	gdp(1);work();
	for (int i=0;i<=ma;i++){
		for (int j=0;j<=ma;j++){
			vector<ul> n1;n1.clear();
			for (int k=1;k<=64;k++)n1.push_back(da[i*64+k].a[j]);
			n1=zh(n1);
			for (int k=1;k<=64;k++)da[j*64+k].a[i]|=n1[k-1];
		}
	}
	num=0;for (int i=1;i<=m*2;i++)if (que(v1,pa(i))==0)dfs1(i);
	for (int i=m*2;i>=1;i--)if (que(v2,en[i])==0){nu++;dfs2(en[i]);}
	for (int i=1;i<=m;i++) if (an[i*2]==an[i*2-1]){puts("NO");return 0;}
	puts("YES");
	for (int i=1;i<=m;i++)if (an[i*2]>an[i*2-1]) puts("2");else puts("1");
	return 0;
}