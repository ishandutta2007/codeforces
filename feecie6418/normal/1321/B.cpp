#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int n,a[200005];
long long f[200005],tmp[1000005],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=tmp[a[i]-i+500000]+a[i];
		tmp[a[i]-i+500000]=max(tmp[a[i]-i+500000],f[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans;
}