#include<bits/stdc++.h>
using namespace std;
int n,cnt[10005];
void Solve(){
	memset(cnt,0,sizeof(cnt));
	cin>>n;
	for(int i=1;i<=n;i++){
		char a[10];
		scanf("%s",a);
		int x=a[0]-'a',y=a[1]-'a';
		cnt[x*26+y]++;
	}
	long long ans=0;
	for(int i=0;i<26*26;i++){
		for(int j=i;j<26*26;j++){
			int x1=i/26,y1=i%26;
			int x2=j/26,y2=j%26;
			if((x1==x2)+(y1==y2)==1){
				ans+=1ll*cnt[i]*cnt[j];
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve();
}