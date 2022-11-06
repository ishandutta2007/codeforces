#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e6+10;
const int mo=1e9+7;
int r[N],p[N];bool v[N];
int main(){int tot=0;
	rep(i,2,2750131){
		if(!v[i])p[++tot]=i;
		rep(j,1,tot){
			if(i*p[j]>2750131)break;
			r[i*p[j]]=i;
			v[i*p[j]]=1;
			if(!(i%p[j]))break;
		}
	}int n;
	multiset<int>s1,s2;
	scanf("%d",&n);
	rep(i,1,n*2){int x;
		scanf("%d",&x);
		if(!v[x])s1.insert(x);
		else s2.insert(x);
	}
	while(!s2.empty()){
		int x=*(--s2.end());s2.erase(--s2.end());
		printf("%d ",x);
		if(v[r[x]])s2.erase(s2.find(r[x]));else s1.erase(s1.find(r[x]));
	}
	while(!s1.empty()){
		int x=*s1.begin();s1.erase(s1.begin());
		printf("%d ",x);s1.erase(s1.find(p[x]));
	}
}