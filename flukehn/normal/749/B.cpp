#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(12);
	//int T;cin>>T;
	int a,b,c,d,e,f;
	while(cin>>a>>b>>c>>d>>e>>f){
		set<pair<int,int> >S;
		S.insert(make_pair(c+e-a,d+f-b));
		S.insert(make_pair(a+c-e,b+d-f));
		S.insert(make_pair(a+e-c,b+f-d));
		cout<<S.size()<<"\n";
		for(auto w:S)cout<<w.first<<" "<<w.second<<"\n";
	}
}