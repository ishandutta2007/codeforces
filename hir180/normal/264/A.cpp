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
char st[1000005];
int main(){
	vector<int>ans1,ans2;
	scanf("%s",st);
	int leng=strlen(st);
	for(int i=leng-1;i>=0;i--){
		if(st[i]=='l'){
			ans2.pb(i+1);
		}else{
			ans1.pb(i+1);
		}
	}
	reverse(ans1.begin(),ans1.end());
	for(int i=0;i<ans1.size();i++){
		printf("%d\n",ans1[i]);
	}
	for(int i=0;i<ans2.size();i++){
		printf("%d\n",ans2[i]);
	}
}