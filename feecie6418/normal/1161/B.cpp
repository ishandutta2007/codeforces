#include<bits/stdc++.h>
using namespace std;
int n,m,st[400005],l[400005],pre[400005],tmp[400005];
pair<int,int> p[400005];
map<int,int> mp[400005];
int Calc(int x,int y){
	swap(x,y);
	if(y>x)return y-x;
	return y-x+n;
}
int main() {
	cin>>n>>m;
	for(int i=1,x,y;i<=m;i++){
		cin>>x>>y;
		p[i]=make_pair(x,y);
		p[i+m]=make_pair(y,x);
	}
	m*=2;
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++){
		int x=p[i].first,y=p[i].second;
		st[i]=x;
		if(y>x)l[i]=y-x;
		else l[i]=y+n-x;
		mp[st[i]][l[i]]=1;
		pre[i]=tmp[l[i]],tmp[l[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(!pre[i])pre[i]=tmp[l[i]];
//		vec[l[i]].push_back(Calc(st[i],st[pre[i]]));
//		vec2[l[i]].push_back(st[i]);
		if(pre[i]==i)return puts("NO"),0;
	}
	for(int i=1;i<n;i++){
		if(n%i)continue;
		bool flag=1;
		for(int j=1;j<=m;j++){
			if(!mp[(i+st[j]-1)%n+1][l[j]]){
				flag=0;
				break;
			}
		}
		if(flag)return puts("Yes"),0;
	}
	puts("No");
	return 0;
}