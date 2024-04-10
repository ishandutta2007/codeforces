#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=5e5+10;
const int mo=1e9+7;
const ll inf=1e9;
int fi[30],f[N],s[N];
vector<int>p[N];
void bd(int x){
	int sz=p[x].size();s[x]=1;
	if(x>1){
		rep(i,0,sz-1)if(p[x][i]==f[x]){
			swap(p[x][i],p[x][sz-1]);break;
		}
		p[x].pop_back();
	}
	for(auto&i:p[x]){
		f[i]=x;bd(i);s[x]+=s[i];
	}
}
bool ck(int x,int m){
	if(m<=3)return 1;
	queue<int>q;q.push(x);
	vector<int>res;
	while(!q.empty()){
		int y=q.front();q.pop();
		if(s[y]==fi[m-2]||s[y]==fi[m-1])res.push_back(y);
		for(auto&i:p[y])if(f[i]==y)q.push(i);
	}
	for(auto&y:res){
		int fa=f[y];bool ok;f[y]=0;
		for(int i=fa;i;i=f[i])s[i]-=s[y];
		if(s[y]==fi[m-2])ok=ck(y,m-2)&&ck(x,m-1);
		else ok=ck(x,m-2)&&ck(y,m-1);
		for(int i=fa;i;i=f[i])s[i]+=s[y];
		f[y]=fa;
		if(ok)return 1;
	}
	return 0;
}
int main(){int n,m;
	scanf("%d",&n);
	fi[0]=fi[1]=m=1;
	while(fi[m]<n){
		++m;fi[m]=fi[m-2]+fi[m-1];
	}
	if(fi[m]!=n){
		printf("NO\n");return 0;
	}
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	bd(1);
	printf("%s\n",ck(1,m)?"YES":"NO");
}