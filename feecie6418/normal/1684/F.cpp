#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m,mm,a[200005],b[200005],I,curcnt,cnt[200005];
struct Seg{
	int l,r;
}c[200005],tmc[200005];
vector<int> pos[200005];
struct Segi{
	int l,r,id;
};
vector<Segi> ql[200005],qr[200005];
void inc(int x,int y){
	if(!cnt[x])curcnt++;
	cnt[x]+=y;
	if(!cnt[x])curcnt--;
}
void Solve(){
	scanf("%d%d",&n,&mm),m=0,I=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(b+1,b+n+1,a[i])-b,pos[a[i]].push_back(i);
	for(int i=1;i<=mm;i++){
		scanf("%d%d",&tmc[i].l,&tmc[i].r);
	}
	sort(tmc+1,tmc+mm+1,[](Seg x,Seg y){return x.l!=y.l?x.l<y.l:x.r>y.r;});
	for(int i=1,mxr=0;i<=mm;i++){
		if(tmc[i].r>mxr)c[++m]=tmc[i],mxr=tmc[i].r;
	}
	c[m+1].l=n+1;
	for(int i=1;i<=m;i++){
		int R=min(c[i+1].l-1,c[i].r);
		for(int j=c[i].l;j<=R;j++){
			int x=a[j];
			int l=lower_bound(pos[x].begin(),pos[x].end(),c[i].l)-pos[x].begin();
			int r=upper_bound(pos[x].begin(),pos[x].end(),c[i].r)-pos[x].begin()-1;
			if(l==r)continue;
			++I;
			ql[pos[x][l+1]].push_back({pos[x][l+1],pos[x][r],I});
			qr[pos[x][r]].push_back({pos[x][l+1],pos[x][r],I});
			
			ql[pos[x][l]].push_back({pos[x][l],pos[x][r-1],I});
			qr[pos[x][r-1]].push_back({pos[x][l],pos[x][r-1],I});
			//printf("%d %d;%d %d\n",pos[x][l+1],pos[x][r],pos[x][l],pos[x][r-1]);
		}
	}
	curcnt=0;
	int ans=1e9;
	for(int i=1,j=0;i<=n;i++){
		j=max(j,i-1);
		while(curcnt<I&&j<n){
			j++;
			for(auto k:qr[j]){
				if(k.l>=i)inc(k.id,1);
			}
		}
		if(curcnt==I)ans=min(ans,j-i+1);
		for(auto k:ql[i]){
			if(k.r<=j)inc(k.id,-1);
		}
	}
	cout<<ans<<'\n';
	for(int i=0;i<=max(n,m);i++){
		a[i]=b[i]=cnt[i]=0;
		c[i]=tmc[i]={0,0};
		pos[i].clear(),ql[i].clear(),qr[i].clear();
	}
	n=m=mm=I=curcnt=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}