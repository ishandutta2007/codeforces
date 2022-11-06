#include<bits/stdc++.h>
using namespace std;
struct Info{int x,y;}a[200010];
int n,h,f[200010],g[200010],ansn;
int main(){
	scanf("%d %d",&n,&h);ansn=h;
	for (int i=1;i<=n;i++){scanf("%d %d",&a[i].x,&a[i].y);}
	for (int i=1;i<=n;i++) f[i]=a[i].y-a[i].x,g[i]=a[i+1].x-a[i].y;
	for (int i=1;i<=n;i++) f[i]+=f[i-1];
	for (int i=1;i<n;i++) g[i]+=g[i-1];
	int l=1,r=1;
	if (g[r-1]-g[l-1]<h) ansn=max(ansn,f[r]-f[l-1]+h);
	while (l<=r){
		if (g[r-1]-g[l-1]<h){r++;if (r>n) break;}else l++;
		if (g[r-1]-g[l-1]<h) ansn=max(ansn,f[r]-f[l-1]+h);
	}
	cout<<ansn<<endl;
	return 0;
}