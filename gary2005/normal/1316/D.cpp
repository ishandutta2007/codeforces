/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
mp a[1001][1001];
char res[1002][1001];
bool vis[1002][1002];
vector<mp> is;
int n;
bool check(int x,int y){
	if(x<0||y<0) return 0;
	if(x>n||y>n) return 0;
	if(vis[x][y]) return 0;
	return 1;
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		rb(j,1,n)
			cin>>a[i][j].FIR>>a[i][j].SEC;
	rb(i,1,n)
		rb(j,1,n)
	if(a[i][j].FIR==i&&a[i][j].SEC==j){
		is.PB(II(i,j));
		vis[i][j]=1;
		res[i][j]='X';
	}
	int walk[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	char OO[4]={'U','D','L','R'};
	while(!is.empty()){
		mp now=is[is.size()-1];
		is.POB();
		rep(i,4)
		
		{
			int x,y;
			x=now.FIR+walk[i][0];
			y=now.SEC+walk[i][1];
			if(check(x,y)&&a[x][y]==a[now.FIR][now.SEC]){
				vis[x][y]=1;
				res[x][y]=OO[i];
				is.PB(II(x,y));
			}
			}	
	}
	rb(i,1,n)
		rb(j,1,n)
			if(!vis[i][j]){
				if(a[i][j].FIR<0)
				{
					bool ok=0;
					rep(k,4){
						int x,y;
						x=i+walk[k][0];
						y=j+walk[k][1];
						if(x>=1&&x<=n&&y>=1&&y<=n)
						{
							if(a[x][y].FIR<0){
								ok=1;
								res[i][j]=OO[k^1];
								break;
							}
						 } 
					}
					if(!ok)
					{
						cout<<"INVALID"<<endl;
						return 0;
					}
				}
				else{
//					cout<<i<<" "<<j<<endl;
					cout<<"INVALID"<<endl;
					return 0;
				}
				
			}
				
	cout<<"VALID"<<endl;
	rb(i,1,n)
		rb(j,1,n)
		{
			cout<<res[i][j];
			if(j==n) cout<<endl;
		 } 
	return 0;
}