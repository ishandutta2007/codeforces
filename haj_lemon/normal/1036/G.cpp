#include<bits/stdc++.h>
using namespace std;
struct Info{int nu,ne;}a[1000010];
int m,n,x,y,b[1000010],f[1000010],g[1000010],c[40],bi[1000010],num,nb,nc;
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;}
int dfs(int x){
	int sum=0;
	if (f[x]==0) sum+=(1<<(bi[x]));
	for (int y=b[x];y;y=a[y].ne)sum+=dfs(a[y].nu);
	return sum;
}
int pa(int x){
	int y=0;
	while (x){y+=x%2;x/=2;}
	return y;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++){scanf("%d %d",&x,&y);f[x]++;g[y]++;jb(x,y);}
	for (int i=1;i<=n;i++)if(f[i]==0)bi[i]=nb++;
	for (int i=1;i<=n;i++)if(g[i]==0)c[++nc]=dfs(i);
	for (int i=1;i<((1<<nc)-1);i++){
		int k=0;
		for (int j=1,l=1;j<=nc;l*=2,j++)if ((i&l)!=0)k=(k|c[j]);
		if (pa(i)>=pa(k)){cout<<"NO"<<endl;return 0;}
	}
	cout<<"YES"<<endl;
	return 0;
}