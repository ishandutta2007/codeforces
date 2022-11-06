#include<bits/stdc++.h>
using namespace std;
typedef long long L;
const int N=100011;
int n,m,a[3][N],b[3],c[3];
L A[3][N];
int Ge(int x,int r){
	if(r<0)return 1;
	return (double)a[x][c[x]+1]/(x+1) > (double)a[r][c[r]+1]/(r+1);
}
int main(){
#ifdef flukehn
	freopen("in.txt","r",stdin);
#endif
	int i,j,k,x,y,t,r;
	cin>>n>>m;
	for(i=1;i<=n;++i){
		scanf("%d%d",&x,&y);
		--x;
		a[x][++b[x]]=y;
	}
	for(i=0;i<3;++i)sort(a[i]+1,a[i]+b[i]+1,greater<int>());
	for(i=0;i<3;++i){
		for(j=1;j<=b[i];++j)A[i][j]=A[i][j-1]+a[i][j];
	}
	//cerr<<"ok\n";
	t=m;
	while(t){
		//cerr<<t<<" "<<c[0]<<" "<<c[1]<<" "<<c[2]<<endl;
		//cerr<<t<<" "<<b[0]<<" "<<b[1]<<" "<<b[2]<<endl;
		r=-1;
		for(i=0;i<3;++i)
			if(t>i && c[i]<b[i] && Ge(i,r))
				r=i;
		if(r<0)break;
		c[r]++;
		t-=r+1;
	}
	L an=0;
	for(i=max(0,c[0]-10);i<=min(b[0],c[0]+10);++i)
		for(j=max(0,c[1]-10);j<=min(b[1],c[1]+10);++j)
			for(k=max(0,c[2]-10);k<=min(b[2],c[2]+10);++k)
				if(i+j*2+k*3<=m)
					an=max(an,A[0][i]+A[1][j]+A[2][k]);
	cout<<an<<endl;
}