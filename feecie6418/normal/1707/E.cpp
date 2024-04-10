#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int L[19][100005],R[19][100005],fmx[19][17][100005],fmi[19][17][100005];
int lg2[100005]={-1},a[100005],n,q,f1[19][100005];
int Qmx(int l,int r,int id){
	int k=lg2[r-l+1];
	return max(fmx[id][k][l],fmx[id][k][r-(1<<k)+1]);
}
int Qmi(int l,int r,int id){
	int k=lg2[r-l+1];
	return min(fmi[id][k][l],fmi[id][k][r-(1<<k)+1]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),lg2[i]=lg2[i>>1]+1,f1[0][i]=a[i];
	if(*min_element(a+1,a+n+1)!=1||*max_element(a+1,a+n+1)!=n){
		while(q--){
			int l,r;
			scanf("%d%d",&l,&r);
			if(l==1&&r==n)puts("0");
			else puts("-1");
		}
		return 0;
	}
	for(int i=1;i<n;i++)L[0][i]=min(a[i],a[i+1]),R[0][i]=max(a[i],a[i+1]);
	for(int j=1;j<=18;j++){
		for(int i=1;i<n;i++)fmx[j-1][0][i]=R[j-1][i],fmi[j-1][0][i]=L[j-1][i];
		for(int k=1;k<=16;k++)
			for(int i=1;i+(1<<k)-1<n;i++){
				fmx[j-1][k][i]=max(fmx[j-1][k-1][i],fmx[j-1][k-1][i+(1<<k-1)]);
				fmi[j-1][k][i]=min(fmi[j-1][k-1][i],fmi[j-1][k-1][i+(1<<k-1)]);
			}
		for(int i=1;i<=n;i++)f1[j][i]=f1[j-1][f1[j-1][i]];
		for(int i=1;i<n;i++){
			if(L[j-1][i]<R[j-1][i])
				L[j][i]=Qmi(L[j-1][i],R[j-1][i]-1,j-1),R[j][i]=Qmx(L[j-1][i],R[j-1][i]-1,j-1);
			else L[j][i]=R[j][i]=f1[j-1][L[j-1][i]];
		}
	}
	while(q--){
		int l,r,ans=0;
		scanf("%d%d",&l,&r);
		if(l==1&&r==n){
			puts("0");
			continue;
		}
		for(int i=17;i>=0;i--){
			if(l==r)break;
			int mn=Qmi(l,r-1,i),mx=Qmx(l,r-1,i);
			if(mn==1&&mx==n)continue;
			l=mn,r=mx,ans+=(1<<i);
		}
		if(l==r||Qmi(l,r-1,0)!=1||Qmx(l,r-1,0)!=n){
			puts("-1");
			continue;
		}
		cout<<ans+1<<'\n';
	}
}