#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct Y{
	int x,y;
}s[500005]; 
int main(){
	cin>>n;
	if(n<=2)return puts("0"),0;
	int o=1;
	while(o*2<=n)o<<=1;
	for(int i=1;(1<<i)<=o;i++){
		for(int j=1;j<=o;j+=(1<<i)){
			for(int k=j;k<j+(1<<i-1);k++)if(k+(1<<i-1)<=n)s[++ans]={k,k+(1<<i-1)};
		}
	}
	for(int i=1;(1<<i)<=o;i++){
		for(int j=1;j<=o;j+=(1<<i)){
			for(int k=j;k<j+(1<<i-1);k++)if(k+(1<<i-1)<=n)s[++ans]={n-o+k,n-o+k+(1<<i-1)};
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)cout<<s[i].x<<' '<<s[i].y<<endl;
	return 0;
}