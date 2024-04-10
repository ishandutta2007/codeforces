#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
void sol(){int n,a[N];
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-(a+1);
	vector<int>s1,s2;int an1=0,an2=0;
	dep(i,n,1){bool fl=0;
		for(auto &j:s1)if(!(j%a[i])){fl=1;break;}
		if(fl)continue;
		s1.pb(a[i]);an1+=a[i];
		if(s1.size()>2)break;
	}
	dep(i,n-1,1){bool fl=0;
		for(auto &j:s2)if(!(j%a[i])){fl=1;break;}
		if(fl)continue;
		s2.pb(a[i]);an2+=a[i];
		if(s2.size()>2)break;
	}
	printf("%d\n",max(an1,an2));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}