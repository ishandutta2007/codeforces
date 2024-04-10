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
int num[1000005]={};
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("2");
		puts("1 0");
		return 0;
	}
	if(n==2){
		puts("6");
		puts("0 2 1");
		return 0;
	}
	int binary[21];
	binary[0]=1;
	for(int i=1;i<=20;i++){
		binary[i]=binary[i-1]*2;
	}
	vector<P>vec;
	int ru=n,id;
	while(1){
		for(int i=1;i<=20;i++){
			if(ru<=binary[i]-1){
				id=i;
				break;
			}
		}
		vec.pb(mp(binary[id]-1-ru,ru));
		ru=binary[id]-2-ru;
		if(ru<1) break;
	}
	for(int i=0;i<vec.size();i++){
		int f=vec[i].first;
		int s=vec[i].second;
		for(int i=f;i<=s;i++){
			num[i]=s+f-i;
		}
	}
	long long ret;
	ret=(long long)n*(long long)(n+1);
	printf("%lld\n",ret);
	for(int i=0;i<=n;i++){
		printf("%d%c",num[i],i==n?'\n':' ');
	}
}