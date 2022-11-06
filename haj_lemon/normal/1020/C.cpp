#include<bits/stdc++.h>
using namespace std;
struct Info{int x,y;}a[10010];
bool comp(const Info &a,const Info &b){return a.y<b.y;}
int m,n,f[10010],sum2,g[10010];
long long sum,ansn=1e18;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		f[a[i].x]++;
	}
	sort(a+1,a+n+1,comp);
	for (int i=f[1];i<=n;i++){
		sum2=0;
		for (int j=2;j<=m;j++){
			if (f[j]>=i){g[j]=f[j]-i+1;sum2+=f[j]-i+1;}else g[j]=0;
		}
		if (sum2>i-f[1]) continue;
		sum2=(i-f[1])-sum2;sum=0;
		for (int j=1;j<=n;j++){
			if (g[a[j].x]!=0){
				g[a[j].x]--;sum+=a[j].y;
			}else{
				if (sum2!=0&&a[j].x!=1){sum2--;sum+=a[j].y;}
			}
		}
		ansn=min(ansn,sum);
	}
	cout<<ansn<<endl;
	return 0;
}