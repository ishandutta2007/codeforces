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
int main(){
	int num[9]={0,1, 2, 9, 64, 625, 7776, 117649, 2097152};
		int n,k;
		scanf("%d %d",&n,&k);
		long long res=num[k];
		long long se=(long long)(n-k);
		for(long long i=0;i<se;i++){
			res*=se;
			res%=1000000007;
		}
		printf("%lld\n",res);
}