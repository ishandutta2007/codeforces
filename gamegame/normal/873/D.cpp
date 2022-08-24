#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
queue<pair<int,int> >q;
int a[200001];
int b[200002];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	if(k%2==0){
		cout << -1 << endl;
		return 0;
	}
	for(int i=1; i<=n ;i++){
		a[i]=i;
	}
	k--;
	if(n==1 && k!=0){
		cout << -1 << endl;
		return 0;
	}
	q.push(make_pair(1,n));
	for(int i=0; i<k ;i+=2){
		if(q.empty()){
			cout << -1 << endl;
			return 0;
		}
		int x=q.front().first,y=q.front().second;
		q.pop();
		int mid=(x+y-1)/2;
		b[x]+=y-mid;
		b[mid+1]-=y-x+1;
		b[y+1]+=mid-x+1;
		if(x!=mid) q.push(make_pair(x,mid));
		if(mid+1!=y) q.push(make_pair(mid+1,y));
	}
	int cur=0;
	for(int i=1; i<=n ;i++){
		cur+=b[i];
		a[i]=i+cur;
		cout << a[i] << ' ';
	}
	cout << endl;
}