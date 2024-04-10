#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[105],cnt[105];
bool dfs(int lst){
	for(int i=1;i<=n;i++){
		if(i==lst||!a[i])continue;
		a[i]--;
		int o=dfs(i);
		a[i]++;
		if(!o)return 1;
	}
	return 0;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		int s=0;
		for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++,s+=a[i];
		sort(a+1,a+n+1);
		if(s-a[n]<a[n])puts("T");
		else puts(s%2?"T":"HL");
	}
    return 0;
}