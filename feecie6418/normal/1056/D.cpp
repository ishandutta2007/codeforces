#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pr;
int fa[100005],n,isl[100005],sz[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)isl[i]=1;
	for(int i=2;i<=n;i++)cin>>fa[i],isl[fa[i]]=0;
	for(int i=n;i;i--)sz[i]+=isl[i],sz[fa[i]]+=sz[i];
	sort(sz+1,sz+n+1);
	for(int i=1;i<=n;i++)cout<<sz[i]<<' ';
}