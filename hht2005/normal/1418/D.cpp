#include<bits/stdc++.h>
using namespace std;
set<int>s;
multiset<int>d;
set<int>::iterator it;
int main() {
	int n,q,opt,x;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d",&x);
		s.insert(x);
	}
	int las=0;
	for(int i:s) {
		if(las)d.insert(i-las);
		las=i;
	}
	if(s.size()>2)printf("%d\n",*s.rbegin()-*s.begin()-*d.rbegin());
	else puts("0");
	while(q--) {
		scanf("%d%d",&opt,&x);
		if(opt) {
			it=s.lower_bound(x);
			if(s.size()) {
				if(it==s.end())d.insert(x-*--it);
				else if(it==s.begin())d.insert(*it-x);
				else {
					int b=*it,a=*--it;
					d.erase(d.find(b-a));
					d.insert(x-a);
					d.insert(b-x);
				}
			}//sdf
			s.insert(x);
		} else {
			it=s.lower_bound(x);
			if(s.size()>1) {
				if(it==--s.end())d.erase(d.find(x-*--it));
				else if(it==s.begin())d.erase(d.find(*++it-x));
				else {
					int b=*++it,a=*--(--it);
					d.erase(d.find(x-a));
					d.erase(d.find(b-x));
					d.insert(b-a);
				}
			}
			s.erase(x);
		}
		if(s.size()>2)printf("%d\n",*s.rbegin()-*s.begin()-*d.rbegin());
		else puts("0");
	}
	return 0;
}