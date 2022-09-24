#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[100005],m,nxt[100005],lst[100005],del[100005],inq[100005];
vector<int> ans;
void Solve(){
	cin>>n,m=0;
	for(int i=1;i<=n;i++)cin>>a[i],nxt[i]=i%n+1,lst[i]=(i-2+n)%n+1;
	queue<int> q;
	for(int i=2;i<=n;i++)if(__gcd(a[i],a[i-1])==1){q.push(i);inq[i]=1;i++;}
	if(!(q.size()&&q.back()==n)&&__gcd(a[n],a[1])==1)q.push(1),inq[1]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(del[x]||__gcd(a[lst[x]],a[x])!=1)continue;
		del[x]=1,lst[nxt[x]]=lst[x],nxt[lst[x]]=nxt[x];
		ans.push_back(x);
		if(__gcd(a[lst[x]],a[nxt[x]])==1&&!inq[lst[x]])q.push(nxt[x]),inq[nxt[x]]=1;
	}
	cout<<ans.size()<<' ';
	for(int i:ans)cout<<i<<' ';
	puts("");
	ans.clear();
	for(int i=1;i<=n;i++)a[i]=nxt[i]=lst[i]=del[i]=inq[i]=0;
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}