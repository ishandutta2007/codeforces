#include<iostream>
using namespace std;
const int N=500002;
int n,nn;
string t;
int dp[N];
int r[N],s[N];
int nr[N];
int sz1[N],sz2[N];
int p1[N],p2[N];
int b1[N],b2[N];
int ord[N];
int lcp[N];
int sp[19][N];
int maxi[1<<20];
void upd(int id,int l,int r,int p,int v){
	if(l==r){
		maxi[id]=v;
		return;
	}
	int mid=(l+r)/2;
	if(p<=mid) upd(id*2,l,mid,p,v);
	else upd(id*2+1,mid+1,r,p,v);
	maxi[id]=max(maxi[id*2],maxi[id*2+1]);
}
int qry(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return 0;
	if(ql<=l && r<=qr) return maxi[id];
	int mid=(l+r)/2;
	return max(qry(id*2,l,mid,ql,qr),qry(id*2+1,mid+1,r,ql,qr));
}
int jj(int i,int dpi){
	int cl=r[i],cr=r[i];
	for(int j=18; j>=0 ;j--){
		if(cl-(1<<j)>=1 && sp[j][cl-(1<<j)]>=dpi) cl-=(1<<j);
		if(cr+(1<<j)<=n && sp[j][cr]>=dpi) cr+=(1<<j);
	}
	return qry(1,1,n,cl,cr);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> t;t='?'+t;nn=max(n,26);
	for(int i=1; i<=n ;i++) r[i]=t[i]-'a'+1;
	for(int i=1; i<=n ;i*=2){
		for(int j=1; j<=n ;j++) s[j]=(j+i<=n)?r[j+i]:0;
		for(int j=0; j<=nn ;j++) sz1[j]=sz2[j]=p1[j]=p2[j]=0;
		for(int j=1; j<=n ;j++) sz1[r[j]]++,sz2[s[j]]++;
		for(int j=1; j<=nn ;j++) sz1[j]+=sz1[j-1],sz2[j]+=sz2[j-1];
		for(int j=1; j<=n ;j++) b2[(s[j]>0?sz2[s[j]-1]:0)+(++p2[s[j]])]=j;
		for(int j=1; j<=n ;j++) b1[sz1[r[b2[j]]-1]+(++p1[r[b2[j]]])]=b2[j];
		for(int j=1; j<=n ;j++){
			if(j!=1 && r[b1[j]]==r[b1[j-1]] && s[b1[j]]==s[b1[j-1]]) nr[b1[j]]=nr[b1[j-1]];
			else nr[b1[j]]=j;
		}
		for(int j=1; j<=n ;j++) r[j]=nr[j];
	}
	for(int i=1; i<=n ;i++) ord[r[i]]=i;
	for(int i=1; i<=n ;i++){
		if(r[i]==1) continue;
		lcp[r[i]]=max(0,lcp[r[i-1]]-1);
		int k=ord[r[i]-1];
		while(i+lcp[r[i]]<=n && k+lcp[r[i]]<=n && t[i+lcp[r[i]]]==t[k+lcp[r[i]]]) lcp[r[i]]++;
	}
	for(int i=1; i<n ;i++) sp[0][i]=lcp[i+1];
	for(int i=1; i<19 ;i++){
		for(int j=1; j+(1<<i)<=n ;j++) sp[i][j]=min(sp[i-1][j],sp[i-1][j+(1<<(i-1))]);
	}
	dp[n]=1;
	int open=n+1;
	int ans=1;
	for(int i=n-1; i>=1 ;i--){
		dp[i]=dp[i+1]+1;
		while(true){
			int val=jj(i,dp[i]-1);
			int val2=jj(i+1,dp[i]-1);
			if(val>=dp[i]-1 || val2>=dp[i]-1) break;
			dp[i]--;open--;
			upd(1,1,n,r[open],dp[open]);
		}
		ans=max(ans,dp[i]);
	}
	cout << ans << endl;
}