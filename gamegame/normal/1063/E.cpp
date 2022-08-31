#include<iostream>
#include<stack>
using namespace std;
int n;
int a[1001];
char out[1001];
void put(){
	for(int i=1; i<=n ;i++) cout << out[i];
	cout << '\n';
}
bool per=true;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		int x;
		cin >> x;
		a[x]=i;
		if(i!=x) per=false;
	}
	if(per){
		int cur=0;
		cout << n << endl;
		while(cur<n){
			cur++;
			for(int i=1; i<=n ;i++) out[i]='.';
			put();
		}
		return 0;
	}
	cout << n-1 << endl;
	a[n]=0;
	int cur=0;
	for(int i=1; i<=n ;i++){
		cur++;
		for(int i=1; i<=n ;i++) out[i]='.';
		int l=1;
		while(a[l]==l) l++;
		int r=n;
		while(a[r]==r) r--;
		if(i%2==1){
			if(l!=r){
				out[l]=out[a[l]]=out[r]='\\';
				a[r]=a[a[l]];
				a[a[l]]=a[l];
				a[l]=0;
			}
			put();
		}
		else{
			if(l!=r){
				out[r]=out[a[r]]=out[l]='/';
				a[l]=a[a[r]];
				a[a[r]]=a[r];
				a[r]=0;
			}
			put();
		}
	}
}