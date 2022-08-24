#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
int a[200001],b[200001];
char c[10]={'a','e','i','o','u','1','3','5','7','9'};
int main(){
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ans=0;
	for(int i=0; i<s.size() ;i++){
		int need=false;
		for(int j=0; j<10 ;j++){
			if(s[i]==c[j]) need=true;
		}
		ans+=need;
	}
	cout << ans << endl;
}