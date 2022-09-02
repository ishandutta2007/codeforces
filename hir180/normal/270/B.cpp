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
int num[100005];
int main(){
	int n;
	scanf("%d",&n);
	int ans=0;
	bool N=true;
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	int last;
	for(int i=0;i<n;i++){
		if(num[i]==1){
			N=false;
			last=i;
		}
		if(!N){
			if(i!=n-1){
				if(num[i]>num[i+1]){
					last=i+1;
				}
			}
		}
	}
	printf("%d\n",last);
}