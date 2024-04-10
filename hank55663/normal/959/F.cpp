#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
typedef complex<double> C;
int mod=1e9+7;
LL f_pow(LL a,LL b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int a[100005];
	for(int i = 0;i<n;i++)
		scanf("%d",&a[i]);
	pair<pii,int> p[100005];
	for(int i = 0;i<q;i++){
		int l,x;
		scanf("%d %d",&l,&x);
		p[i]=mp(mp(l,x),i);
	}
	sort(p,p+q);
	vector<int> v;
	int now=0;
	int ans[100005];
	for(int i = 0;i<q;i++){
		while(now<p[i].x.x){
			int x=a[now];
			for(auto &it:v){
				x=min(x^it,x);
				if(x>it){
					swap(x,it);
				}
			}
			if(x!=0){
				v.pb(x);
			}
			now++;
		}
		int qu=p[i].x.y;
		for(auto it:v){
			qu=min(qu^it,qu);
		}
		if(qu==0){
			ans[p[i].y]=f_pow(2,now-v.size());
			//printf("%d %d %d %d\n",now,v.size(),p[i].y,p[i].x.x);
		}
		else{
			ans[p[i].y]=0;
		}
	}
	for(int i=  0;i<q;i++)
		printf("%d\n",ans[i]);
}