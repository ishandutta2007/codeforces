#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int f[200005],a[200005],n,K,mx=0,all[200005],h[200005],allh[200005];
int pre[200005],suf[200005],pall[200005],sall[200005],M,s[200005];
int pl[200005],F[200005],L[200005],R[200005],v[400005];
vector<int> g[200005];
void dfs(int x,int fa){
	pl[++pl[0]]=x,F[x]=fa,all[x]=a[x];
	for(int y:g[x]){
		if(y==fa)continue;
		dfs(y,x),all[x]=min(all[x],all[y]);
	}
}
int p1=2000000;
char buf[2000005];
int gc(){
	return getchar();
	if(p1>=2000000)fread(buf,1,2000000,stdin),p1=0;
	return buf[p1++];
}
int rd(){
	int x=0,ff=1;
	char ch=gc();
	while((ch<'0'||ch>'9')&&ch!='-')ch=gc();
	if(ch=='-')ff=-1,ch=gc();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=gc();
	return x*ff;
}
int main(){
	n=rd(),K=rd();
	for(int i=1;i<=n;i++)a[i]=rd();
	for(int i=1,x,y;i<n;i++)x=rd(),y=rd(),g[x].push_back(y),g[y].push_back(x);
	dfs(1,0);
	for(int i=1,cur=0;i<=n;i++){
		L[i]=cur;
		for(int j:g[i])if(j!=F[i])v[cur++]=j;
		R[i]=cur;
	}
	int l=1,r=1e6,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		M=mid,mx=0;
		//dp1(1,0);
		for(int i=n;i>=1;i--){
			int x=pl[i];
			if(a[x]<M)f[x]=0;
			else {
				f[x]=1;
				int m=0;
				for(int j=L[x],y=v[j];j<R[x];j++,y=v[j]){
					if(all[y]>=M)f[x]+=f[y];
					else m=max(m,f[y]);
				}
				f[x]+=m;
			}
			//cout<<x<<' '<<f[x]<<'\n';
		}
		//dp2(1,0);
		allh[1]=1;
		for(int i=1;i<=n;i++){
			int x=pl[i];
			//cout<<x<<' '<<h[x]<<' '<<allh[x]<<'\n';
			if(a[x]<M){
				for(int j=L[x],y=v[j];j<R[x];j++,y=v[j])h[y]=allh[y]=0;
				continue;
			}
			int c=0;
			for(int j=L[x],y=v[j];j<R[x];j++,y=v[j])s[c++]=y;
			if(!c){
				mx=max(mx,1+h[x]);
				continue;
			}
			int sum=1;
			for(int i=0;i<c;i++)if(all[s[i]]>=M)sum+=f[s[i]];
			if(allh[x])sum+=h[x];
			if(all[s[0]]<M)pre[0]=f[s[0]],pall[0]=0;
			else pre[0]=0,pall[0]=1;
			for(int i=1;i<c;i++){
				pre[i]=max(pre[i-1],all[s[i]]<M?f[s[i]]:0);
				pall[i]=(pall[i-1]&&all[s[i]]>=M);
			}
			if(!allh[x])suf[c]=h[x],sall[c]=0;
			else suf[c]=0,sall[c]=1;
			for(int i=c-1;i>=0;i--){
				suf[i]=max(suf[i+1],all[s[i]]<M?f[s[i]]:0);
				sall[i]=(sall[i+1]&&all[s[i]]>=M);
			}
			for(int i=0;i<c;i++){
				int u=sum,v=0,av=1;
				if(all[s[i]]>=M)u-=f[s[i]];
				if(i)v=max(v,pre[i-1]),av&=pall[i-1];
				v=max(v,suf[i+1]),av&=sall[i+1];
				u+=v;
				h[s[i]]=u,allh[s[i]]=av;
				//cout<<"S:"<<s[i]<<' '<<pre[max(i-1,0)]<<' '<<v<<'\n';
			}
			mx=max(mx,sum+suf[0]);
			for(int i=0;i<=c;i++){
				pre[i]=suf[i]=pall[i]=sall[i]=0;
			}
		}
		if(mx>=K)ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
}