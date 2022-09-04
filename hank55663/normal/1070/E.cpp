#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll t,a[200005];
int main(){
	int nn;
	scanf("%d",&nn);
	while(nn--){
		set<int> st;
		scanf("%d%d%lld",&n,&m,&t);
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			st.insert(a[i]);
		}
		ll p,q,mid;
		ll ansV,ansD;
		ansV=-1000;
		p = 0;
		mid = q = 200005;
		while(p<=q){
			mid = (p+q)/2;
			int cnt = 0;
			ll spend = 0;
			ll last=0;
			int i;
			for(i=0;i<n;i++){
				if(a[i]<=mid){
					if(spend + a[i] > t){
						break;
					}
					cnt++;
					spend+=a[i];
					last+=a[i];
					if(cnt % m == 0){
					    spend+=last;
					    last = 0;
					}
	//				cout<<"i = "<<i<<' '<<spend<<endl;
				}
			}
	//		cout<<"mid = "<<mid<<' '<<cnt<<endl;
			if(cnt > ansV){
				ansV = cnt;
				ansD = mid;
			}
			if(i==n){
				p = mid+1;
			}
			else{
				q = mid-1;
			}
		}
		set<int> :: iterator it;
		it = st.find(ansD);
		for(int i=0;i<100;i++){
			it++;
			if(it == st.end()) break;
			
			int mid = *it;
			
			int cnt = 0;
			ll spend = 0;
			ll last=0;
			
			for(int i=0;i<n;i++){
				if(a[i]<=mid){
					if(spend + a[i] > t){
						break;
					}
					cnt++;
					spend+=a[i];
					last+=a[i];
					if(cnt % m == 0){
					    spend+=last;
					    last = 0;
					}
	//				cout<<"i = "<<i<<' '<<spend<<endl;
				}
			}
			
			if(cnt > ansV){
				ansV = cnt;
				ansD = mid;
			}
			
		}
		for(int i=0;i<100;i++){
			if(it == st.begin()) break;
			it--;
			
			int mid = *it;
			
			int cnt = 0;
			ll spend = 0;
			ll last=0;
			
			for(int i=0;i<n;i++){
				if(a[i]<=mid){
					if(spend + a[i] > t){
						break;
					}
					cnt++;
					spend+=a[i];
					last+=a[i];
					if(cnt % m == 0){
					    spend+=last;
					    last = 0;
					}
	//				cout<<"i = "<<i<<' '<<spend<<endl;
				}
			}
			
			if(cnt > ansV){
				ansV = cnt;
				ansD = mid;
			}
			
		}
		cout<<ansV<<' '<<min(ansD,t)<<endl;
		
	}
	return 0;
}