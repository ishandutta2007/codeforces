#include<bits/stdc++.h>
using namespace std;
int m,n,k,ansn=-1,x,y,xx,yy,f[400010];
int fa(int x){
	if (f[x]!=x) f[x]=fa(f[x]);
	return f[x];
}
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=m+n;i++) f[i]=i;
	for (int i=1;i<=k;i++){
		cin>>x>>y;y+=n;
		xx=fa(x);yy=fa(y);
		if (xx!=yy)f[xx]=yy;
	}
	for (int i=1;i<=m+n;i++) if (f[i]==i)ansn++;
	cout<<ansn<<endl;
	return 0;
}