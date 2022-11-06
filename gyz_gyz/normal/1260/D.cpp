#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1e6+10;
int m,n,k,t,v[N],l[N],r[N],d[N],a[N];
bool sol(int D){int ans=0;
	rep(i,1,n+1)v[i]=0;
	rep(i,1,k)if(d[i]>D)++v[l[i]],--v[r[i]+1];
	rep(i,1,n)if(v[i]+=v[i-1])ans+=2;
	return ans<=t;
}
int main(){
	scanf("%d%d%d%d",&m,&n,&k,&t);t-=n+1;
	rep(i,1,m)scanf("%d",&a[i]);a[0]=1e9;
	sort(a+1,a+m+1,[](int x,int y){return x>y;});
	rep(i,1,k)scanf("%d%d%d",&l[i],&r[i],&d[i]);
	int L=0,R=m,M=(L+R+1)>>1;
	for(;L<R;M=(L+R+1)>>1)if(sol(a[M]))L=M;else R=M-1;
	printf("%d\n",M);
}