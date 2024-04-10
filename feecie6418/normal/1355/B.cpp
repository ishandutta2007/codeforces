#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
int a[200005]; 
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			int j=i;
			while(j<=n&&j-i+1<a[j])j++;
			if(j>n)break;
			ans++,i=j;
		}
		cout<<ans<<'\n';
	} 
}