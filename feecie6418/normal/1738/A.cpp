#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,m1,m2,a[100005],b[100005],t1[100005],t2[100005];
void Solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	ll sum=0;
	m1=m2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0)t1[++m1]=b[i];
		else t2[++m2]=b[i];
	}
	sort(t1+1,t1+m1+1);
	sort(t2+1,t2+m2+1);
	if(m1!=m2){
		for(int i=1;i<=m1;i++){
			if(i<=m1-min(m1,m2))sum+=t1[i];
			else sum+=2*t1[i];
		}
		for(int i=1;i<=m2;i++){
			if(i<=m2-min(m1,m2))sum+=t2[i];
			else sum+=2*t2[i];
		}
	}
	else {
		for(int i=1;i<=n;i++)sum+=b[i]*2;
		sum-=*min_element(b+1,b+n+1);
	}
	cout<<sum<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}