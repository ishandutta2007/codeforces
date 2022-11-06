#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 200010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int n,f[N];
void wr(int x){
	if(!x)return;wr(f[x]);printf("%d ",x);
}
int main(){
	scanf("%d",&n);
	rep(i,2,n)scanf("%d",&f[i]);wr(n);
}