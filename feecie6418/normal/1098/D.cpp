#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n;
struct Heap{
	priority_queue<int,vector<int>,greater<int>> q,del;
	ll sum=0;
	void push(int n){q.push(n),sum+=n;}
	void pop(int n){del.push(n),sum-=n;}
	int top(){
		while(q.size()&&del.size()&&q.top()==del.top())q.pop(),del.pop();
		if(!q.size())return -1;
		return q.top();
	}
}q[40];
int main(){
	cin>>n;
	for(int i=1,cnt=0;i<=n;i++){
		char op[10];
		int x;
		scanf("%s%d",op,&x);
		if(op[0]=='+'){
			cnt++;
			for(int j=0;j<30;j++)if((1<<j+1)>x){q[j].push(x);break;}
		}
		else {
			cnt--;
			for(int j=0;j<30;j++)if((1<<j+1)>x){q[j].pop(x);break;}
		}
		int ans=cnt;
		ll sum=0;
		for(int j=0;j<30;j++){
			if(q[j].sum&&sum*2<q[j].top())ans--;
			sum+=q[j].sum;
		}
		cout<<ans<<'\n';
	}
}