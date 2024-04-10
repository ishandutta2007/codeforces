#include<bits/stdc++.h>
#define maxn 210200
#define F first
#define S second

using namespace std;
typedef pair<int,int> pi;
pi a[maxn];
int n,k,d[maxn];

int main(){
	cin >> n;
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		d[u]++; d[v]++;
	}
	for (int i=0;i<n;i++){
		a[i].F=d[i+1]; a[i].S=i+1;
	}
	sort(a,a+n);
	if (n==2){
		cout << "Yes" << endl;
		cout << 1 << endl << 1 << ' ' << 2 << endl;
		return 0;
	}
	if (a[n-2].F>2){
		cout << "No" << endl;
		return 0;
	}
	//for (int i=0;i<n;i++) cout << a[i].F << endl;
	k=0; while (a[k].F==1) k++;
	cout << "Yes" << endl;
	cout << k << endl;
	for (int i=0;i<k;i++) cout << a[n-1].S << ' ' << a[i].S << endl;
	return 0;
}