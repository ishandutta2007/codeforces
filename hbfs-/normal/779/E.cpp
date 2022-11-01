#include <bits/stdc++.h>
#define N 5050 
using namespace std;
map<string,int> mp;
struct query{int a,b,t,num;string f;} q[N];
int n,m;
void init() {
	cin>>n>>m;
	string s;
	for (int i=1;i<=n;i++) {
		cin>>s;
		mp[s]=i;
		cin>>s;cin>>s;
		if (s[0]>='0'&&s[0]<='9') q[i].f=s;
		else {
			if (s[0]!='?') q[i].a=mp[s];
			cin>>s;
			if (s[0]=='A') q[i].t=1;
			if (s[0]=='O') q[i].t=2;
			if (s[0]=='X') q[i].t=3;
			cin>>s;
			if (s[0]!='?') q[i].b=mp[s]; 
		}
	}
}
int find(int x,int f) {
	int rt=0; q[0].num = f;
	for (int i=1;i<=n;i++) {
		if (q[i].t==0) q[i].num=q[i].f[x]-'0';
		int p1=q[q[i].a].num,p2=q[q[i].b].num;
		if (q[i].t==1) q[i].num=p1&p2;
		if (q[i].t==2) q[i].num=p1|p2;
		if (q[i].t==3) q[i].num=p1^p2;
		rt+=q[i].num;
	}
	return rt;
}
void solve() {
	string ans1="",ans2="";
	for (int i=0;i<m;i++) {
		int x0=find(i,0);
		int x1=find(i,1);
		x0<=x1 ? ans1=ans1+'0' : ans1=ans1+'1';
		x0>=x1 ? ans2=ans2+'0' : ans2=ans2+'1';
	}
	cout<<ans1<<"\n";
	cout<<ans2<<"\n";
}
int main() {
	init();
	solve();
}