#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int ans=0;
		for(int i=2,mx=a[1];i<=n;i++){
			if(a[i]<mx){
				long long l=1;int c=1;
				while(l*2<=mx-a[i])l<<=1,c++;
				ans=max(ans,c);
			}
			mx=max(mx,a[i]);
		}
		cout<<ans<<endl;
	}
}