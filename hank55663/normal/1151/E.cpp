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
int main()
{
	int n;
	scanf("%d",&n);
	LL a[100005];
	set<int> s;
	s.insert(0);
	s.insert(n+1);
	for(int i = 0;i<n;i++){
		scanf("%lld",&a[i]);
		s.insert(a[i]);
	}
	LL ans=a[0]*(n-a[0]+1);
	for(int i = 1;i<n;i++){
		if(a[i-1]<a[i]){
			ans+=(a[i]-a[i-1])*(n-a[i]+1);
		}
		else if(a[i-1]>a[i]){
			ans+=(a[i-1]-a[i])*a[i];
		}
	}
	printf("%lld\n",ans);
	/*
	vector<int> v;
	v.pb(a[0]);
	for(int i = 1;i<n;i++){
		if(a[i]!=v.back()){
			v.pb(a[i]);
		}
	}
	n=v.size();
	LL ans=0;
	for(int i = 1;i<n;i++){
		LL Max=max(v[i-1],v[i+1]);
		LL Min=min(v[i-1],v[i+1]);
		if(v[i-1]>v[i]&&v[i+1]>v[i]){
			ans+=(n+1-Max)*(Min-v[i]);
		}
		if(v[i-1]<v[i]&&v[i+1]<v[i]){
			ans+=(v[i]-Max)*(Min);
		}
	}
	//printf("%lld\n",ans);
	int last=0;
	ans+=(LL)n*(n-1)/2+n;
	for(auto it:s){
		int num=it-last-1;
		//printf("%lld\n",num);
		ans-=(LL)num*(num)/2;
		last=it;
	}
	printf("%lld\n",ans);*/
}