#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax= 200*1000+1;
int n;
int a[nax];
multiset<int>S;

int main() {
	scanf("%d",&n);
	for(int i=0; i<n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n;i++) {
		int x;
		scanf("%d",&x);
		S.insert(x);
	}
	int e,tmp,pos1,pos2,pos3,ans=-1;
	for(int i=0; i<n;i++) {
		e = n-a[i];
		auto it1 = S.lower_bound(e);
		if(it1==S.end()) pos1=nax;
		else pos1=(a[i]+(*it1))%n;
		auto it2 = S.upper_bound(e);
		if(it2==S.end())pos2=nax;
		else pos2 = (a[i]+(*it2))%n;
		auto itmin = S.upper_bound(-1);
		if(itmin==S.end()) pos3=nax;
		else pos3 = (a[i]+(*itmin))%n;
		tmp=min({pos1,pos2,pos3});
		if(tmp==pos1) {
			ans=pos1;
			S.erase(it1);
		}
		else if(tmp==pos2) {
			ans=pos2;
			S.erase(it2);
		}
		else {
			ans=pos3;
			S.erase(itmin);
		}
		printf("%d ",ans);
	}
}