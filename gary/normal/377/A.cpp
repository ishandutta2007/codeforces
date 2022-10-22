//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m;
int k;
char maze[505][505];
int v[505][505];
int X[4]={0,0,1,-1},Y[4]={1,-1,0,0};
void dfs(int x,int y){
//	cout<<x<<" "<<y<<endl;
	if(v[x][y]||x<=0||x>n||y<=0||y>m) return;
	v[x][y]=1;
	if(!k) return;
	rb(i,0,3){
		if(!v[x+X[i]][y+Y[i]]){
			dfs(x+X[i],y+Y[i]);
		}
	}
	if(k){
		k--;
		maze[x][y]='X';
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	rb(i,1,n)
		rb(j,1,m)
			cin>>maze[i][j],v[i][j]=(maze[i][j]=='#')? 1:0;
	rb(i,1,n){
		rb(j,1,m){
			if(maze[i][j]=='.'){
				dfs(i,j);
				break;
			}
		}
	}
	rb(i,1,n)
	{
		rb(j,1,m){
			cout<<maze[i][j];
		}
		cout<<endl;
	}
	return 0;
}