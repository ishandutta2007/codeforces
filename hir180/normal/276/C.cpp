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
long long num[200005];
int start[200005];
int endd[200005];
long long shu[200005]={};
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	sort(num,num+n);
	long long ans=0;
	for(int j=0;j<q;j++){
		int e,o;
		scanf("%d %d",&e,&o);
		start[j]=e;
		endd[j]=o;
	}
	sort(start,start+q);
	sort(endd,endd+q);
	for(int i=0;i<n;i++){
		int qe=upper_bound(start,start+q,i+1)-lower_bound(start,start+q,i+1);
		int qf=upper_bound(endd,endd+q,i)-lower_bound(endd,endd+q,i);
		if(i!=0) shu[i]=shu[i-1]+qe-qf;
		else shu[i]=qe-qf;
	}
	sort(shu,shu+n);
	for(int i=n-1;i>=0;i--){
		ans+=shu[i]*num[i];
	}
	printf("%lld\n",ans);
	return 0;
}