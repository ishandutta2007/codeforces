#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
long long  cntn[128],cntm[128];
int  main(){
	ios::sync_with_stdio(false);
	long long  n,m;
	cin >> n >> m;
	long long  nl=0,ml=0,n2=max(1LL,n-1),m2=max(1LL,m-1);
	while(n2>0){
		nl++;n2/=7;
	}
	while(m2>0){
		ml++;m2/=7;
	}
	vector<long long >v;
	for(long long  i=0; i<128 ;i++){
		v.clear();
		for(long long  j=0; j<7 ;j++){
			if(i&(1<<j)){
				v.push_back(j);
			}
		}
		if(v.size()==nl){
			do{
				long long res=0;
				for(long long  i=0; i<v.size() ;i++){
					res=res*7+v[i];
				}
				if(res>=n) break;
				cntn[i]++;
			}while(next_permutation(v.begin(),v.end()));
		}
	}
	for(long long  i=0; i<128 ;i++){
		v.clear();
		for(long long  j=0; j<7 ;j++){
			if(i&(1<<j)){
				v.push_back(j);
			}
		}
		if(v.size()==ml){
			do{
				long long res=0;
				for(long long  i=0; i<v.size() ;i++){
					res=res*7+v[i];
				}
				if(res>=m) break;
				cntm[i]++;
			}while(next_permutation(v.begin(),v.end()));
		}
	}
	long long ans=0;
	for(long long  i=0; i<128 ;i++){
		for(long long  j=0; j<128 ;j++){
			if((i&j)==0){
				ans+=cntn[i]*cntm[j];
			}
		}
	}
	cout << ans << endl;
}