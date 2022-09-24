#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200000,B=350;
int n,m,q,a[N+5],id[N+5],ori[N+5],bel[N+5],S[(N+B-1)/B+5],cn0=0;
int E[(N+B-1)/B+5],cnt[(N+B-1)/B+5][17005],tag[(N+B-1)/B+5];
int A[N+5],C[N+5],tot,lst[N+5],d[N+5],all[N+5];
char op[10];
void Pushdown(int x){
	for(int i=S[x];i<=E[x];i++)cnt[x][d[i]]--,d[i]^=tag[x];
	tag[x]=0;
}
void Redo(int x){
	for(int i=S[x];i<=E[x];i++)cnt[x][d[i]]++;
}
void Upd(int x,int y){
	if(all[x%m])cn0--;
	all[x%m]^=y;
	if(all[x%m])cn0++;
	int l=id[x],r=lst[x%m];
	Pushdown(bel[l]);
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++)d[i]^=y;
		return Redo(bel[l]);
	}
	Pushdown(bel[r]);
	for(int i=l;i<=E[bel[l]];i++)d[i]^=y;
	for(int i=S[bel[r]];i<=r;i++)d[i]^=y;
	Redo(bel[l]),Redo(bel[r]);
	for(int i=bel[l]+1;i<bel[r];i++)tag[i]^=y;
}
void Getans(){
	int ans=0;
	for(int j=1;j<=bel[n+1];j++)ans+=cnt[j][tag[j]];
	cout<<n+1-ans<<'\n';
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]^=x,A[i]=x;
	for(int i=1;i<=n+1;i++)E[bel[i]=(i-1)/B+1]=i;
	for(int i=n+1;i;i--)S[bel[i]]=i;
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[i]^=x,C[i]=x;
	for(int i=n+1;i;i--)a[i]^=a[i-1];
	for(int i=m+1;i<=n+1;i++)a[i]^=a[i-m];
	for(int i=n-m+2;i<=n+1;i++){
		all[i%m]=a[i];
		if(a[i])cn0++;
	}
	for(int i=1;i<=m;i++){
		for(int j=i;j<=n+1;j+=m)id[j]=++tot,ori[tot]=j,lst[i%m]=tot;
	}
	for(int i=1;i<=bel[n+1];i++)for(int j=S[i];j<=E[i];j++)cnt[i][d[j]=a[ori[j]]]++;
	if(cn0)puts("-1");
	else Getans();
	for(int i=1,x,y;i<=q;i++){
		scanf("%s%d%d",op,&x,&y);
		if(op[0]=='a')Upd(x,A[x]^y),Upd(x+1,A[x]^y),A[x]=y;
		else Upd(x,C[x]^y),Upd(x+1,C[x]^y),C[x]=y;
		if(cn0)puts("-1");
		else Getans();
	}
}