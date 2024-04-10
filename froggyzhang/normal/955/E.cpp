#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const int inf=1e9;
int n,a[N],p1[N],p2[N];
class Segment_Tree{
	struct node{
		int mn;
		node(){mn=inf;}
	}t[N<<2];
	#define ls u<<1
	#define rs u<<1|1
public:
	void Change(int u,int L,int R,int p,int d){
		if(L==R){
			t[u].mn=d;
			return;
		}
		int mid=(L+R)>>1;
		p<=mid?Change(ls,L,mid,p,d):Change(rs,mid+1,R,p,d);
		t[u].mn=min(t[ls].mn,t[rs].mn);
	}
	int Query(int u,int L,int R,int l,int r){
		if(l>r)return inf;
		if(L>=l&&R<=r){
			return t[u].mn;
		}
		int mid=(L+R)>>1,mn=inf;
		if(l<=mid)mn=min(mn,Query(ls,L,mid,l,r));
		if(r>mid)mn=min(mn,Query(rs,mid+1,R,l,r));
		return mn;
	}
}Pre,Suf,jbl,jbr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		p1[i]=p2[i]=i;
	}
	for(int i=1;i<=n;++i){
		jbl.Change(1,1,n,i,a[i]-i);
		jbr.Change(1,1,n,i,a[i]+i);
	}
	sort(p1+1,p1+n+1,[&](int i,int j){return a[i]<a[j];});
	sort(p2+1,p2+n+1,[&](int i,int j){return 2*i-a[i]<2*j-a[j];});
	int j1=1,j2=n;
	while(j2>=1&&2*p2[j2]-a[p2[j2]]>1){
		Pre.Change(1,1,n,p2[j2],p2[j2]);
		--j2;
	}
	++j2;
	int ans=inf;
	for(int z=1;z<=n;++z){
		while(j1<=n&&z>a[p1[j1]]){
			Suf.Change(1,1,n,p1[j1],p1[j1]);
			++j1;	
		}
		while(j2<=n&&!(z<2*p2[j2]-a[p2[j2]])){
			Pre.Change(1,1,n,p2[j2],inf);
			++j2;	
		}
		int j=min(Pre.Query(1,1,n,1,z),Suf.Query(1,1,n,z,n));
		if(j==inf)continue;
		
		int gl=jbl.Query(1,1,n,1,min(j-1,z))+z,gr=jbr.Query(1,1,n,max(j,z),n)-z;
		if(j>z){
			gl=min(gl,jbr.Query(1,1,n,z,j-1)-z);
		}
		else{
			gr=min(gr,jbl.Query(1,1,n,j,z)+z);
		}
		ans=min(ans,max(gl,gr));
	}
	cout<<(ans==inf?-1:ans)<<'\n';
	return 0;
}