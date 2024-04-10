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
int n;
long long k[100005],a[100005];
long long maxi=0;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&k[i],&a[i]);
	}
	for(int i=0;i<n;i++){
		long long hk=1;
		for(int j=0;j<=15;j++){
			if(hk>=a[i] && j!=0){
				maxi=max(maxi,k[i]+j);
				break;
			}
			hk*=4;
		}
	}
	printf("%lld\n",maxi);
}