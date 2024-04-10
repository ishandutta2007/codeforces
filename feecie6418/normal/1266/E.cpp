#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pr;
int n,m,a[200005];
ll s=0;
map<int,int> f[200005];
void Inc(int x,int d){
	s-=max(a[x],0);
	a[x]+=d;
	s+=max(a[x],0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
	scanf("%d",&m);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		if(f[x][y])Inc(f[x][y],1);
		f[x][y]=z;
		if(z)Inc(z,-1);
		cout<<s<<'\n';
	}
}