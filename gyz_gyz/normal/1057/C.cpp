#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 3010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,m,k,tot,ans,f[60][N];char s[60];
struct pr{int r,p,c;}a[60];
bool cmp(pr x,pr y){return x.r<y.r;}
int main(){
	scanf("%d%d%d",&n,&m,&k);ans=inf;
	rep(i,1,n){
		scanf("%d",&a[i].r);
		a[i].p=i;tot+=a[i].r;
	}
	scanf("%s",s+1);
	rep(i,1,n)if(s[i]=='G')a[i].c=1;
	else if(s[i]=='B')a[i].c=2;
	sort(a+1,a+n+1,cmp);
	rep(i,1,n)rep(j,0,tot)f[i][j]=inf;
	rep(i,1,n){
		f[i][a[i].r]=min(f[i][a[i].r],abs(m-a[i].p));
		rep(j,0,tot)if(f[i][j]<inf){
			if(j>=k)ans=min(ans,f[i][j]);
			rep(k,i+1,n)if((a[i].r<a[k].r)&&(a[i].c!=a[k].c))
				f[k][j+a[k].r]=min(f[k][j+a[k].r],f[i][j]+abs(a[i].p-a[k].p));
		}
	}
	if(ans<inf)printf("%d",ans);else printf("-1");
}