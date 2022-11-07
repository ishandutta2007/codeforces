#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int mo=1e9+7;
struct pr{int x;string s;};
vector<pr>res;
int main(){int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int tot=(n-1)*m*2+(m-1)*n*2;
	if(k>tot){
		printf("NO\n");return 0;
	}
	if(m-1)res.push_back({m-1,"R"});
	rep(i,2,n){
		res.push_back({1,"D"});
		if(m-1)res.push_back({m-1,string(i&1?"R":"L")+"UD"});
	}
	dep(i,n,1){
		if(i<n)res.push_back({1,"U"});
		if(m-1)res.push_back({m-1,i&1?"L":"R"});
	}
	while(tot>k){
		pr s=res.back();res.pop_back();
		tot-=s.x*s.s.size();
		if(tot<k){
			int t=(k-tot)/s.s.size();
			if(t)res.push_back({t,s.s});
			tot+=t*s.s.size();
			if(tot<k){
				string ss;
				rep(i,1,k-tot)ss+=s.s[i-1];
				res.push_back({1,ss});
			}
		}
	}
	printf("YES\n%d\n",(int)res.size());
	for(auto&i:res)printf("%d %s\n",i.x,i.s.c_str());
}