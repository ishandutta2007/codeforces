#include<bits/stdc++.h>
using namespace std;
int n,ans;
struct t{
	int s,f;
}dan[500005];
bool cmp(t a,t b){
	return a.f<b.f;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>dan[i].s>>dan[i].f;
	}
	sort(dan+1,dan+1+n,cmp);
	int now=-1;
	for(int i=1;i<=n;i++){
		if(dan[i].s>=now){
			ans++;
			now=dan[i].f+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}