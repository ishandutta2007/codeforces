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
#define mod 1000000007 
bool f[1005]={};
long long c[1005][1005]={};
long long binary[1005]={};
int main(){
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i) c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=mod;
		}
	}
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int gl; cin >> gl;
		f[gl]=true;
	}
	vector<int>fl;
	int cur=0;
	for(int i=1;i<=n;i++){
		if(!f[i]){
			cur++;
		}else{
				fl.pb(cur);
				cur=0;
		}
	}
	fl.pb(cur);
	long long ret=1;
	int all=n-m;
	for(int i=0;i<fl.size();i++){
		ret*=c[all][fl[i]];
		ret%=mod;
		all-=fl[i];
	}
	binary[0]=1;
	for(int i=1;i<1000;i++){
		binary[i]=binary[i-1]*2;
		binary[i]%=mod;
	}
	for(int i=1;i<fl.size()-1;i++){
		if(fl[i]) ret*=binary[fl[i]-1];
		ret%=mod;
	}
	printf("%lld\n",ret);
	return 0;
}