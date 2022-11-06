#include<bits/stdc++.h>
#define p 500000
#define N 500010
#define INF 1e9
using namespace std;
string s,st;
struct pp{int mi,we;}z;
struct seg{int ls,rs;pp x;}t[10000010];
int n,g[N],sa[N],ra[N],be[N],en[N],q,ls[N],rs[N],x[N],y[N],rk[N],h[N],f[N][20];
int lo[N],num=1,ro[N];
pp he(pp x,pp y){if (x.mi<y.mi)return x;return y;}
int que(int le,int x,int y){
	if (x+le>n||y+le>n) return le;
	for (int i=x+le,j=y+le;i<=n&&j<=n;i++,j++){
		if (s[j-1]!=s[i-1])return i-x;
		if (i==n||j==n)return i-x+1;
	}
}
int qlcp(int x,int y){if (y>n) return 0;x++;if (x>y) return INF;int z=lo[y-x+1];return min(f[x][z],f[y-(1<<z)+1][z]);}
int col(int x,int y){
	int l=x,r=n+1,mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (qlcp(x,mid)>y)l=mid;else r=mid;
	}
	if (qlcp(x,l)<=y)return l;return r;
}
int cor(int x,int y){
	int l=x,r=n+1,mid;
	while (l+1<r){
		mid=(l+r)/2;
		if (qlcp(x,mid)>=y)l=mid;else r=mid;
	}
	if (qlcp(x,r)>=y)return r;return l;	
}
void build(int nu,int l,int r){
	t[nu].x.mi=INF;t[nu].x.we=l;
	if (l!=r){t[nu].ls=++num;build(num,l,(l+r)/2);t[nu].rs=++num;build(num,(l+r)/2+1,r);}
}
void build1(int &no,int la,int l,int r,int we,int x){
	if (no==0) no=++num;
	t[no]=t[la];
	if (l==r){t[no].x.mi=x;}
	else{
		if (we<=(l+r)/2){t[no].ls=0;build1(t[no].ls,t[la].ls,l,(l+r)/2,we,x);}else
		{t[no].rs=0;build1(t[no].rs,t[la].rs,(l+r)/2+1,r,we,x);}
		t[no].x=he(t[t[no].ls].x,t[t[no].rs].x);
	}
}
pp que(int x,int l,int r,int nl,int nr){
	if (l==nl&&r==nr) return t[x].x;
	int mid=(l+r)/2;
	if (nl>mid) return que(t[x].rs,mid+1,r,nl,nr);
	if (nr<=mid) return que(t[x].ls,l,mid,nl,nr);
	return he(que(t[x].ls,l,mid,nl,mid),que(t[x].rs,mid+1,r,mid+1,nr));
}
int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s;be[0]=1;en[0]=s.length();
	cin>>q;
	for (int i=1;i<=q;i++){be[i]=s.length()+2;cin>>ls[i]>>rs[i]>>st;s+='&'+st;en[i]=s.length();}
	n=s.length();
	for (int i=1;i<=n;i++)g[s[i-1]]++;
	for (int i=1;i<=p;i++)g[i]+=g[i-1];
	for (int i=n;i>=1;i--)sa[g[s[i-1]]--]=i;
	for (int i=1;i<=n;i++) ra[sa[i]]=ra[sa[i-1]]+((i==1)|(s[sa[i]-1]!=s[sa[i-1]-1]));
	for (int j=1;ra[sa[n]]!=n;j*=2){
		for (int i=1;i<=n;i++)x[i]=ra[i];
		for (int i=1;i<=n;i++)if (i+j<=n) y[i]=ra[i+j];else y[i]=0;
		memset(g,0,sizeof(g));
		for (int i=1;i<=n;i++)g[y[i]]++;
		for (int i=1;i<=p;i++)g[i]+=g[i-1];
		for (int i=n;i>=1;i--)rk[g[y[i]]--]=i;
		memset(g,0,sizeof(g));
		for (int i=1;i<=n;i++)g[x[i]]++;
		for (int i=1;i<=p;i++)g[i]+=g[i-1];
		for (int i=n;i>=1;i--)sa[g[x[rk[i]]]--]=rk[i];
		for (int i=1;i<=n;i++)ra[sa[i]]=ra[sa[i-1]]+((i==1)|(x[sa[i]]!=x[sa[i-1]])|(y[sa[i]]!=y[sa[i-1]]));
	}
	for (int i=1;i<=n;i++){if (ra[i]==1){h[i]=0;}else{h[i]=que(max(h[i-1]-1,0),i,sa[ra[i]-1]);}}
	for (int i=1;i<=n;i++)f[i][0]=h[sa[i]];
	ro[n+1]=1;build(1,1,en[0]);
	for (int i=n;i>=1;i--){
		if (sa[i]<=en[0]){
			build1(ro[i],ro[i+1],1,en[0],sa[i],i);
		}else{
			ro[i]=ro[i+1];
		}
	}
	lo[1]=0;for(int i=2;i<=n;i++) lo[i]=lo[i/2]+1;
	for (int j=2,i=1;j<=n;j*=2,i++)
		for (int k=1;k+j-1<=n;k++)f[k][i]=min(f[k][i-1],f[k+(1<<(i-1))][i-1]);
	for (int i=1;i<=q;i++){
		for (int j=en[i]-be[i]+1;j>=0;j--){
			int l=col(ra[be[i]],j),r=cor(ra[be[i]],j);if (r>n) r--;
			if (l<=r&&ls[i]<=rs[i]-j){
				z=que(ro[l],1,en[0],ls[i],rs[i]-j);
				if (z.mi<=r){
					for (int k=z.we;k<=z.we+j;k++)cout<<s[k-1];cout<<endl;
					break;
				}
			}
			if (j==0)cout<<"-1"<<endl;
		}
	}
	return 0;
}