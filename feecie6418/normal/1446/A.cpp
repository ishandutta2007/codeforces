#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll w;
struct T{
	int id;
	ll x;
}a[200005];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>w;
		for(int i=1;i<=n;i++)cin>>a[i].x,a[i].id=i;
		sort(a+1,a+n+1,[](T i,T j){return i.x<j.x;});
		ll s=0;
		int L=0,R=0;
		for(int i=1,j=0;i<=n;i++){
			while(s<(w+1)/2&&j<n)s+=a[++j].x;
			if(s>=(w+1)/2&&s<=w){
				L=i,R=j;
				break;
			}
			s-=a[i].x;
		}
		if(!L&&!R)puts("-1");
		else {
			cout<<R-L+1<<endl;
			for(int i=L;i<=R;i++)cout<<a[i].id<<' ';
			cout<<endl;
		}
	}
    return 0;
}