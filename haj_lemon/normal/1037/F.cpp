#include<bits/stdc++.h>
#define mo 1000000007
#define ll long long
using namespace std;
struct Info{int nu,we;}f[1000010][22];
int a[1000010],p[1000010],n,k,sum,b[1000010];
long long ansn;
Info co(Info a,Info b){if (a.nu>b.nu) return a;return b;}
Info que(int l,int r){
	int x=p[(r-l+1)];
	return co(f[l][x],f[r-(1<<x)+1][x]);
}
ll co(int x){
	int l=0,r=sum,mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (a[mid]<=x)l=mid;else r=mid;
	}
	if (a[r]<=x) return r;return l;
}
ll get(int x,int y){
	int p=y,q=(x-y+1);
	if (p>q) swap(p,q);
	ll s1=co(p),s2=co(q),s3=co(x);
	ll sum=b[s1];
	sum=(sum+(s2-s1)*p)%mo;
	sum=(sum-(b[s3]-b[s2])+(s3-s2)*(x+1))%mo;
	sum=(sum+mo)%mo;
	return sum;
}
void work(int l,int r){
	if (r-l+1<k) return ;
	Info p=que(l,r);
	ansn=(ansn+p.nu*get(r-l+1,p.we-l+1))%mo;
	work(l,p.we-1);work(p.we+1,r);
}
int main(){
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++){scanf("%d",&f[i][0].nu);f[i][0].we=i;}
	p[1]=0;
	for (int i=2;i<=n;i++) p[i]=p[i/2]+1;
	sum=1;a[1]=k;
	while (a[sum]+k-1<=n){sum++;a[sum]=a[sum-1]+k-1;}
	for (int i=1;i<=sum;i++) b[i]=(b[i-1]+a[i])%mo;
	for (int j=2,i=1;j<=n;j*=2,i++)
		for (int k=1;k+(1<<i)-1<=n;k++)
			f[k][i]=co(f[k][i-1],f[k+(1<<(i-1))][i-1]);
	work(1,n);
	cout<<ansn<<endl;
	return 0;
}