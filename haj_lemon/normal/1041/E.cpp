#include<bits/stdc++.h>
using namespace std;
struct Info{int nu,we,x,y;}a[1010];
int n,x,y,b[1010],nb,xb;
bool c=true,v[1010];
bool comp(const Info &a,const Info &b){return a.nu>b.nu;}
bool comp1(const Info &a,const Info &b){return a.we<b.we;}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d %d",&x,&y);
		if (max(x,y)==n){a[i].nu=min(x,y);a[i].we=i;}else c=false;
	}
	sort(a+1,a+n,comp);
	for (int i=1;i<=n;i++)v[i]=true;
	for (int i=1;i<n;i++)v[a[i].nu]=false;
	for (int i=n-1;i>=1;i--) if (v[i])b[++nb]=i;
	xb=1;
	for (int i=1,j=0;i<=n;i=j+1){
		while (j<=n&&a[j+1].nu==a[i].nu)j++;
		if (b[xb]>a[i].nu) c=false;
		if (i==j){
			a[i].x=n;a[i].y=a[i].nu;
		}else{
			a[i].x=n;a[i].y=b[xb];
			for (int k=i+1;k<j;k++){
				a[k].x=b[xb];a[k].y=b[++xb];
			}
			a[j].x=b[xb];a[j].y=a[j].nu;xb++;
		}
	}
	if (c){
		cout<<"YES"<<endl;
		sort(a+1,a+n,comp1);
		for (int i=1;i<n;i++) cout<<a[i].x<<' '<<a[i].y<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}