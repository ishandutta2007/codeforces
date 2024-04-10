#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,K,q,is[3005][3005],X[3005],Y[3005],lst[3005][3005],l[3005],r[3005],nxt[3005],w[3005],cur[3005];
ll ans=0,sum=0;
vector<int> t[3005];
int S(int l,int r){
	return (l+r)*(r-l+1)/2;
}
int Calc(int i){
	if(nxt[i]<i)return (i-l[i]-1)*(i-l[i])/2;
	return S(r[nxt[i]]-i,r[nxt[i]]-(l[i]+1));
}
void Insert(int x,int p){
	int q=r[p];
	if(q==x)w[q]++;
	else r[p]=x,l[x]=p,r[x]=q,l[q]=x,w[x]=1;
	int i=r[x],cnt=0,j=l[i],s=0;
	ans-=cur[i];
	while(s+w[r[j]]<K)j=r[j],s+=w[j];
	nxt[i]=j,ans+=(cur[i]=Calc(i));
	for(i=l[i],cnt++;i&&cnt<=K;i=l[i],cnt++){
		ans-=cur[i],s+=w[i];
		while(s>=K)s-=w[j],j=l[j];
		nxt[i]=j,ans+=(cur[i]=Calc(i));
	}
}
int main(){
	cin>>n>>m>>q>>K;
	for(int i=1,x,y;i<=q;i++)cin>>x>>y,is[x][y]=i,t[x].push_back(y),X[i]=x,Y[i]=y;
	for(int i=1;i<=n;i++)sort(t[i].begin(),t[i].end());
	for(int i=1;i<=q;i++){
		int l=0;
		for(int j=X[i];j>=1;j--){
			for(int k:t[j])if(k<Y[i])l=max(l,k);
			lst[i][j]=l;
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)sum+=i*j;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m+1;j++)w[j]=l[j]=r[j]=nxt[j]=cur[j]=0;
		r[0]=r[m+1]=m+1,l[0]=l[m+1]=0,nxt[0]=nxt[m+1]=m+1,w[0]=0,w[m+1]=1e9,cur[m+1]=ans=m*(m+1)/2;
		for(int j=i;j<=n;j++){
			for(int k:t[j])Insert(k,lst[is[j][k]][i]);
			sum-=ans;
		}
	}
	cout<<sum;
}