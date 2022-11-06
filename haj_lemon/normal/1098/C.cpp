#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
ll n,s,d[N],de[N],fa[N];
ll get(ll x){
	memset(d,0,sizeof(d));memset(de,0,sizeof(de));
	d[1]=1;
	for (int i=2,no=1;i<=n;i++){d[i]=d[no]+1;de[no]++;if (de[no]==x)no++;}
	ll su=0;
	for (int i=1;i<=n;i++)su+=d[i];
	return su;
}
int get1(){
	int l=1,r=n-1,mid;
	while (l<r){
		mid=(l+r)/2;
		if (get(mid)>s)l=mid+1;else r=mid;
	}
	return l;	
}
ll get3(int deg,int dep){
	memset(d,0,sizeof(d));memset(de,0,sizeof(de));
	d[1]=1;
	for (int i=2;i<=dep;i++)d[i]=i,de[i-1]=1;
	ll no=deg;
	for (int i=dep+1,no=deg,k=2;;no=no*deg,k++){
		if (i+no-2<=n){
			for (int j=i;j<=i+no-2;j++)d[j]=k;
			i=i+no-1;
		}else{
			for (int j=i;j<=n;j++)d[j]=k;
			break;
		}
	}
	ll su=0;
	for (int i=1;i<=n;i++)su+=d[i];
	return su;
}
int get2(int x){
	if (x==1)return n;
	memset(d,0,sizeof(d));memset(de,0,sizeof(de));
	d[1]=1;
	for (int i=2,no=1;i<=n;i++){d[i]=d[no]+1;de[no]++;if (de[no]==x)no++;}
	int l=d[n],r=n,mid;
	while (l<r){
		mid=(l+r+1)/2;
		if (get3(x,mid)>s)r=mid-1;else l=mid;
	}
	return l;
}
int main(){
//	freopen("d.in","r",stdin);
	cin>>n>>s;
	if (s>(n+1)*n/2||s<n*2-1){puts("No");return 0;}
	int deg=get1();
	int dep=get2(deg);
	memset(d,0,sizeof(d));memset(de,0,sizeof(de));
	for (int i=1;i<=dep;i++)d[i]++;
	ll no=deg;
	for (int i=dep+1,no=deg,k=2;;no=no*deg,k++){
		if (i+no-2<n){
			for (int j=i;j<=i+no-2;j++)d[k]++;
			i=i+no-1;
		}else{
			for (int j=i;j<n;j++)d[k]++;
			break;
		}
	}
	ll su=0;
	for (int i=1;i<=n;i++)su+=1ll*i*d[i];
	d[s-su]++;
	for (int i=1,j=0;i<=n;i++){
		for (int k=j+1;k<=j+d[i];k++)fa[k]=i;
		j+=d[i];
	}
	puts("Yes");
	for (int i=2,la=1;i<=n;i++){
		while (fa[la]+1!=fa[i]||de[la]==deg)la++;
		de[la]++;
		cout<<la<<' ';
	}
	cout<<endl;
	return 0;
}