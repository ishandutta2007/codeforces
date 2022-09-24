#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,lg2[1050005]={-1},c[1050005],ans[1050005],mx,v[1050005];
ll a[25],b[25],s[1050005];
int main(){
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
		if(b[i])a[++n]=b[i];
	}
	for(int i=1;i<(1<<n);i++)lg2[i]=lg2[i>>1]+1,c[i]=c[i>>1]+(i&1),s[i]=s[i-(i&-i)]+a[lg2[i&-i]+1];
	for(int i=1;i<(1<<n);i++){
		for(int j=i&(i-1);(j<<1)>=i;j=(j-1)&i){
			if(abs(s[i-j]-s[j])<c[i]&&((s[i-j]-s[j]-c[i])&1)){
				ans[i]=v[i]=1;
				break;
			}
		}
	}
	for(int i=1;i<(1<<n);i++){
		mx=max(mx,ans[i]);
		if(v[i])for(int t=(1<<n)-i-1,j=t;j;j=(j-1)&t)ans[i+j]=max(ans[i]+ans[j],ans[i+j]);
	}
	cout<<n-mx;
	return 0;
}