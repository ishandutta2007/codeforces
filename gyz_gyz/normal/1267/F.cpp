#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define sc second
using namespace std;
const int N=2e5+10;
char s[N];int a[N],b[N],v[N],res[N];
vector<pair<int,int>>ans;
set<int>p[N];
void lk(int x,int y){
	p[x].insert(y);p[y].insert(x);ans.push_back({x,y});
}
int main(){int n,m,n1,m1;
	scanf("%d%d%d%d",&n,&m,&n1,&m1);
	rep(i,1,n1){
		scanf("%d",&a[i]);
		++v[a[i]];
	}
	rep(i,1,m1){
		scanf("%d",&b[i]);
		++v[b[i]];
	}
	if(n1>=m||m1>=n){
		printf("No\n");return 0;
	}
	while(n1<m-1){
		a[n1+1]=a[n1];++v[a[n1]];++n1;
	}
	while(m1<n-1){
		b[m1+1]=n+m;++v[n+m];++m1;
	}
	int t1=1,t2=1;
	set<int>ss;
	rep(i,1,n+m)if(!v[i])ss.insert(i);
	int ct=0;
	while(!ss.empty()&&ct<n+m-2){++ct;
		int x=*ss.begin();ss.erase(ss.begin());
		if(x<=n){
			lk(x,b[t2]);
			if(!--v[b[t2]])ss.insert(b[t2]);
			++t2;
		}else{
			lk(x,a[t1]);
			if(!--v[a[t1]])ss.insert(a[t1]);
			++t1;
		}
	}lk(a[n1],n+m);
	set<int>s;ct=0;
	rep(i,1,n+m)if((int)p[i].size()==1)s.insert(i);
	while(!s.empty()&&ct<=n+m-2){
		int x=*s.begin();s.erase(s.begin());
		res[++ct]=*p[x].begin();
		p[res[ct]].erase(x);
		if((int)p[res[ct]].size()==1)s.insert(res[ct]);
	}
	int x=1;
	rep(i,1,n1){
		while(x<=n+m-2&&res[x]!=a[i])++x;
		if(x>n+m-2){
			printf("No\n");return 0;
		}++x;
	}
	x=1;
	rep(i,1,m1){
		while(x<=n+m-2&&res[x]!=b[i])++x;
		if(x>n+m-2){
			printf("No\n");return 0;
		}++x;
	}
	printf("Yes\n");
	rep(i,0,n+m-2)printf("%d %d\n",ans[i].first,ans[i].second);
}