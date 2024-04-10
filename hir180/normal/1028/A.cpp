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
int n,m,a[505][505];

int main(){
	cin>>n>>m;
	repn(i,n){
		string str; cin>>str;
		rep(j,m){
			if(str[j] == 'W') a[i][j+1] = 0;
			else a[i][j+1] = 1;
		}
	}
	repn(i,n){
		repn(j,m){
		    if(a[i][j]==0) continue;
			int aa=0,b=0,c=0,d=0;
			int ii = i, jj = j;
			while(a[ii][jj] == 1 && 1<=ii && ii<=n && 1<=jj && jj<=m) ii++;
			aa = ii-i;
			
			ii = i, jj = j;
			while(a[ii][jj] == 1 && 1<=ii && ii<=n && 1<=jj && jj<=m) ii--;
			b = i-ii;
			
			ii = i, jj = j;
			while(a[ii][jj] == 1 && 1<=ii && ii<=n && 1<=jj && jj<=m) jj++;
			c = jj-j;
			
			ii = i, jj = j;
			while(a[ii][jj] == 1 && 1<=ii && ii<=n && 1<=jj && jj<=m) jj--;
			d = j-jj;
			
			if(aa==b&&b==c&c==d){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
}