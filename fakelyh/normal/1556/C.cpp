#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1005],s[1005],ans,mn[1005][1005],sum,l,r,w;
inline int ask(int a,int b,int c,int d){
	if(a>c)swap(a,c),swap(b,d);
	if(b<c)return 0;
	if(b<d)return b-c+1;
	return d-c+1;
}
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(register int i=1;i<=n;i++)cin>>a[i];
	for(register int i=1;i<=n;i++)s[i]=s[i-1]+pow(-1,(i&1)+1)*a[i];
	memset(mn,0x3f,sizeof(mn));
	for(register int i=1;i<=n;i++){
		sum=0;
		for(register int j=i;j<=n;j++)sum+=pow(-1,(j&1)+1)*a[j],mn[i][j]=min(mn[i][j-1],sum);
	}
	for(register int i=1;i<=n;i+=2)
	for(register int j=i+1;j<=n;j++){
	    sum=s[j-1]-s[i],l=pow(-1,j&1)-sum,r=pow(-1,j&1)*a[j]-sum;
		if(max(1ll,-mn[i+1][j-1])<=a[i])ans+=ask(max(1ll,-mn[i+1][j-1]),a[i],l,r);
	}
	cout<<ans<<endl;
	return 0;
}