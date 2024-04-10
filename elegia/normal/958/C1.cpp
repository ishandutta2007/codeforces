#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 100005
#define MAXM 205
#define INF 0x7FFFFFFF
#define LL long long
#define NN 100
using namespace std;

int N,P;
int a[MAXN];
int s0[MAXN],s1[MAXN];


int main(){
	//ios::sync_with_stdio(0);
	//freopen("1.txt","r",stdin);
	
	cin>>N>>P;
	
	for(int i=1;i<=N;i++){
		cin>>a[i];
		s0[i] = (s0[i-1] + a[i])%P;
	}
	int ans = 0;
	for(int i=1;i<N;i++){
		ans = max(ans, s0[i] + ((s0[N] - s0[i])%P+P)%P);
	}
	cout<<ans;
	return 0;
}