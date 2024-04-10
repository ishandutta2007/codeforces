#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
typedef long long ll;
const int maxn=5e5+20;
const int M=998244353;
int cnt[maxn],a[maxn],_,n,l,r,ans,t1,t2;
int main(){
	scanf("%d",&_);
	while (_--){
		scanf("%d%d%d",&n,&l,&r);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		if (l>r){
			swap(l,r);
			reverse(a+1,a+n+1);
		}
		ans=(r-l)/2; t1=0; t2=0;
        for (int i=1;i<=n;i++) cnt[i]=0;
        for (int i=l+1;i<=n;i++) cnt[a[i]]++;
        for (int i=1;i<=l;i++) if (cnt[a[i]]) cnt[a[i]]--; else t1++;
        for (int i=1;i<=n;i++) if (cnt[i]&1) t2++;
        ans+=max(t1,(t1+t2)/2);
        printf("%d\n",ans);
	}
	return 0;
}