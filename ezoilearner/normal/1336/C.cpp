#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define per(i,a,b) for(register int i=(a);i>=(b);--i)

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


const int Mod=998244353;
const int I2=499122177;
namespace modular{
	int dec(int a,int b){return a-b<0?a-b+Mod:a-b;}
	int add(int a,int b){return a+b>=Mod?a+b-Mod:a+b;}
	int mul(int a,int b){return 1ll*a*b%Mod;} 
	int Fast_Pow(int a,int b){
		int res=1;
		while(b){
			if(b&1)res=1ll*res*a%Mod;
			b>>=1;
			a=1ll*a*a%Mod; 
		}
		return res;
	}
	void Add(int &a,int b){a=a+b>=Mod?a+b-Mod:a+b;}
}using namespace modular;

int n,m;
#define Maxn 3005
char S[Maxn],T[Maxn];
int ans[Maxn];

int F[Maxn][Maxn];
void calc2(){
	//right
	rep(i,2,m)F[0][i]=1;
	rep(i,0,n-1){
		rep(j,1,m+1){
			int l=j,r=min(j+i-1,m),t=F[i][j];
			if(l>1){
				if(S[i+1]==T[l-1])Add(F[i+1][l-1],t);
			}
			if(r==m)Add(F[i+1][l],t);
			else{
				if(S[i+1]==T[r+1])Add(F[i+1][l],t);
			}
		}
		if(i+1>=m)ans[i+1]=F[i+1][1];
	}
}

void calc1(){
	bool fl=true;
	rep(i,1,m)
		if(S[i]!=T[i])fl=false;
	if(!fl)return;
	rep(i,m,n){
		ans[i]=add(ans[i],1);
	}
}

int g[Maxn][Maxn];
void calc3(){
	g[0][m+1]=1;
	rep(i,0,n-1){
		rep(j,1,m+1)Add(g[i+1][j],g[i][j]);
		rep(j,1,m+1){
			int t=g[i][j];
			if(j==m+1)Add(g[i+1][j],g[i][j]);
			if(j>1&&T[j-1]==S[i+1])Add(g[i+1][j-1],t); 
		}
		Add(ans[i+1],g[i+1][1]);
	}
}

int main(){
	scanf("%s",S+1);scanf("%s",T+1);
	n=strlen(S+1);m=strlen(T+1);
	calc2();
	calc1();
	calc3();
	int Ans=0;
	rep(i,1,n)Ans=add(Ans,ans[i]);
	printf("%d\n",Ans);
	return 0; 
}