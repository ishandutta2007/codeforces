#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
int adj[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int p[4]={0,1,2,3};
char g[51][51];
string s;
int sx,sy,ex,ey;
bool ingrid(int x,int y){
	return (x>=1 && x<=n && y>=1 && y<=m && g[x][y]!='#');
}
bool check(){
	int curx=sx,cury=sy;
	bool out=(p[0]==0 && p[2]==1 && p[3]==2 && p[1]==3);
	for(int i=0; i<s.size() ;i++){
		curx+=adj[p[s[i]-48]][0];
		cury+=adj[p[s[i]-48]][1];
		if(!ingrid(curx,cury)) return false;
		if(curx==ex && cury==ey) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> g[i][j];
			if(g[i][j]=='S') sx=i,sy=j;
			if(g[i][j]=='E') ex=i,ey=j;
		}
	}
	cin >> s;
	int ans=0;
	do{
		if(check()) ans++;
	}while(next_permutation(p,p+4));
	cout << ans << endl;
}