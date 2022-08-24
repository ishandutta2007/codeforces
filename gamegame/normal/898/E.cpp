#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
priority_queue<int,vector<int>,greater<int> >s,ns;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int a;
	for(int i=1; i<=n ;i++){
		cin >> a;
		int b=sqrt(a);
		if(b*b==a){
			if(b==0) s.push(2);
			else s.push(1);
		}
		else{
			ns.push(min((b+1)*(b+1)-a,a-b*b));
		}
	}
	long long ans=0;
	while(s.size()>n/2){
		ans+=s.top();
		s.pop();
	}
	while(ns.size()>n/2){
		ans+=ns.top();
		ns.pop();
	}
	cout << ans << endl;
}