#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,a[500005],cnt;
ll sum=0,ts=0,s[500005],curs[500005];
struct Node{
	ll curs,curans;
};
bool operator <(const Node a,const Node b){
	return a.curs<b.curs;
}
int main() {
	scanf("%d%d",&n,&K);
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,[](int x,int y) {return x>y;});
	priority_queue<Node> q;
	int pos=n;
	for(int i=1;i<=n;i++){
		ts+=s[i-1];
		s[i]=s[i-1]+a[i];
		if(s[i]<0){
			pos=i;
			break;
		}
	}
	q.push({s[pos],ts});
	for(int i=pos+1;i<=pos+K&&i<=n;i++)q.push({a[i],0});
	for(int i=pos+K+1;i<=n;i++){
		Node x=q.top();
		q.pop();
		x.curans+=x.curs,x.curs+=a[i];
		q.push(x);
	}
	while(!q.empty())sum+=q.top().curans,q.pop();
	cout<<sum;
	return 0;
}
/*
13 2
3 1 4 1 5 -9 -2 -6 -5 -3 -5 -8 -9

14 2
3 1 4 1 -10 -9 -2 -6 -5 -3 -5 -8 -9 -13
*/