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
	int n,k;
	scanf("%d %d",&n,&k);
	if(n<k){
		puts("-1");
		return 0;
	}
	if(k==1){
		if(n>1){
			puts("-1");
			return 0;
		}else{
			puts("a");
			return 0;
		}
	}else if(k==2){
		string ans;
		while(n){
			if(n==1){
				ans.pb('a');
				break;
			}
			else ans+="ab";
			n-=2;
		}
		cout << ans << endl;
		return 0;
	}else{
		string rest;
		for(int i=3;i<=k;i++){
			rest.pb('a'+i-1);
		}
		n-=k;
		n+=2;
		string ans;
		while(n){
			if(n==1){
				ans.pb('a');
				break;
			}
			else ans+="ab";
			n-=2;
		}
		cout << ans+rest << endl;
		return 0;
	}
}