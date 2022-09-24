#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
const int mod=998244353;
int n,m,del1[1005],del2[1005];
ll a[1005],b[1005],t1[1005][4005],t2[1005][4005];
ll rd(){
	ll x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-'0',ch=getchar();
	return x;
}
void wrt(ll x){
	int c[40]={0};
	if(!x)return putchar('0'),void();
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])putchar(c[c[0]--]+'0');
}
ll gcd(ll x,ll y){
	if(!x||!y)return x+y;
	return __gcd(x,y);
}
void Build1(int id,int p,int l,int r){
	if(l==r)return t1[id][p]=a[id]/gcd(a[id],b[l]),void();
	int mid=(l+r)>>1;
	Build1(id,p*2,l,mid),Build1(id,p*2+1,mid+1,r);
	t1[id][p]=gcd(t1[id][p*2],t1[id][p*2+1]);
}
void Build2(int id,int p,int l,int r){
	if(l==r)return t2[id][p]=b[id]/gcd(b[id],a[l]),void();
	int mid=(l+r)>>1;
	Build2(id,p*2,l,mid),Build2(id,p*2+1,mid+1,r);
	t2[id][p]=gcd(t2[id][p*2],t2[id][p*2+1]);
}
void Erase1(int id,int p,int l,int r,int x){
	if(l==r)return t1[id][p]=0,void();
	int mid=(l+r)>>1;
	if(x<=mid)Erase1(id,p*2,l,mid,x);
	else Erase1(id,p*2+1,mid+1,r,x);
	t1[id][p]=gcd(t1[id][p*2],t1[id][p*2+1]);
}
void Erase2(int id,int p,int l,int r,int x){
	if(l==r)return t2[id][p]=0,void();
	int mid=(l+r)>>1;
	if(x<=mid)Erase2(id,p*2,l,mid,x);
	else Erase2(id,p*2+1,mid+1,r,x);
	t2[id][p]=gcd(t2[id][p*2],t2[id][p*2+1]);
}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=rd(),del1[i]=0;
	for(int i=1;i<=m;i++)b[i]=rd(),del2[i]=0;
	for(int i=1;i<=n;i++)Build1(i,1,1,m);
	for(int i=1;i<=m;i++)Build2(i,1,1,n);
	int remn=n,remm=m;
	while(remn&&remm){
		int P=0;
		for(int i=1;i<=n;i++){
			if(del1[i])continue;
			if(t1[i][1]>1)P=i;
		}
		if(P){
			del1[P]=1,remn--;
			for(int j=1;j<=m;j++)Erase2(j,1,1,n,P);
			continue;
		}
		for(int i=1;i<=m;i++){
			if(del2[i])continue;
			if(t2[i][1]>1)P=i;
		}
		if(P){
			del2[P]=1,remm--;
			for(int j=1;j<=n;j++)Erase1(j,1,1,m,P);
			continue;
		}
		puts("YES");
		cout<<remn<<' '<<remm<<'\n';
		for(int i=1;i<=n;i++)if(!del1[i])wrt(a[i]),cout<<' ';
		cout<<'\n';
		for(int i=1;i<=m;i++)if(!del2[i])wrt(b[i]),cout<<' ';
		cout<<'\n';
		return ;
	}
	puts("NO");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}