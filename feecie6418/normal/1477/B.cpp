#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,l[200005],r[200005],flag;
char a[200005],b[200005];
struct P{
	int len,sum;
}t[800005];
P operator +(P a,P b){
	P ret;
	ret.sum=a.sum+b.sum,ret.len=a.len+b.len;
	return ret;
}
int tag[800005];
void Build(int p,int l,int r){
	tag[p]=-1;
	if(l==r){
		t[p]={1,b[l]-'0'};
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=t[p*2]+t[p*2+1];
}
void Tag(int p,int x){
	if(!x)t[p].sum=0;
	else t[p].sum=t[p].len;
	tag[p]=x;
}
void Pushdown(int p){
	if(~tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=-1;
}
void Make(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Make(p*2,l,mid,x,y,z);
	if(mid<y)Make(p*2+1,mid+1,r,x,y,z);
	t[p]=t[p*2]+t[p*2+1];
}
P Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	Pushdown(p);
	int mid=(l+r)/2;
	if(x>mid)return Query(p*2+1,mid+1,r,x,y);
	if(y<=mid)return Query(p*2,l,mid,x,y);
	return Query(p*2,l,mid,x,y)+Query(p*2+1,mid+1,r,x,y);
}
void Solve(){
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	for(int i=1;i<=m;i++)scanf("%d%d",&l[i],&r[i]);
	Build(1,1,n);
	flag=1;
	for(int i=m;i>=1;i--){
		int s=Query(1,1,n,l[i],r[i]).sum;
		if(s*2==r[i]-l[i]+1){
			flag=0;
			break;
		}
		if(s*2>r[i]-l[i]+1)Make(1,1,n,l[i],r[i],1);
		else Make(1,1,n,l[i],r[i],0);
	}
	for(int i=1;i<=n;i++){
		if(Query(1,1,n,i,i).sum!=a[i]-'0')flag=0;
	}
	if(flag)puts("YES");
	else puts("NO");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}