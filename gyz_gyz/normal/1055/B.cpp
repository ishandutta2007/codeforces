#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 2000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,q,l,x,y,z,ans,a[N];
void f(int x,int y){
	if(a[x]>l)return;
	a[x]+=y;if(a[x]<=l)return;
	if(a[x-1]<=l&&a[x+1]<=l)ans++;
	if(a[x-1]>l&&a[x+1]>l)ans--;
}
int main(){
	scanf("%d%d%d",&n,&q,&l);
	rep(i,1,n){
		scanf("%d",&x);f(i,x);
	}
	rep(i,1,q){
		scanf("%d",&x);
		if(x){
			scanf("%d%d",&y,&z);f(y,z);
		}else printf("%d\n",ans);
	}
}