#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int f[405][405][3][3],tf[405][405][3][3],sumf[405][405];
int g[405][2][2],tg[405][2][2],sumg[405];
int cf[3]={24,1,1};
int mf[3][3]={{23,1,1},{24,0,1},{24,1,0}};
int cg[2]={25,1};
int mg[2][2]={{24,1},{25,0}};
int n,a[26],ans;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
void solve1(int n){
	for (int i=0;i<2;i++)
	for (int j=0;j<2;j++){
        g[(i==1)+(j==1)][i][j]=cg[i]*cg[j];
	}
    for (int _=2;_<n;_++){
		memcpy(tg,g,sizeof(g));
        memset(g,0,sizeof(g));
        for (int i=0;i<=_;i++)
		for (int x=0;x<2;x++)
		for (int y=0;y<2;y++) {
			int res=tg[i][x][y];
			if (!res) continue;
			for (int z=0;z<2;z++)
				add(g[i+(z==1)][y][z],1ll*res*mg[x][z]%M);
		}
    }
    for (int i=0;i<=n;i++)
		for (int x=0;x<2;x++)
			for (int y=0;y<2;y++)
				add(sumg[i],g[i][x][y]);
	for (int i=n;i;i--) add(sumg[i-1],sumg[i]);
}
void solve2(int n){
	for (int i=0;i<3;i++)
	for (int j=0;j<3;j++){
        f[(i==1)+(j==1)][(i==2)+(j==2)][i][j]=cf[i]*cf[j];
	}
    for (int _=2;_<n;_++){
		memcpy(tf,f,sizeof(f));
        memset(f,0,sizeof(f));
        for (int i=0;i<=_;i++)
		for (int j=0;j+i<=_;j++)
		for (int x=0;x<3;x++)
		for (int y=0;y<3;y++) {
			int res=tf[i][j][x][y];
			if (!res) continue;
			for (int z=0;z<3;z++)
				add(f[i+(z==1)][j+(z==2)][y][z],1ll*res*mf[x][z]%M);
		}
    }
    for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int x=0;x<3;x++)
				for (int y=0;y<3;y++)
					add(sumf[i][j],f[i][j][x][y]);
	for (int i=n;i;i--) for (int j=n;j>=0;j--) add(sumf[i-1][j],sumf[i][j]);
	for (int i=n;i>=0;i--) for (int j=n;j;j--) add(sumf[i][j-1],sumf[i][j]);
}
int main(){
	cin >> n;
	for (int i=0;i<26;i++) cin >> a[i];
    solve1(n);
    solve2(n);
    ans=26*26;
    for (int i=2;i<n;i++) ans=1ll*ans*25%M;
    for (int i=0;i<26;i++) sub(ans,sumg[a[i]+1]);
    for (int i=0;i<26;i++)
		for (int j=i+1;j<26;j++)
			add(ans,sumf[a[i]+1][a[j]+1]);
	cout << ans << endl;
	return 0;
}