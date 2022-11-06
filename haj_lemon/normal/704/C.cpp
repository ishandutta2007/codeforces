#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mr make_pair
#define fi first
#define se second
#define N 100010
#define mo 1000000007
using namespace std;
struct Info{int k,a,b;}b[N];
vector<pair<int,int> > a[N];
int m,n;
bool vi[N];
ll an[2],dp[N][2][2][2],g[2][2],as[N][2][2],gs=1;
void jb(int x,int y,int z){a[x].pb(mr(y,z));if (x!=y)a[y].pb(mr(x,z));}
void add(ll &x,ll y){x=(x+y)%mo;}
void add(int x,int c,ll y,ll z){
	ll p=as[x][c][0],q=as[x][c][1];
	as[x][c][0]=(p*y+q*z)%mo;as[x][c][1]=(p*z+q*y)%mo;
}
bool ch(int x,int y,int z,int g){
	if (abs(b[z].b)!=g)swap(b[z].a,b[z].b);
	return (((b[z].a<0)^x)|((b[z].b<0)^y));
}
void dfs(int x,int g,int fi){
	vi[x]=0;
	if (g==0){dp[x][0][0][0]=1;dp[x][1][0][1]=1;as[x][0][0]=as[x][1][0]=1;}
	for (auto y:a[x]){
		if(y.fi==x){
			if (b[y.se].a<0){
				swap(dp[x][0][0][0],dp[x][0][1][0]);swap(dp[x][1][0][0],dp[x][1][1][0]);
			}else{
				swap(dp[x][0][0][1],dp[x][0][1][1]);swap(dp[x][1][0][1],dp[x][1][1][1]);
			}
		}
	}
	int ne=1;
	for (auto y:a[x]){
		if (y.se!=g&&y.fi!=x){
			if (x==fi&&!vi[y.fi])continue;
			if (y.fi==fi){
				for (int i=0;i<=1;i++){
					ll p=0,q=0;
					for (int j=0;j<=1;j++)
						for (int k=0;k<=1;k++)
							if (k^ch(i,j,y.se,x))add(q,dp[x][i][k][j]);else add(p,dp[x][i][k][j]);
					add(fi,i,p,q);
				}
				ne=0;
			}else{
				for (int i=0;i<=1;i++)
					for (int j=0;j<=1;j++)
						for (int k=0;k<=1;k++)
							for (int ne=0;ne<=1;ne++)
								add(dp[y.fi][i][j^ch(k,ne,y.se,y.fi)][ne],dp[x][i][j][k]);
				ne=0;
				dfs(y.fi,y.se,fi);
			}
		}
	}
	if (ne){
		for (int j=0;j<=1;j++){
			ll p=0,q=0;
			for (int k=0;k<=1;k++)add(p,dp[x][j][0][k]),add(q,dp[x][j][1][k]);
			add(fi,j,p,q);
		}
	}
	if (x==fi){add(0,0,as[x][0][0]+as[x][1][0],as[x][0][1]+as[x][1][1]);}
}
int main(){
	cin>>m>>n;
	for (int i=1;i<=n;i++)vi[i]=1;
	for (int i=1;i<=m;i++){
		cin>>b[i].k>>b[i].a;
		if (b[i].k==2)cin>>b[i].b;else b[i].b=b[i].a;
		if (b[i].a==-b[i].b)gs^=1;
		else jb(abs(b[i].a),abs(b[i].b),i);
	}
	as[0][0][0]=1;
	for (int i=1;i<=n;i++)if (vi[i])dfs(i,0,i);
	cout<<as[0][0][gs]<<endl;
	return 0;
}