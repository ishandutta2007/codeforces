#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[200005],s[200005],ans[200005];
ll f[200005];
struct P{
	int x,id;
	bool operator <(const P w) const {
		return x<w.x;
	}
}a[200005];
int main() {
	memset(f,0x3f,sizeof(f)),f[0]=0;
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]={x,i};
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		for(int j=max(i-10,0);j<=i-3;j++)if(f[j]+a[i].x-a[j+1].x<f[i])f[i]=f[j]+a[i].x-a[j+1].x,p[i]=j,s[i]=s[j]+1;
	}
	cout<<f[n]<<' '<<s[n]<<endl;
	for(int i=n,s=0;i;i=p[i]){
		s++;
		for(int j=i;j>p[i];j--)ans[a[j].id]=s;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	return 0;
}