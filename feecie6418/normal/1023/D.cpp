#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m,a[200005],L[200005],R[200005],st[200005],top;
int main(){
	cin>>n>>m;
	int hasm=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m)hasm=1;
	}
	if(!hasm){
		for(int i=1;i<=n;i++){
			if(!a[i]){
				a[i]=m;
				hasm=1;
				break;
			}
		}
		if(!hasm)return puts("NO"),0;
	}
	for(int i=1;i<=n;i++){
		if(a[i])continue;
		int j=i;
		while(j<n&&a[j+1]==0)j++;
		int k=max(a[i-1],a[j+1]);
		for(int x=i;x<=j;x++)a[x]=k;
		i=j;
	}
	for(int i=1;i<=n;i++){
		R[a[i]]=i;
		if(!L[a[i]])L[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(top&&a[i]<a[st[top]])return puts("NO"),0;
		if(L[a[i]]==i)st[++top]=i;
		if(R[a[i]]==i)assert(st[top]==L[a[i]]),top--;
	}
	puts("YES");
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}