#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],b[100005];
int main() {
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&n),b[0]=0;
		int mi=1e9;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),mi=min(mi,a[i]);
		for(int i=1;i<=n;i++)if(a[i]%mi==0)b[++b[0]]=a[i];
		sort(b+1,b+b[0]+1);
		for(int i=1,t=0;i<=n;i++)if(a[i]%mi==0)a[i]=b[++t];
		bool f=1;
		for(int i=2;i<=n;i++)if(a[i]<a[i-1])f=0;
		puts(f?"YES":"NO");
	}
	return 0;
}