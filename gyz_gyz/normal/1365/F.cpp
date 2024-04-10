#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
int a[N],b[N];pii A[N],B[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	if(n&1&&a[n/2+1]!=b[n/2+1]){
		printf("No\n");return;
	}
	rep(i,1,n/2){
		A[i]={a[i],a[n-i+1]};
		if(A[i].fr>A[i].sc)swap(A[i].fr,A[i].sc);
		B[i]={b[i],b[n-i+1]};
		if(B[i].fr>B[i].sc)swap(B[i].fr,B[i].sc);
	}
	sort(A+1,A+n/2+1);
	sort(B+1,B+n/2+1);
	rep(i,1,n/2)if(A[i]!=B[i]){
		printf("No\n");return;
	}
	printf("Yes\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}