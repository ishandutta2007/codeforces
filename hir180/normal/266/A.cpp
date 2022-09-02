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
	int dp[51][4]={};
	int n;
	string str;
	cin >> n >> str;
	int ans=10000;
	for(int i=0;i<n;i++){
		int num=i;
		char last;
		last=str[i];
		for(int j=i+1;j<n;j++){
			if(str[j]==last){
				num++;
			}else{
				last=str[j];
			}
		}
		ans=min(ans,num);
	}
	printf("%d\n",ans);
}