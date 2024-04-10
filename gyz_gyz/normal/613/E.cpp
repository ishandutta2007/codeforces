#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define N 2010
#define mo 1000000007
using namespace std;
typedef long long ll;
int n,m;char s[2][N],t[N];
ll ans,a[2][N][N],b[2][N][N],h1[2][N],h2[2][N],H1[N],H2[N],ut[N],rt[N];
ll qk(ll x,int y){ll r=1;
	for(;y;y>>=1){if(y&1)r=r*x%mo;x=x*x%mo;}return r;
}
ll gt(int l,int r,int k){
	if(l<=r)return (h1[k][r]+mo-h1[k][l-1]*ut[r-l+1]%mo)*rt[r-l+1]%mo;
	return (h2[k][r]+mo-h2[k][l+1]*ut[l-r+1]%mo)*rt[l-r+1]%mo;
}
ll gt(int l,int r){
	if(l<=r)return (H1[r]+mo-H1[l-1]*ut[r-l+1]%mo)*rt[r-l+1]%mo;
	return (H2[r]+mo-H2[l+1]*ut[l-r+1]%mo)*rt[l-r+1]%mo;
}
int main(){
	scanf("%s%s%s",s[0]+1,s[1]+1,t+1);
	for(n=1;s[0][n];)++n;--n;
	for(m=1;t[m];)++m;--m;ut[0]=rt[0]=1;
	rep(i,1,n)ut[i]=ut[i-1]*131%mo,rt[i]=qk(ut[i],mo-2);
	rep(i,1,n)rep(j,0,1)h1[j][i]=(h1[j][i-1]*131+s[j][i])%mo;
	rep(i,1,m)H1[i]=(H1[i-1]*131+t[i])%mo;
	dep(i,n,1)rep(j,0,1)h2[j][i]=(h2[j][i+1]*131+s[j][i])%mo;
	dep(i,m,1)H2[i]=(H2[i+1]*131+t[i])%mo;
	rep(i,1,n){
		rep(k,0,1){
			if(s[k][i]==t[1])add(a[k][i+1][2],1);
			if(m>1&&s[k][i]==t[m])add(b[k][i+1][m-1],1);
		}
		rep(j,2,n-i+1){if(j*2>m)break;
			rep(k,0,1){
				if(j*2==m)add(ans,gt(i,i+j-1,k^1)==gt(m,m-j+1)&&gt(i+j-1,i,k)==gt(m-j,m-j*2+1));
				if(gt(i,i+j-1,k^1)==gt(m,m-j+1)&&gt(i+j-1,i,k)==gt(m-j,m-j*2+1))
					add(ans,a[k][i][m-j*2+1]);
				if(gt(i,i+j-1,k^1)==gt(1,j)&&gt(i+j-1,i,k)==gt(j+1,j*2))
					add(ans,b[k][i][j*2]);
			}
		}
		rep(j,1,m)rep(k,0,1)
			if(s[k][i]==t[j]){
				add(a[k][i+1][j+1],a[k][i][j]);
				add(b[k][i+1][j-1],b[k][i][j]);
				if(j<m&&s[k^1][i]==t[j+1])add(a[k^1][i+1][j+2],a[k][i][j]);
				if(j>1&&s[k^1][i]==t[j-1])add(b[k^1][i+1][j-2],b[k][i][j]);
			}
		rep(k,0,1){
			add(ans,a[k][i+1][m+1]);
			add(ans,b[k][i+1][0]);
		}
		rep(j,1,i){if(j*2>m)break;
			rep(k,0,1){
				if(j*2==m)add(ans,gt(i,i-j+1,k^1)==gt(1,j)&&gt(i-j+1,i,k)==gt(j+1,j*2));
				add(a[k][i+1][j*2+1],gt(i,i-j+1,k^1)==gt(1,j)&&gt(i-j+1,i,k)==gt(j+1,j*2));
				add(b[k][i+1][m-j*2],gt(i,i-j+1,k^1)==gt(m,m-j+1)&&gt(i-j+1,i,k)==gt(m-j,m-j*2+1));
			}
		}
	}
	printf("%lld\n",ans);
}