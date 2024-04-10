#include<iostream>
#include<algorithm>
using namespace std;
#define fi first
#define se second
int n;
pair<int,int>a[100001];
bool used[100001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	int ptr=1;
	int ans=0;
	for(int i=1; i<=n ;i++){
		while(ptr<=n && a[ptr].fi<=a[i].fi) ptr++;
		if(ptr<=n){
			used[ptr]=true;
			ptr++;
			ans++;
		}
	}
	cout << ans << endl;
}