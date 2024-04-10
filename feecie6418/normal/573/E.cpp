#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 LL;
typedef pair<int,int> pr;
const int mod=998244353,B=300;
pr b[100005];
ll ans=0,a[100005],d[100005],tagk[100005],tagb[100005];
int n,bel[100005],S[1005],E[1005],st[505][505],top[505],cur[505];
int used[100005];
void Redo(int i){
	//cout<<"Redo:"<<i<<'\n';
	top[i]=0;
	for(int k=S[i],t;k<=E[i];k=t+1){
		t=k;
		while(t<E[i]&&b[k].first==b[t+1].first)t++;
		ll mx=-1e18;
		int j=0;
		for(int l=k;l<=t;l++){
			if(used[b[l].second])continue;
			if(d[b[l].second]>mx)mx=d[b[l].second],j=b[l].second;
		}
		if(!j)continue;
		while(top[i]>1){
			int x=st[i][top[i]],y=st[i][top[i]-1];
			if(((LL)d[x]-d[y])*(a[x]-a[j])<((LL)d[x]-d[j])*(a[x]-a[y]))break;
			top[i]--;
		}
		st[i][++top[i]]=j;
	}
	cur[i]=1;
	while(cur[i]<top[i]&&d[st[i][cur[i]+1]]>d[st[i][cur[i]]])cur[i]++;
	//for(int j=1;j<=top[i];j++){
	//	printf("st[%d]=(%lld,%lld)\n",st[i][j],a[st[i][j]],d[st[i][j]]);
	//}
}
void Pushdown(int x){
	for(int i=S[x];i<=E[x];i++)d[i]+=tagk[x]*a[i]+tagb[x];
	tagk[x]=tagb[x]=0;
}
void Getmx(){
	ll mx=-1e18;
	int P=0;
	for(int i=1;i<=bel[n];i++){
		if(cur[i]>top[i])continue;
		int x=st[i][cur[i]];
		//if(x==931)cerr<<i<<' '<<cur[i]<<' '<<top[i]<<' '<<(cur[i]>top[i])<<"PP\n";
		if(a[x]*tagk[i]+d[x]+tagb[i]>mx){
			mx=a[x]*tagk[i]+d[x]+tagb[i];
			P=x;
		}
	}
	ans+=mx,used[P]=1,Pushdown(bel[P]);
	for(int i=S[bel[P]];i<P;i++)d[i]+=a[P];
	for(int i=P+1;i<=E[bel[P]];i++)d[i]+=a[i];
	Redo(bel[P]);
	for(int i=1;i<bel[P];i++)tagb[i]+=a[P];
	for(int i=bel[P]+1;i<=bel[n];i++){
		tagk[i]++;
		while(cur[i]<top[i]){
			int x=st[i][cur[i]],y=st[i][cur[i]+1];
			if(a[x]*tagk[i]+d[x]<a[y]*tagk[i]+d[y])cur[i]++;
			else break;
		}
	}
}
int main(){
	//freopen("subsequence3-2.in","r",stdin);
	//freopen("subsequence.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=pr(a[i],i),bel[i]=(i-1)/B+1;
	for(int i=1;i<=n;i++)E[bel[i]]=i,d[i]=a[i];
	for(int i=n;i;i--)S[bel[i]]=i;
	for(int i=1;i<=bel[n];i++){
		sort(b+S[i],b+E[i]+1);
		Redo(i);
	}
	ll uuu=0;
	for(int i=1;i<=n;i++)Getmx(),uuu=max(uuu,ans);
	cout<<uuu;
}