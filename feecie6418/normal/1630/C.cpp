#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,M,mx[200005],mn[200005],f[200005],is[200005],R[200005];
int tmp[200005],c[200005];
struct Seg{
	int l,r;
}b[200005];
void Solve(){
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx[a[i]]=i;
	for(int i=n;i>=1;i--)mn[a[i]]=i;
	for(int i=n;i>=1;i--)if(mx[i])b[++m]={mn[i],mx[i]};
	sort(b+1,b+m+1,[](Seg x,Seg y){return x.l<y.l;});
	for(int i=1,prer=0,lst=0;i<=m;i++){
		if(prer>b[i].r)continue;
		prer=b[i].r;
		tmp[b[i].r]=i;
		if(b[i].l!=b[i].r)tmp[b[i].l]=-1;
		R[b[i].r]=b[i].l;
	}
	multiset<int> s;
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		if(tmp[i]<=0){
			if(tmp[i]!=-1)f[i]=f[i-1];
			else f[i]=1e9;
			continue;
		}
		f[i]=min(f[i-1]+1,f[R[i]-1]+2);
		while(r<i-1)s.insert(f[r+1]),r++;
		while(l<=R[i]&&l<=r)s.erase(s.find(f[l])),l++;
		if(s.size())f[i]=min(f[i],1+*s.begin());
		//for(int k=R[i]+1;k<i;k++)f[i]=min(f[i],f[k]+1);
		//cout<<i<<' '<<f[i]<<'\n';
	}
	cout<<n-f[n]<<'\n';
	for(int i=1;i<=n;i++)a[i]=mx[i]=mn[i]=is[i]=f[i]=R[i]=tmp[i]=0;
	m=M=0;
}
int main(){
	int t=1;
	while(t--)Solve();
}
/*
1
9
1 6 7 8 6 4 7 4 3
ans=3

1
8
1 6 7 6 4 7 4 3

1
6
1 2 3 1 2 3
*/