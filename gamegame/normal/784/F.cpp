#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int n,p,t;
int cnt[101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p;
		cnt[p]++;
	}
	for(int i=1; i<=80000000 ;i++){
		if(rand()%2==0) t*=2;
	}
	for(int i=1; i<=100 ;i++){
		for(int j=0; j<cnt[i] ;j++) cout << i << ' ';
	}
}