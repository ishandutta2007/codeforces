#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1<<19];
int main(){
	int n;ll ans=0;multiset<int>s;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=n;i;--i){
		s.insert(a[i]);
		if((i&-i)==i){
			int x=*s.begin();s.erase(s.begin());
			if(x==-1)break;ans+=x;
		}
	}
	printf("%lld\n",ans);
}