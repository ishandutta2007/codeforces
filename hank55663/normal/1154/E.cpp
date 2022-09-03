#include<bits/stdc++.h>
#define pdd pair<long double,long double>
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define LL long long
#define y second
#define x first
#define pi acos(-1)
#define pi2 (2*pi)
#define MEMS(x) memset(x,-1,sizeof(x))
#define ld long double
using namespace std;
int main() {
	set<int> s;
	set<pii> num;
	int n,k;
	scanf("%d %d",&n,&k);
	int a[200005];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		num.insert(mp(a[i],i));
		s.insert(i);
	}
	vector<int> fi,se;
	int cnt=1;
	while(s.size()){
		pii p=*num.rbegin();
		auto it=s.find(p.y);
		vector<int> temp;
		for(int i = 0;i<=k;i++){
			temp.pb(*it);
		//	printf("%d %d\n",*it,cnt);
			if(it==s.begin())break;
			it--;
		}
		it=s.find(p.y);
		for(int i = 0;i<k;i++){
			it++;
			if(it==s.end())break;
			temp.pb(*it);
		//	printf("%d %d\n",*it,cnt);
		}
		if(cnt&1){
			for(auto it:temp)
			fi.pb(it);
		}
		else{
			for(auto it:temp)
			se.pb(it);
		}
		for(auto it:temp){
			s.erase(it);
			num.erase(mp(a[it],it));
		}
		cnt++;
	}
	int ans[200005];
	for(auto it:fi)
	ans[it]=1;
	for(auto it:se)
	ans[it]=2;
	for(int i = 0;i<n;i++)
	printf("%d",ans[i]);
}