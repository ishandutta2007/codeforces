#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> P;
int n;
int sum[500]={};
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int a,b,c,d;
int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(int j=0;j<n;j++){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int num=b+120;
		for(int i=a-1;i>=1;i--){
			num+=month[i];
		}
		for(int i=num-1;i>=num-d;i--){
			sum[i]+=c;
		}
	}
	int ans=0;
	for(int i=0;i<500;i++){
		ans=max(ans,sum[i]);
	}
	printf("%d\n",ans);
	return 0;
}