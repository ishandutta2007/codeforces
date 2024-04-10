#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;
const int N=2e5+100;
int a[N];
multiset<ll> S;
multiset<ll>::iterator iter;

bool cmp(int n1,int n2) {return (n1<n2);}

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		
		ll Sum=0;
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),Sum+=a[i];
		
		sort(a+1,a+n+1,cmp);
		
		S.clear();
		
		S.insert(Sum);
		
		bool pd=true;int id=n;
		while(1){
			iter=S.end();iter--;
			ll t=(*iter);
			S.erase(iter);
			if(t>a[id]){
				ll t1=t/2,t2=(t+1)/2;
				S.insert(t1);S.insert(t2);
			}
			else if(t==a[id]){
				id--;
				if(id==0) break;
			}
			else {pd=false;break;}
		}
		
		if(!pd) printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}