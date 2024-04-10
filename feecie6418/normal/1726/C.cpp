#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,fa[200005],st[200005];
char a[200005];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void Solve(){
	scanf("%d%s",&n,a+1);
	for(int i=1;i<=n+n;i++)fa[i]=i;
	int top=0;
	for(int i=1;i<=n+n;i++){
		if(a[i]=='(')st[++top]=i;
		else {
			fa[gf(i)]=gf(st[top]);
			top--;
		}
	}
	for(int i=1;i<n+n;i++)if(a[i]==')'&&a[i+1]=='(')fa[gf(i)]=gf(i+1);
	int s=0;
	for(int i=1;i<=n+n;i++)s+=(gf(i)==i);
	cout<<s<<'\n'; 
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve(); 
}