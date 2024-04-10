#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include <iomanip>
#include<assert.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 500005
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int ans[N];
	for(int i=0;i<n;i++)
	ans[i]=i;
	vector<int> a[N];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++){
			int b;
			scanf("%d",&b);
			a[i].pb(b);
		}
	}
	for(int i=0;i<m;i++){
		int last=0;
		for(int j=1;j<n;j++){
			if(a[j][i]<a[j-1][i]){//printf("%d %d\n",last,j-1);
				ans[last]=max(j-1,ans[last]),last=j;
			}
		}
		ans[last]=n-1;
	}
	for(int i=1;i<n;i++)
	ans[i]=max(ans[i-1],ans[i]);
	int k;
	scanf("%d",&k);
	while(k--){
		int c,d;
		scanf("%d %d",&c,&d);
		c--,d--;
		if(ans[c]>=d)
		printf("Yes\n");
		else
		printf("No\n");
	}
}