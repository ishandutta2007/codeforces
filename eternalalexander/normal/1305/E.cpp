#include <bits/stdc++.h>
int n,m,a[5005],vis[200005];
void output(int l,int r){
	for(int i=l;i<=r;++i)printf("%d ",i);exit(0);
}
int main(){
	scanf("%d%d",&n,&m);
	int d=0,ans=0;
	for(int i=1;i<=n;++i){
		ans+=(i-1)/2;
		if(ans==m){output(n-i+1,n-i+1+n-1);}
		if(ans>m){
			ans-=(i-1)/2;
			d=i;
			break;
		}
	}//printf(">%d\n",d);
	if(d==0){puts("-1");return 0;}
	for(int i=1;i<n;++i)a[i]=i+(n-d);
	for(int i=1;i<n;++i){
		for(int j=i+1;j<n;++j){
			vis[a[i]+a[j]]++;
		}
	}for(int i=a[n-1]+1;;i++){
		if(vis[i]==m-ans){
			a[n]=i;
			for(int i=1;i<=n;++i)printf("%d ",a[i]);return 0;
		}
	}
	return 0;
}