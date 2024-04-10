#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
long long num[100005];
long long query[100005][3];
long long imos[100005]={};
long long imoss[100005]={};
long long cou[100005]={};
long long sum[100005]={};
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
	}
	for(int i=1;i<=m;i++){
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		query[i][0]=a;
		query[i][1]=b;
		query[i][2]=c;
	}
	for(int i=0;i<k;i++){
		int g,j;
		scanf("%d %d",&g,&j);
		imos[g]++;
		imos[j+1]--;
	}
	for(int i=1;i<=m;i++){
		cou[i]=cou[i-1]+imos[i];
	}
	for(int i=1;i<=m;i++){
		query[i][2]*=cou[i];
	}
	for(int i=1;i<=m;i++){
		imoss[query[i][0]]+=query[i][2];
		imoss[query[i][1]+1]-=query[i][2];
	}
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+imoss[i];
	}
	for(int i=1;i<=n;i++){
		printf("%lld%c",sum[i]+num[i],i==n?'\n':' ');
	}
}