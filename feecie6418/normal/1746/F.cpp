#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pr;
const int mod=998244353,B=40;
const ll RA=2e9;
ll c[42][300005];
unsigned int a[42][600005];
int n,v[300005],q;
void U(int f,int x,ll y){
	while(x<=n)c[f][x]+=y,x+=x&-x;
}
ll Q(int f,int x){
	ll r=0;
	while(x)r+=c[f][x],x-=x&-x;
	return r;
}
mt19937_64 rng(time(0));
int O[300005],L[300005],R[300005],X[300005],b[600005];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]),b[i]=v[i];
	}
	b[0]=n;
	for(int i=1;i<=q;i++){
		scanf("%d",&O[i]);
		if(O[i]==1)scanf("%d%d",&L[i],&X[i]),b[++b[0]]=X[i];
		else scanf("%d%d%d",&L[i],&R[i],&X[i]);
	}
	sort(b+1,b+b[0]+1);
	for(int j=0;j<B;j++)for(int i=1;i<=b[0];i++)a[j][i]=rng()%RA;
	for(int i=1;i<=n;i++){
		v[i]=lower_bound(b+1,b+b[0]+1,v[i])-b;
		for(int j=0;j<B;j++)U(j,i,a[j][v[i]]);
	}
	for(int i=1;i<=q;i++){
		int op=O[i],l=L[i],r=R[i],x=X[i];
		if(op==1){
			x=lower_bound(b+1,b+b[0]+1,x)-b;
			for(int j=0;j<B;j++)U(j,l,(ll)a[j][x]-(ll)a[j][v[l]]);
			v[l]=x;
		}
		else {
			bool ok=1;
			for(int j=0;j<B;j++){
				ok&=(Q(j,r)%x==Q(j,l-1)%x);
			}
			if(ok)puts("YES");
			else puts("NO");
		}
	}
}