#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int d[1005],n;
vector<int> v,v2;
int main() {
	cin>>n;
	for(int i=1,x,y;i<n;i++)cin>>x>>y,d[x]++,d[y]++;
	for(int i=1;i<=n;i++)if(d[i]==1)v.push_back(i);
	while(v.size()>1){
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end())-v.begin());
		random_shuffle(v.begin(),v.end());
		v2.clear();
		for(int i=0;i<v.size();i+=2){
			if(i+1==v.size())v2.push_back(v[i]);
			else {
				int o=v[i],oo=v[i+1];
				cout<<"? "<<o<<' '<<oo<<endl;
				cin>>o;
				if(d[o]==1){
					cout<<"! "<<o<<endl;
					return 0;
				}
				v2.push_back(o);
			}
		}
		v=v2;
	}
	cout<<"! "<<v[0]<<endl;
}