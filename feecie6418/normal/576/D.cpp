#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,w[155];
struct U{
	int x,y,z;
}e[155];
struct Matrix{
	bitset<155> a[155];
	void E(bool P=1){
		for(int i=0;i<n;i++)a[i].reset(),a[i][i]=P;
	}
	bitset<155>& operator [](int x){
		return a[x];
	}
}g,vec[32],cur,tmp;
Matrix operator *(Matrix &x,Matrix &y){
	Matrix ans,t;
	ans.E(0);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)t[i][j]=y[j][i];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if((x[i]&t[j]).count())ans[i][j]=1;
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),w[i]=e[i].z;
	cur.E(),sort(w+1,w+m+1);
	for(int i=1,t;i<=m+1;i++){
		if(i!=m+1&&w[i]==w[i-1])continue;
		g.E(0),g[n-1][n-1]=1;
		for(int j=1;j<=m;j++)if(e[j].z<w[i]||i==m+1)g[e[j].x-1][e[j].y-1]=1;
		vec[0]=g,t=0;
		for(int j=1;j<=30;j++)vec[j]=vec[j-1]*vec[j-1];
		for(int j=30;j>=0;j--){
			if(t+(1<<j)>=((i!=m+1?w[i]-w[i-1]:2147483647)))continue;
			if(!(tmp=cur*vec[j])[0][n-1])cur=tmp,t+=(1<<j);
		}
		if(!(tmp=cur*vec[0])[0][n-1]){
			cur=tmp;
			continue;
		}
		return cout<<w[i-1]+t+1,0;
	}
	puts("Impossible");
}