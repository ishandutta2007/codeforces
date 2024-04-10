#include <bits/stdc++.h>
using namespace std;

int n,m;

bool check(int t){
	int x=n,y=m;
	for(int i=t;i>=1;i--)
		if(x>y){
			if(x<i) return 0;
			x-=i;
		}else{
			if(y<i) return 0;
			y-=i;
		}
	return 1;
}

void gao(int t){
	static vector<int> ans1,ans2;
	int x=n,y=m;
	for(int i=t;i>=1;i--)
		if(x>y){
			x-=i;
			ans1.push_back(i);
		}else{
			y-=i;
			ans2.push_back(i);
		}
	printf("%d\n",ans1.size());
	for(int i=0;i<ans1.size();i++) printf("%d ",ans1[i]);
	puts("");
	printf("%d\n",ans2.size());
	for(int i=0;i<ans2.size();i++) printf("%d ",ans2[i]);
	puts("");
}

int main(){
	scanf("%d%d",&n,&m);
	int l=0,r=10000000;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	gao(l);
}