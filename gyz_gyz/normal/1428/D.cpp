#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+10;
const int mo=998244353;
const ll inf=1e18;
vector<pii>ans;int a[N];
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	queue<int>q;
	int h=0,ls=0;
	rep(i,1,n)if(a[i]){
		if(a[i]==1&&!q.empty()){
			ans.push_back({q.front(),i});
			q.pop();
		}else{
			if(ls==3)ans.push_back({h,i});
			ans.push_back({++h,i});
			ls=a[i];
			if(a[i]==2)q.push(h);
		}
	}
	if(!q.empty()||ls>2){
		printf("-1\n");return 0;
	}
	printf("%d\n",(int)ans.size());
	for(auto&i:ans)printf("%d %d\n",i.fr,i.sc);
}