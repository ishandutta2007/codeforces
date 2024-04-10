#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,k;
int a[300002];
bool ok[300001];
bool check(int mid){
	queue<pair<int,int> >q;
	int last=0,front=1;
	bool ok;
	q.push(make_pair(a[1],0));
	for(int i=1; i<=n ;i++){
		while(!q.empty() && a[i]-q.front().first>mid){
			q.pop();
		}
		ok=false;
		if(!q.empty() && i-q.front().second>=k) ok=true;
		if(ok) q.push(make_pair(a[i+1],i));
	}
	return ok;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int l=0,r=1e9,mid;
	while(l!=r){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout << l << endl;
}