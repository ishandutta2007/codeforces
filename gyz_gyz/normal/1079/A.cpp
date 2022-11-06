#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define N 400000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,k,tot,al,a[N];
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(!(a[x]++))al++;
		tot=max(tot,a[x]);
	}
	printf("%d\n",((tot-1)/k+1)*k*al-n);
}