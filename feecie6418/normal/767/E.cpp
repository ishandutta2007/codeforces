#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,m,c[100005],w[100005],cho[100005],A[100005],d[100005];
ll sum=0;
priority_queue<pr,vector<pr>,greater<pr> > q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>c[i],d[i]=c[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		c[i]%=100;
		if(!c[i])continue;
		A[i]=(100-c[i])*w[i];
		if(m>=c[i]){
			m-=c[i];
			q.push(pr(A[i],i));
			continue;
		}
		if(q.size()&&q.top().first<A[i]){
			sum+=q.top().first;
			cho[q.top().second]=1;
			q.pop();
			m+=100;
			m-=c[i];
			q.push(pr(A[i],i));
			continue;
		}
		m+=100-c[i];
		sum+=A[i];
		cho[i]=1;
	}
	cout<<sum<<'\n';
	for(int i=1;i<=n;i++){
		if(cho[i])cout<<(d[i]+99)/100<<" 0\n";
		else cout<<d[i]/100<<' '<<d[i]%100<<'\n';
	}
}