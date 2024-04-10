#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m,k;
int a[100001],b[100001];
string s[5]={"Tetrahedron","Cube","Octahedron" ,"Dodecahedron","Icosahedron"};
int t[5]={4,6,8,12,20};
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	string ss;
	long long ans=0;
	for(int i=1; i<=n ;i++){
		cin >> ss;
		for(int j=0; j<5 ;j++){
			if(ss==s[j]) ans+=t[j];
		}
	}
	cout << ans << endl;
}