//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while(t--){
		int n,k,m;
		cin>>n>>k>>m;
/*		set<int> ss;
		for(int i=1;i<=n;i++){
			ss.insert(i);
		}*/
		vector<int> tt;
		for(int i=0;i<m;i++){
			cin>>it[i];

		//	ss.erase(i);
		}
		tt.pb(it[0]-1);
		for(int i=1;i<m;i++){
			tt.pb(it[i]-it[i-1]-1);
		}
		tt.pb(n-it[m-1]);

		/*for(auto j:tt){
			cout<<j<<",";
		}
		cout<<endl;*/
		if((n-m)%(k-1)!=0){
			cout<<"NO"<<endl;
			continue;
		}
		int st=0;
		llo co=0;
		for(auto j:tt){
			co+=j;
			if(co>=(k-1)/2){
				if((n-m-co)>=(k-1)/2){
					st=1;
				}
			}
		}
	/*	for(auto j:tt){
			if(j>(n-m)-(k-1)/2){
				st=0;
			}
		}*/
		if(st==0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	/*	int ind=0;
		for(int i=1;i<=n;i++){
			if(ss.find(i)!=ss.end()){

			}
		}*/


	//	cout<<"YES"<<endl;
	}



 
	return 0;
}