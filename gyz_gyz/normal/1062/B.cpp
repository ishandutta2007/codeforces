#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 3000000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,tot,ans,x,al,t[N];
int main(){
	scanf("%d",&n);ans=1;
	rep(i,2,n)while(!(n%i)){
		n/=i;x++;
		if(!(t[i]++))ans*=i,al++;
		if(t[i]>tot)tot=t[i];
	}
	if(tot*al==x&&tot==(tot&(-tot)))x=0;else x=1;
	while(tot!=(tot&(-tot)))tot+=tot&(-tot);
	for(;tot>1;tot>>=1)x++;
	printf("%d %d\n",ans,x);
}