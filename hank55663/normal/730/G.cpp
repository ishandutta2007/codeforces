#include<bits/stdc++.h>
using namespace std;
struct car{
	int s,t,ans,i;
};
int main() {
	int n;
	scanf("%d",&n);
	car a[205];
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].s,&a[i].t);
		a[i].i=i;
	}
	set<pair<int,int> > s;
	for(int i=0;i<n;i++){
		int ok=1;
		int dd=1,ans=0;
		for(set<pair<int,int> > ::iterator it=s.begin();it!=s.end();it++){
			if(ans==0&&it->first-dd>=a[i].t)
			ans=dd;
			if(it->first>=a[i].s&&it->first<=a[i].s+a[i].t-1)
			ok=0;
			if(it->second>=a[i].s&&it->second<=a[i].s+a[i].t-1)
			ok=0;
			if(it->first<=a[i].s&&a[i].s<=it->second)
			ok=0;
			dd=it->second+1;
		}
		if(ans==0)
		ans=dd;
		if(ok){
			a[i].ans=a[i].s;
		}
		else
		a[i].ans=ans;
		s.insert(make_pair(a[i].ans,a[i].ans+a[i].t-1));
	}
	for(int i=0;i<n;i++)
	printf("%d %d\n",a[i].ans,a[i].ans+a[i].t-1);
}