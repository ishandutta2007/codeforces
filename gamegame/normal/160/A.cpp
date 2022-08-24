#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int i,int j){
	return i>j;
}
int main(){
	int x;
	cin >> x;
	int a[x];
	int sum=0;
	for(int i=0; i<x ;i++){
		cin >> a[i];
		sum+=a[i];
	}
	sort(a,a+x,cmp);
	int msum=0;
	for(int i=0; i<x ;i++){
		msum+=a[i];
		if(msum*2>sum){
			cout << i+1 << endl;
			return 0;
		}
	}
}