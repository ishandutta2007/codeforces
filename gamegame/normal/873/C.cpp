#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
int n,m,k;
using namespace std;
int a[101][101];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			cin >> a[i][j];
		}
	}
	int maxs=0,maxcc=0;
	for(int j=1; j<=m ;j++){
		int maxi=0,maxc=0,cur=0;
		for(int i=1; i<=n ;i++){
			if(a[i][j]==0) continue;
			int sum=0;
			for(int l=i; l<=min(n,i+k-1) ;l++){
				sum+=a[l][j];
			}
			if(sum>maxi){
				maxi=sum;
				maxc=cur;
			}
			cur++;
		}
		maxcc+=maxc;
		maxs+=maxi;
	}
	cout << maxs << ' ' << maxcc << endl;
}