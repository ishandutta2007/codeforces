#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
int a[N],v[33];
struct po{
	int x,y;
	friend bool operator<(const po&a,const po&b){
		return a.x==b.x?a.y<b.y:a.x<b.x;
	}
};
int main(){int n;
	scanf("%d",&n);
	set<po>s;
	rep(i,1,n){po x;
		scanf("%d%d",&x.x,&x.y);
		s.insert(x);
	}
	po p1=*s.begin(),p2=*s.rbegin();
	int x=p1.x+p2.x,y=p1.y+p2.y;
	for(auto&i:s){
		po t={x-i.x,y-i.y};
		if(!s.count(t)){
			printf("NO\n");return 0;
		}
	}
	printf("YES\n");
}