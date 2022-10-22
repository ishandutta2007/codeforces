#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+100;
ll a[N];int bk[N],sta[N],tot=0,f[N],L[N],R[N],g[N][2];bool bz[N][2],Ans[N];

int n;
bool PD(int L,int R,ll c){
	if(c<0) return false;
	if(c==0) return true;
	if(L>R) return false;
	swap(L,R);L=n-L+1;R=n-R+1;
	int l=0,r=R-L+1;
	while(l<=r){
		int mid=(l+r)>>1;
		ll t1=(ll)L*mid+(ll)mid*(mid-1)/2;
		ll t2=(ll)R*mid-(ll)mid*(mid-1)/2;
		if(t1<=c&&c<=t2) return true;
		if(c<t1) r=mid-1;
		else l=mid+1;
	}
	return false;
}
void doit(int L,int R,ll c){
	if(L>R) return ;
	swap(L,R);L=n-L+1;R=n-R+1;
	int l=0,r=R-L+1;
	while(l<=r){
		int mid=(l+r)>>1;
		ll t1=(ll)L*mid+(ll)mid*(mid-1)/2;
		ll t2=(ll)R*mid-(ll)mid*(mid-1)/2;
		if(t1<=c&&c<=t2){
			int now=mid;
			for(int j=L;j<=R;j++){
				t1=(ll)(j+1)*now+(ll)now*(now-1)/2;
				t2=(ll)R*now-(ll)now*(now-1)/2;
				if(c<t1||c>t2) Ans[n-j+1]=true,now--,c-=j;
			}
			return ;
		}
		if(c<t1) r=mid-1;
		else l=mid+1;
	}
}

int main()
{
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	ll las=-1;int las1;
	for(int i=1;i<=n;i++) bk[i]=2;
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(las!=-1){
				if(las==a[i]) bk[las1]=bk[i]=0;
				else if(las==a[i]+1) bk[las1]=0,bk[i]=1;
				else sta[++tot]=las1,R[tot]=i-1,L[tot+1]=i;
			}
			else L[1]=i;
			las=a[i];las1=i;
		}
	}
	sta[++tot]=las1;R[tot]=n+1;
	
	if(las==-1){
		for(int i=1;i<=n;i++) printf("0");
		return 0;
	}
	
	memset(bz,false,sizeof(bz));bz[0][1]=true;
	memset(f,60,sizeof(f));
	for(int i=1;i<=tot;i++){
		if(bz[i-1][1]){
			ll c=a[sta[i]]-a[sta[i-1]];
			if(bk[sta[i]]==1||bk[sta[i]]==2)
				if(PD(sta[i-1]+1,L[i]-1,c-(n-sta[i]+1))) bz[i][1]=true,g[i][1]=1;
			
			if(bk[sta[i]]==0||bk[sta[i]]==2)
				for(int j=(i==tot?L[i]:sta[i]+1);j<=R[i];j++)
					if(a[j]==0&&PD(sta[i-1]+1,L[i]-1,c-(n-j+1)-1)){
						bz[i][0]=true;
						if(f[i]>j) f[i]=j,g[i][0]=1;
					}
		}
		if(bz[i-1][0]){
			int t1=f[i-1];ll c=a[sta[i]]-a[sta[i-1]]+1;
			if(bk[sta[i]]==1||bk[sta[i]]==2)
				if(PD(t1+1,L[i]-1,c-(n-sta[i]+1))) bz[i][1]=true,g[i][1]=0;
			
			if(bk[sta[i]]==0||bk[sta[i]]==2)
				for(int j=(i==tot?L[i]:sta[i]+1);j<=R[i];j++)
					if(a[j]==0&&PD(t1+1,L[i]-1,c-(n-j+1)-1)){
						bz[i][0]=true;
						if(f[i]>j) f[i]=j,g[i][0]=0;
					}
		}
	}
	
	memset(Ans,false,sizeof(Ans));
	int c=(bz[tot][1]==true);
	for(int i=tot;i>=1;i--){
		int Las=g[i][c],t;ll s=a[sta[i]]-a[sta[i-1]]-(1-c)+1-Las;
		if(!Las) t=f[i-1]+1;else t=sta[i-1]+1;
		if(c) doit(t,L[i]-1,s-(n-sta[i]+1)),Ans[sta[i]]=true;
		else doit(t,L[i]-1,s-(n-f[i]+1)),Ans[f[i]]=true;
		c=Las;
	}
	
	for(int i=1;i<=n;i++) printf("%d",Ans[i]);
	printf("\n");
	
	return 0;
}