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
map<int,int>ma;
int num[100005];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		int cou=1;
		while(num[i]>1){
			if(num[i]%2==1){
				num[i]=(num[i]-1)/2;
				cou++;
			}else{
				num[i]/=2;
			}
		}
		ma[cou]++;
	}
	long long ans=0;
	map<int,int>::iterator ite;
	for(ite=ma.begin();ite!=ma.end();ite++){
		ans+=(long long)(ite->second)*(ite->second-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}