#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct Matrix{
	int a[2][2];
	Matrix(){memset(a,0,sizeof(a));}
	int* operator [](int k){return a[k];}
}t[2000005];
int a[500005],n,m;
Matrix operator *(Matrix x,Matrix y){
	Matrix ans;
	for(int i=0;i<2;i++)for(int j=0;j<2;j++)for(int k=0;k<2;k++)ans[i][j]=(ans[i][j]+1ll*x[i][k]*y[k][j])%mod;
	return ans;
}
void Build(int p,int l,int r){
	if(l==r)return t[p][1][0]=1,t[p][1][1]=a[l]+1,t[p][0][1]=(a[l-1]==1?9-a[l]:0),void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r),t[p]=t[p*2]*t[p*2+1];
}
void Update(int p,int l,int r,int x){
	if(l==r)return t[p][1][0]=1,t[p][1][1]=a[l]+1,t[p][0][1]=(a[l-1]==1?9-a[l]:0),void();
	int mid=(l+r)/2;
	if(x<=mid)Update(p*2,l,mid,x);
	else Update(p*2+1,mid+1,r,x);
	t[p]=t[p*2]*t[p*2+1];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char c;
		cin>>c,a[i]=c-'0';
	}
	Build(1,1,n);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),a[x]=y,Update(1,1,n,x),Update(1,1,n,x+1),printf("%d\n",t[1][1][1]);
}