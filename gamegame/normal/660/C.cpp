#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	int a[n+1];
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(k==0){
		int cur=0,maxi=0;
		for(int i=1; i<=n ;i++){
			if(a[i]==1){
				cur++;
			}
			else{
				cur=0;
			}
			maxi=max(maxi,cur);
		}
		cout << maxi << endl;;
		for(int i=1; i<n ;i++){
			cout << a[i] << ' ';
		}
		cout << a[n] << endl;
		return 0;
	}
	int l=1,r=1,maxi,maxl=1,maxr=1;
	int sco=1,use=1-a[1];
	maxi=sco;
	while(r!=n){
		r++;
		if(a[r]==0){
			if(use!=k){
				use++;
				sco++;
				if(sco>maxi){
					maxi=sco;
					maxl=l;
					maxr=r;
				}
			}
			else{
				while(a[l]==1){
					sco--;
					l++;
				}
				if(l==r){
					int sco=1,use=1-a[l];
				}
				else{
					l++;
				}
			}
		}
		else{
			sco++;
			if(sco>maxi){
				maxi=sco;
				maxl=l;
				maxr=r;
			}
		}
	}
	cout << maxi << endl;
	for(int i=maxl; i<=maxr ;i++){
		a[i]=1;
	}
	for(int i=1; i<n ;i++){
		cout << a[i] << ' ';
	}
	cout << a[n] << endl;
}