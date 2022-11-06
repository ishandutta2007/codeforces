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
const int N=1e5+11,M=255;
char t[N],s[4][M];
int l[4],n,q;
int f[M][M][M];
int nex[N][26];
int nxt(int x,char c){
	if(!c)return n+1;
	return nex[x][c-'a'];
}
int upmn(int &x,int y){return x>y?x=y,1:0;}
int main(){
	ios::sync_with_stdio(0);
	
	cin>>n>>q>>t+1;
	memset(nex,0x3f,sizeof nex);
	For(i,0,M)For(j,0,M)For(k,0,M)f[i][j][k]=n+1;
	f[0][0][0]=0;
	per(i,1,n){
		For(j,0,26)nex[i-1][j]=nex[i][j];
		nex[i-1][t[i]-'a']=i;
	}
	//rep(i,0,n)For(j,0,4)cerr<<nex[i][j]<<" \n"[j==3];
	while(q--){
		char c,o;
		int x;
		cin>>c>>x;
		int p=l[x];
		if(c=='-'){
			if(x==1)rep(i,0,l[2])rep(j,0,l[3])f[p][i][j]=n+1;
			if(x==2)rep(i,0,l[1])rep(j,0,l[3])f[i][p][j]=n+1;
			if(x==3)rep(i,0,l[1])rep(j,0,l[2])f[i][j][p]=n+1;
			s[x][l[x]--]=0;
		}else{
			cin>>o;
			//if(x==3&&o=='a')cerr<<"nmn "<<f[l[1]][l[2]][p]<<endl;
			if(x==1)rep(i,0,l[2])rep(j,0,l[3])upmn(f[p+1][i][j],nxt(f[p][i][j],o)),upmn(f[p+1][i+1][j],nxt(f[p+1][i][j],s[2][i+1])),upmn(f[p+1][i][j+1],nxt(f[p+1][i][j],s[3][j+1]));
			if(x==2)rep(i,0,l[1])rep(j,0,l[3])upmn(f[i][p+1][j],nxt(f[i][p][j],o)),upmn(f[i+1][p+1][j],nxt(f[i][p+1][j],s[1][i+1])),upmn(f[i][p+1][j+1],nxt(f[i][p+1][j],s[3][j+1]));
			if(x==3)rep(i,0,l[1])rep(j,0,l[2])upmn(f[i][j][p+1],nxt(f[i][j][p],o)),upmn(f[i+1][j][p+1],nxt(f[i][j][p+1],s[1][i+1])),upmn(f[i][j+1][p+1],nxt(f[i][j][p+1],s[2][j+1]));
			s[x][++l[x]]=o;
		}
		puts(f[l[1]][l[2]][l[3]]<=n?"YES":"NO");
	}
}