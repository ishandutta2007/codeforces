#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
int n,k,q;
int t[100005],x[100005],y[100005],a[16][100005];
int c[110005],L[110005],R[110005],C,pos[100005];
bool xx[4096][100105];
int main(){
	cin>>n>>k>>q;
	rep(j,k)rep(i,n){
		scanf("%d",&a[j][i]);
	}
	C = k;
	rep(i,q){
		scanf("%d%d%d",&t[i],&x[i],&y[i]);x[i]--;y[i]--;
		if(t[i] != 3){
			c[C] = t[i];
			L[C] = x[i];
			R[C] = y[i];
			C++;
		}
		//else pos[i] = C;
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=0;j<k;j++) xx[i][j] = (((i>>j)&1));
		for(int j=k;j<C;j++){
			if(c[j] == 1){
				xx[i][j] = xx[i][L[j]] | xx[i][R[j]];
			}
			else{
				xx[i][j] = xx[i][L[j]] & xx[i][R[j]];
			}
			//cout<<xx[i][j]<<" "<<i<<" "<<j<<endl;
		}
	}
	//cout<<xx[3][4]<<endl;
	rep(i,q){
		//scanf("%d%d%d",&t[i],&x[i],&y[i]);
		if(t[i] != 3) continue;
		vector<int>vi;
		rep(j,k) vi.pb(a[j][y[i]]);
		SORT(vi); ERASE(vi);//cout<<vi.size()<<endl;
		for(int jj=vi.size()-1;jj>=0;jj--){
			int mask = 0;
			rep(j,k){
				if(vi[jj] <= a[j][y[i]]) mask += (1<<j);
			}
		//	cout<<mask<<endl;
			bool u = xx[mask][x[i]]; //cout<<u<<endl;
			if(u == 1){
				cout<<vi[jj]<<endl; break;
			}
		}
	}
}