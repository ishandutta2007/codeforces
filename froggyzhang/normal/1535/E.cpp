#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int Q,f[N][20],dep[N],a[N],c[N],ok[N];
void init(int u){
	for(int j=1;j<=19;++j){
		f[u][j]=f[f[u][j-1]][j-1];
	}
}
inline int Find(int u){
	for(int i=19;i>=0;--i){
		if(ok[f[u][i]])u=f[u][i];
	}
	return u;	
}
pair<int,ll> Solve(int u,int w){
	int A=0;
	ll B=0;
	while(ok[u]){
		int z=Find(u);
		if(a[z]>=w){
			A+=w;
			B+=1LL*w*c[z];
			a[z]-=w;
			break;
		}
		else{
			w-=a[z];
			A+=a[z];
			B+=1LL*a[z]*c[z];	
			ok[z]=0;
		}
	}
	return make_pair(A,B);
}
int main(){
	Q=read();
	dep[1]=1;
	ok[1]=1;
	a[1]=read(),c[1]=read();
	for(int t=2;t<=Q+1;++t){
		int opt=read();
		if(opt==1){
			int fa=read()+1;
			a[t]=read(),c[t]=read();
			f[t][0]=fa;
			init(t);
			dep[t]=dep[fa]+1;
			ok[t]=1;
		}
		else{
			int u=read()+1,w=read();
			auto [A,B]=Solve(u,w);
			printf("%d %lld\n",A,B);
			fflush(stdout);
		}
	}
	return 0;
}