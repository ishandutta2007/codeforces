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
vector<int>prime;
bool notprime[101005]={};
int mat[505][505];
int col[505]={};
int row[505]={};
int main(){
	for(int i=2;i<=101000;i++){
		for(int j=2;j*i<=101000;j++){
			notprime[i*j]=true;
		}
	}
	for(int i=2;i<=101000;i++){
		if(!notprime[i]){
			prime.pb(i);
		}
	}
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int eo=lower_bound(prime.begin(),prime.end(),mat[i][j])-prime.begin();
			col[i]+=prime[eo]-mat[i][j];
		}
	}
	for(int j=0;j<m;j++){
		for(int i=0;i<n;i++){
			int eo=lower_bound(prime.begin(),prime.end(),mat[i][j])-prime.begin();
			row[j]+=prime[eo]-mat[i][j];
		}
	}
	int ans=INF;
	for(int i=0;i<n;i++){
		ans=min(ans,col[i]);
	}
	for(int i=0;i<m;i++){
		ans=min(ans,row[i]);
	}
	printf("%d\n",ans);
	return 0;
}