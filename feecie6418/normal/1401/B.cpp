
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int T;
	cin>>T;
	while(T--){
		int cnt[4],cnt2[4];
		for(int i=0;i<=2;i++)cin>>cnt[i];
		for(int i=0;i<=2;i++)cin>>cnt2[i];
		cout<<2*min(cnt[2],cnt2[1])-2*max(0,cnt2[2]-max(cnt[2]-cnt2[1],0)-cnt[0])<<endl;
	}
	return 0;
}