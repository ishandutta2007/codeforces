//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int v[101][101],col[101][101],n;
int _x[8]={-1,-2,-2,-1,1,2,2,1},_y[8]={-2,-1,1,2,-2,-1,1,2};
void  dfs(int color,int x,int y){
//	cout<<x<<" "<<y<<endl;
	if(x>n||y>n||x<1||y<1) return;
	
	if(v[x][y]) return ;
	v[x][y]=1;//cout<<x<<" "<<y<<endl;
	col[x][y]=color;
	rep(i,8)
		dfs(color^1,x+_x[i],y+_y[i]);
}
int main(){
	cin>>n;
	rb(i,1,n)
		rb(j,1,n) {
//			cout<<endl;
		if(!v[i][j]) dfs(1,i,j);
		}
	rb(i,1,n)
	{
		rb(j,1,n){
			if(col[i][j]==1) cout<<"B";
			else cout<<"W";
		}
		cout<<endl;
	}
	
	return 0;
}