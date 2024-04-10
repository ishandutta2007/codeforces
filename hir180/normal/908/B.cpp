#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
string f[55],txt;
int main(){
	cin>>n>>m;
	rep(i,n) cin>>f[i];
	cin>>txt;
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	int p[4]={0,1,2,3};
	int ans = 0;
	do{
		int cx,cy;
		rep(i,n)rep(j,m)if(f[i][j]=='S')cx=i,cy=j;
		bool ok = 0;
		rep(i,txt.size()){
			int s = txt[i]-'0';
			int go = p[s];
			cx += dx[go];
			cy += dy[go];
			if(0<=cx&&cx<n&&0<=cy&&cy<m&&f[cx][cy]!='#'){
				if(f[cx][cy]=='E')ok=1;
			}
			else break;
		}
		if(ok) ans++;
	}while(next_permutation(p,p+4));
	cout<<ans<<endl;
}