#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int seg[(1<<20)+5],A[(1<<20)+5],B[(1<<20)+5],C[(1<<20)+5],D[(1<<20)+5],n,b[300005];
ll a[300005];
void update(int i){
	int pos = i;
	i += (1<<19)-1; A[i]=B[i]=C[i]=D[i]=seg[i]=0;
	if(a[pos] > 0) A[i] = 1;
	if(a[pos] != 0) B[i] = 1;
	if(a[pos] != 0) C[i] = 1;
	if(a[pos] < 0) D[i] = 1;
	if(a[pos] != 0) seg[i] = 1;
	i = (i-1)/2; int L = 2;
	while(1){
		A[i]=B[i]=C[i]=D[i]=seg[i]=0;
		seg[i] = max(seg[i*2+1],seg[i*2+2]);
		seg[i] = max(seg[i],A[i*2+1]+max(C[i*2+2],D[i*2+2]));
		seg[i] = max(seg[i],B[i*2+1]+D[i*2+2]);
		if(A[i*2+2] < L/2) A[i] = A[i*2+2];
		else if(A[i*2+2] == L/2) A[i] = A[i*2+2]+A[i*2+1];
		if(B[i*2+2] < L/2) B[i] = B[i*2+2];
		else if(B[i*2+2] == L/2) B[i] = B[i*2+2]+A[i*2+1];
		if(D[i*2+2] == L/2){
			B[i] = max(B[i],D[i*2+2]+max(A[i*2+1],B[i*2+1]));
		}
		if(D[i*2+1] < L/2) D[i] = D[i*2+1];
		else if(D[i*2+1] == L/2) D[i] = D[i*2+1]+D[i*2+2];
		if(C[i*2+1] < L/2) C[i] = C[i*2+1];
		else if(C[i*2+1] == L/2) C[i] = C[i*2+1]+D[i*2+2];
		if(A[i*2+1] == L/2){
			C[i] = max(C[i],A[i*2+1]+max(C[i*2+2],D[i*2+2]));
		}
B[i] = max(B[i],A[i]); C[i] = max(C[i],D[i]);
if(A[i] == L) B[i]=C[i]=L;
if(D[i] == L) B[i]=C[i]=L;
		if(!i) break; L*=2;
		i = (i-1)/2;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<n;i++){
		a[i] =1LL*( b[i+1]-b[i]);
		update(i);
	}
	int q; scanf("%d",&q);
	for(int i=0;i<q;i++){
		int e,f,g; scanf("%d%d%d",&e,&f,&g);
		a[e-1] += g;
		a[f] -= g;
		if(e-1 >= 1){
			update(e-1);
		}
		if(f <= n-1){
			update(f); 
		}
		printf("%d\n",seg[0]+1);
	}
}