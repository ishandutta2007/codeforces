#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],pre[100005],suf[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],pre[i]=pre[i-1]|a[i];
	for(int i=n;i;i--)suf[i]=suf[i+1]|a[i];
	int mx=-1,mxp=0;
	for(int i=1;i<=n;i++){
		if((a[i]-((pre[i-1]|suf[i+1])&a[i]))>mx)mx=(a[i]-((pre[i-1]|suf[i+1])&a[i])),mxp=i;
	}
	b[1]=a[mxp];
	for(int i=1,o=1;i<=n;i++)if(i!=mxp)b[++o]=a[i];
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	int w=b[1];
	for(int i=2;i<=n;i++)w-=w&b[i];
	cerr<<endl<<w;
}