//CF#175Div2 by HIR180
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
bool used[100005]={};
int main(){
	int n,s,t;
	scanf("%d %d %d",&n,&s,&t);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	used[s]=true;
	int cur=s;
	if(s==t)
	{
		puts("0");
		return 0;
	}
	for(int i=1;;i++){
		cur=num[cur];
		 if(cur==t){
			printf("%d\n",i);
			return 0;
		}else if(used[cur]){
			puts("-1");
			return 0;
		}else{
			used[cur]=true;
		}
	}
}