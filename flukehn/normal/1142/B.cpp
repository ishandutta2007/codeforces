#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_end=(a);i>=i##_end;--i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define foe(i,a) for(__typeof(a.begin())i=a.begin();i!=a.end();++i)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
typedef double ld;
typedef long long L;
typedef vector<int> VI;
typedef pair<int,int> pa;
const int N=2e5+11,M=22;
int f[N][M];
int las[N],p[N],pr[N],a[N];
int an[N];

int main(){
	ios::sync_with_stdio(0);
	int n,m,q;
	cin>>n>>m>>q;
	rep(i,1,n)cin>>p[i];
	rep(i,1,n){
		int x=p[i];
		pr[x]=i>1?p[i-1]:p[n];
	}
	rep(i,1,m){
		int x;
		cin>>x;
		f[i][0]=las[pr[x]];
		For(j,1,M)f[i][j]=f[f[i][j-1]][j-1];
		int o=i;
		per(j,0,M-1)if(n-1>>j&1)o=f[o][j];
		an[i]=max(an[i-1],o);
		//cerr<<f[i][0]<<" \n"[i==m];
		las[x]=i;
	}
	rep(i,1,q){
		int l,r;
		cin>>l>>r;
		putchar(an[r]>=l?'1':'0');
	}

}