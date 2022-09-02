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
int num[2000005];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		num[i]=i;
	}
	for(int i=2;i<=n;i++){
		int al=i-1,g;
		if(n%i==0){
			g=n/i;
			for(int j=g;j>=1;j--){
				num[al+j*i]=num[al+j*i-i];
			}
		}else{
			g=(n-(n%i))/i;
			num[al+n]=num[g*i+al];
			for(int j=g;j>=1;j--){
				num[al+j*i]=num[al+j*i-i];
			}
		}
		//for(int i=1;i<=n;i++){
		//	printf("%d ",num[i+al]);
		//}
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",num[i+n-1],i==n?'\n':' ');
	}
	return 0;
}