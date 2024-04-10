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
int n,p,jc[250005]={1},ans=0;
int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%p;
	for(int i=1;i<=n;i++)ans=(ans+1ll*(n-i+1)*jc[i]%p*jc[n-i]%p*(n-i+1)%p)%p;
	cout<<ans;
}