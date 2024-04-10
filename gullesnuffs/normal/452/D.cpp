#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long LL;
using namespace std;

queue<int> q[3];

int main(){
	int k;
	int n[3], t[3];
	int sum[4];
	scanf("%d", &k);
	for(int i=0; i < 3; ++i)scanf("%d", n+i);
	for(int i=0; i < 3; ++i)scanf("%d", t+i);
	for(int i=0; i < 3; ++i){
		for(int j=0; j < n[i]; ++j)
			q[i].push(0);
	}
	sum[0]=0;
	sum[1]=t[0];
	sum[2]=sum[1]+t[1];
	sum[3]=sum[2]+t[2];
	int ans=0;
	for(int i=0; i < k; ++i){
		int time=0;
		for(int j=0; j < 3; ++j){
			time=max(time, q[j].front()+sum[3]-sum[j]);
		}
		ans=time;
		for(int j=0; j < 3; ++j){
			q[j].pop();
			q[j].push(time+sum[j+1]-sum[3]);
		}
	}
	printf("%d\n", ans);
}