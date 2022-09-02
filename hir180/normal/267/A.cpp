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
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int main(){
	int n;
	P p[1005];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&p[i].first,&p[i].second);
		int ans=0;
		while(1){
			int we= p[i].second/p[i].first;
			p[i].second-=p[i].first*we;
			ans+=we;
			if(p[i].second<p[i].first){
				swap(p[i].first,p[i].second);
			}
			if(p[i].first==0){
				break;
			}
		}
		printf("%d\n",ans);
	}
}