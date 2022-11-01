#include<bits/stdc++.h>
#define ll long long
#define int long long
inline ll read(){
	char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
	ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
	while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
using namespace std;
int n,ans,k,a[1000000],kk;
bool flag[1000000];
struct lsg{int x,l,r,d;}f[1000000];
void delit(){
	f[1]=f[k];k--;int kk=0,x=1;
	for (;kk<x;){
			kk=x;
			if (kk*2<=k&&f[kk*2].x<f[x].x)x=kk*2;
			if (kk*2+1<=k&&f[kk*2+1].x<f[x].x)x=kk*2+1;
			swap(f[kk],f[x]);
		}
}bool pd(lsg x,lsg y){return x.x<y.x;}
signed main(){
	kk=read();n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);k=n+1;
	for (int i=1;i<=n-1;i++)f[i].x=a[i]=a[i+1]-a[i],f[i].l=i-1,f[i].r=i+1,f[i].d=i;
	f[n].x=1e15;f[n+1].x=1e15;f[n].d=0;f[n+1].d=n;a[0]=a[n]=1e15;
	sort(f+1,f+1+k,pd);
	while (kk--){
		while (flag[f[1].d])delit();
		while (flag[f[1].l])f[1].l--;
		while (flag[f[1].r])f[1].r++;
		ans+=f[1].x;f[1].x=a[f[1].d]=a[f[1].l]+a[f[1].r]-f[1].x;
		flag[f[1].l]=true;flag[f[1].r]=true;
		f[1].l--;f[1].r++;f[++k]=f[1];delit();
	}writeln(ans);
}