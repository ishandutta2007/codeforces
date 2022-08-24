#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	long long x;
	cin >> x;
	pair<long long,long long>a[x+1];
	for(long long i=1; i<=x ;i++){
		cin >> a[i].first >> a[i].second;
	}
	sort(a+1,a+x+1);
	long long cnt=1;
	long long as=0,bs=0;
	a[0]=make_pair(-2e9,-2e9);
	for(long long i=1; i<=x ;i++){
		if(a[i].first==a[i-1].first){
			cnt++;
		}
		else{
			as+=cnt*(cnt-1)/2;
			cnt=1;
		}
	}
	as+=cnt*(cnt-1)/2;
	for(long long i=1; i<=x ;i++){
		swap(a[i].first,a[i].second);
	}
	cnt=1;
	long long anc=1,minus=0;
	sort(a+1,a+x+1);
	for(long long i=1; i<=x ;i++){
		if(a[i].first==a[i-1].first && a[i].second!=a[i-1].second){
			cnt++;
			minus+=anc*(anc-1)/2;
			anc=1;
		}
		else if(a[i].first==a[i-1].first){
			cnt++;
			anc++;
		}
		else{
			minus+=anc*(anc-1)/2;
			bs+=cnt*(cnt-1)/2-minus;
			cnt=1;
			anc=1;
			minus=0;
		}
	}
	minus+=anc*(anc-1)/2;
	bs+=cnt*(cnt-1)/2-minus;
	cout << as+bs << endl;
}