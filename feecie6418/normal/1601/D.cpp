#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m,ans=0;
struct T{
	int s,a;
}a[500005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].s,&a[i].a);
	sort(a+1,a+n+1,[](T x,T y){return max(x.s,x.a)!=max(y.s,y.a)?max(x.s,x.a)<max(y.s,y.a):x.s<y.s;});
	for(int i=1;i<=n;i++){
		if(a[i].s>=m)ans++,m=max(m,a[i].a);
	}
	cout<<ans;
}