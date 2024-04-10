#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef array<int,2> pr;
const int mod=998244353;
int n,m,a[500005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x<m)a[x]++;
	}
	for(int i=1;i<m;i++){
		a[i+1]+=a[i]/(i+1);
		a[i]%=(i+1);
	}
	for(int i=1;i<m;i++)if(a[i])return puts("No"),0;
	puts("Yes");
}