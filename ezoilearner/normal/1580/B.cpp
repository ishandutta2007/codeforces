#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int n,m,K;
#define Maxn 105
int F[Maxn][Maxn][Maxn];

int Mod;
namespace modular{
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;}
	void ADD(int &a,int b){a=a+b>=Mod?a+b-Mod:a+b;} 
}using namespace modular;

int C[Maxn][Maxn],fact[Maxn];

int main(){
	rd(n);rd(m);rd(K);rd(Mod);
	C[0][0]=1;fact[0]=1;
	rep(i,1,n){
		C[i][0]=1;fact[i]=mul(fact[i-1],i);
		rep(j,1,i)C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	rep(i,0,n)F[0][i][0]=1;
	rep(i,1,n){
		rep(j,1,i){
			int t=C[i-1][j-1];
			rep(k,1,i)
			{
				rep(l1,0,max(0,j-1-k+2))
					if(F[j-1][k-1][l1]){
					rep(l2,0,max(i-j-k+2,0))ADD(F[i][k][l1+l2],mul(t,mul(F[j-1][k-1][l1],F[i-j][k-1][l2])));
				}
			}
		}
		per(j,i,1)F[i][1][j]=F[i][1][j-1];F[i][1][0]=0;
		F[i][0][0]=fact[i];rep(k,i+1,n)F[i][k][0]=fact[i];
	}
	printf("%d\n",F[n][m][K]);
	return 0;
}