#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,fa[100005],tot,L[100005],R[100005],b[200005],op[100005],id[100005],fr[100005];
int vl[100005],vr[100005];
vector<int> tag[800005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Ins(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return tag[p].push_back(z);
	int mid=(l+r)>>1;
	if(x<=mid)Ins(p*2,l,mid,x,y,z);
	if(mid<y)Ins(p*2+1,mid+1,r,x,y,z);
}
void Merge(int x,int y){
	x=gf(x),y=gf(y);
	if(x==y)return ;
	fa[x]=y,vl[y]=min(vl[y],vl[x]),vr[y]=max(vr[y],vr[x]);
}
void Merge(int p,int l,int r,int x,int y){
	if(tag[p].size()){
		while(tag[p].size())Merge(y,tag[p].back()),tag[p].pop_back();
		tag[p].push_back(y);
	}
	if(l==r)return ;
	int mid=(l+r)>>1;
	if(x<=mid)Merge(p*2,l,mid,x,y);
	else Merge(p*2+1,mid+1,r,x,y);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&op[i],&L[i],&R[i]);
		if(op[i]==1)b[++b[0]]=L[i],b[++b[0]]=R[i],id[i]=++tot,fr[tot]=i;
	}
	sort(b+1,b+b[0]+1),b[0]=unique(b+1,b+b[0]+1)-b-1;
	for(int i=1;i<=n;i++)
		if(op[i]==1)
			L[i]=lower_bound(b+1,b+b[0]+1,L[i])-b,R[i]=lower_bound(b+1,b+b[0]+1,R[i])-b;
	for(int i=1;i<=tot;i++)fa[i]=i,vl[i]=L[fr[i]],vr[i]=R[fr[i]];
	for(int i=1;i<=n;i++){
		if(op[i]==1){
			Merge(1,1,b[0],L[i],id[i]),Merge(1,1,b[0],R[i],id[i]);
			if(L[i]+1<R[i])Ins(1,1,b[0],L[i]+1,R[i]-1,id[i]);
		}
		if(op[i]==2){
			int x=gf(L[i]),y=gf(R[i]);
			//cout<<x<<' '<<y<<'\n';
			if(x==y)puts("YES");
			else if(vl[x]>=vl[y]&&vr[x]<=vr[y]){
				if(L[fr[L[i]]]==vl[y]&&R[fr[L[i]]]==vr[y])puts("NO");
				else puts("YES");
			}
			else puts("NO");
		}
	}
}