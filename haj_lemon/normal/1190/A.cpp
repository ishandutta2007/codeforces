#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
ll m,n,k,a[N],ans;
int main(){
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)cin>>a[i];
	for (int l=1,r=0;l<=m;l=r+1){
		while (r+1<=m&&(a[r+1]-l+1-1)/k==(a[l]-l+1-1)/k)r++;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}