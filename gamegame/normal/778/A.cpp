#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
string p,t;
int a[200001];
bool del[200001];
bool check(int mid){
	for(int i=1; i<=n ;i++) del[i]=false;
	for(int i=1; i<=mid ;i++) del[a[i]]=true;
	int cur=1;
	for(int i=1; i<=n ;i++){
		if(del[i]) continue;
		if(t[i]==p[cur]) cur++;
		if(cur==m+1) return true;
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> t >> p;
	n=t.size();m=p.size();
	t='^'+t;p=' '+p;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	int left=0,right=n,mid;
	while(left!=right){
		mid=(left+right+1)/2;
		if(check(mid)){
			left=mid;
		}
		else{
			right=mid-1;
		}
	}
	cout << left << endl;
}