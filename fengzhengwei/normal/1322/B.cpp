#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n;
int res[32];
int a[400005];
int b[400005];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<30;i++)
	{
		for(int j=1;j<=n;j++)b[j]=a[j]%(1<<i+1);
//		puts("");
		sort(b+1,b+n+1);
		int r=1;
		for(int j=2;j<=n;j++)
		{
//			cout<<j<<"wqeqeqe"<<;
			while(r<j&&b[j]+b[r]<(1<<i))r++;
			while(r>1&&b[j]+b[r-1]>=(1<<i))r--;
			res[i]+=(j-r);
		}
//		cout<<i<<" "<<res[i]<<endl;
		r=1;
		for(int j=2;j<=n;j++)
		{
			while(r<j&&b[j]+b[r]<(1<<i+1))r++;
			while(r>1&&b[j]+b[r-1]>=(1<<i+1))r--;
			res[i]-=(j-r);
//			cout<<j<<" s "<<r<<endl;
		}
//		cout<<i<<" "<<res[i]<<endl;
		r=1;
		for(int j=2;j<=n;j++)
		{
			while(r<j&&b[j]+b[r]<((1<<i+1)+(1<<i)))r++;
			while(r>1&&b[j]+b[r-1]>=((1<<i+1)+(1<<i)))r--;
			res[i]+=(j-r);
		}
//		cout<<i<<" "<<res[i]<<endl;
	}
	int ans=0;
	for(int i=0;i<30;i++)ans+=(res[i]&1)*(1<<i);
	cout<<ans<<endl;
	return 0;
}