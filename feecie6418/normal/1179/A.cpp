#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[100005],mx=0,ans[300005][2];
deque<int> q;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]),q.push_back(a[i]);
	int cnt=0;
	do {
		++cnt;
		int x=q.front();
		q.pop_front();
		int y=q.front();
		q.pop_front();
		ans[cnt][0]=x,ans[cnt][1]=y;
		int p=x;
		if(x<y)swap(x,y);
		if(p==mx){
			q.push_front(y),q.push_front(x);
			break;
		}
		q.push_front(x),q.push_back(y);
	} while(1);
	while(m--){
		ll o;
		cin>>o;
		if(o<=cnt)printf("%d %d\n",ans[o][0],ans[o][1]);
		else printf("%d %d\n",mx,q[(o-cnt)%(n-1)+1]);
	}
}