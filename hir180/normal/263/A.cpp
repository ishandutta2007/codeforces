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
	int num[5][5];
	int ax,ay;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%d",&num[i][j]);
			if(num[i][j]){
				ax=i;
				ay=j;
			}
		}
	}
	int ro=abs(2-ax);
	int rp=abs(2-ay);
	printf("%d\n",rp+ro);
	return 0;
}