//zyk yyds
#include<bits/stdc++.h>
using namespace std;
#define N 4233
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
int n,a[N];
int A[N],B[N],va[N],vb[N];
mt19937 rnd(time(0));
int main(){
	n=read();
	int zyk=0;
	for(int i=0;i<(1<<n);++i)zyk^=(a[i]=read());
	if(zyk)return !printf("Fou\n");
	printf("Shi\n");
	int res=(1<<n);
	memset(A,-1,sizeof(A));
	memset(B,-1,sizeof(B));
	memset(va,-1,sizeof(va));
	memset(vb,-1,sizeof(vb));
	while(res){
		vector<int> vec;
		for(int i=0;i<(1<<n);++i){
			if(!~va[i])vec.push_back(i);
		}
		int u=vec[rnd()%vec.size()];
		bool flag=false;
		for(int i=0;i<(1<<n);++i){
			if(~A[i])continue;
			if(!~vb[a[i]^u]){
				--res;
				A[i]=u,B[i]=a[i]^u;
				va[u]=vb[a[i]^u]=i;
				flag=true;
				break;
			}
		}
		if(flag)continue;
		vector<int> pos;
		for(int i=0;i<(1<<n);++i){
			if(!~A[i])pos.push_back(i);
		}
		int p=pos[rnd()%pos.size()];
		int z=vb[a[p]^u];
		va[A[z]]=vb[B[z]]=-1;
		A[z]=B[z]=-1;
		va[u]=vb[a[p]^u]=p;
		A[p]=u,B[p]=a[p]^u;
	}
	for(int i=0;i<(1<<n);++i)printf("%d ",A[i]);
	printf("\n");
	for(int i=0;i<(1<<n);++i)printf("%d ",B[i]);
	return 0;
}