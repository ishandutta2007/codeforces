#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int n;
string s;
int a[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	cin >> s;
	s='?'+s;
	int x=0,y=0;
	int cur=n,ans=0;
	for(int i=1; i<=n ;i++){
		if(s[i]=='0'){
			cur++;
		}
		else{
			cur--;
		}
		if(cur==n) ans=max(ans,i);
		if(a[cur]!=0) ans=max(i-a[cur],ans);
		else a[cur]=i;
	}
	cout << ans << endl;
}