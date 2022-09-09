#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int gcd(int a,int b){ return b? gcd(b,a%b): a;}

struct Node
{
	int id,val;
	Node *pre, *nxt;
	Node(void){}
	Node(int _id,int _val): id(_id), val(_val) {}
}b[MAXN];

inline void del(Node *p)
{
	p -> nxt -> pre = p -> pre;
	p -> pre -> nxt = p -> nxt;
}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		b[i] = Node(i, a[i]);
		b[i].nxt = i == n? &b[1]: &b[i+1];
		b[i].pre = i == 1? &b[n]: &b[i-1];
	}
	
	queue<Node*> q;
	static bool vis[MAXN];
	memset(vis,0,n+1);
	for(int i=2; i<=n; ++i)
		if(!vis[i-1] && gcd(a[i], a[i-1]) == 1)
			vis[i] = 1, q.push(&b[i]);
	if(!vis[n] && gcd(a[1], a[n]) == 1)
		vis[1] = 1, q.push(&b[1]);
	
	vector<int> ans;
	while(q.size())
	{
		Node *p = q.front(); q.pop();
		ans.push_back(p -> id);
		if(p -> nxt -> id == p -> id) break;
		if(!vis[p -> pre -> id] && gcd(p -> nxt -> val, p -> pre -> val) == 1)
			q.push(p -> nxt), vis[p -> nxt -> id] = 1;
		del(p);
	}
	
	printf("%d ",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}