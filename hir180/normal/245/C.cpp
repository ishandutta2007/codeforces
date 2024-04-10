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
	int n;
	scanf("%d",&n);
	if(n%2==0 || n==1){
		puts("-1");
		return 0;
	}
	int a[105];
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	int ans=0;
	for(int i=n;i>=2;i--){
		if(i%2==1){
			while(a[i]>0){
				a[(i-1)/2]--;
				a[i]--;
				a[i-1]--;
				if(a[i-1]<0) a[i-1]++;
				if(a[(i-1)/2]<0) a[(i-1)/2]++;
				ans++;
			}
		}else{
			while(a[i]>0){
				a[i/2]--;
				a[i]--;
				a[i+1]--;
				if(a[i+1]<0) a[i+1]++;
				if(a[i/2]<0) a[i/2]++;	
				ans++;
			}
		}
	}
	ans+=a[1];
	printf("%d\n",ans);
}